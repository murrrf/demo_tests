#include "tablewidget.h"

#include "recordeditor.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableView>
#include <QSqlTableModel>
#include <QModelIndex>
#include <QSqlRecord>
#include <QDateTime>
#include <QUuid>
#include <QMessageBox>
#include <QSqlError>
#include <QSortFilterProxyModel>
#include <QHeaderView>

TableWidget::TableWidget(QSqlDatabase db, QWidget *parent) :
    QWidget(parent)
{
    btnAdd = new QPushButton(tr("Add"));
    btnAdd->setEnabled(false);
    connect(btnAdd, SIGNAL(clicked()), this, SLOT(onAdd()));

    btnEdit = new QPushButton(tr("Edit"));
    btnEdit->setEnabled(false);
    connect(btnEdit, SIGNAL(clicked()), this, SLOT(onEdit()));

    btnDelete = new QPushButton(tr("Delete"));
    btnDelete->setEnabled(false);
    connect(btnDelete, SIGNAL(clicked()), this, SLOT(onDelete()));

    boxButtons = new QHBoxLayout();
    boxButtons->addStretch();
    boxButtons->addWidget(btnAdd);
    boxButtons->addWidget(btnEdit);
    boxButtons->addWidget(btnDelete);
    boxButtons->addStretch();


    mdlData = new QSqlTableModel(this, db);
    mdlData->setEditStrategy(QSqlTableModel::OnManualSubmit);

    mdlSortProxy = new QSortFilterProxyModel(this);
    mdlSortProxy->setSourceModel(mdlData);

    tblData = new QTableView();
    tblData->setModel(mdlSortProxy);
    tblData->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tblData->setSelectionBehavior(QAbstractItemView::SelectItems);
    tblData->setSelectionMode(QAbstractItemView::SingleSelection);
    tblData->setSortingEnabled(true);
    tblData->sortByColumn(colDate, Qt::AscendingOrder);
    tblData->horizontalHeader()->setHighlightSections(false);
    connect(tblData, SIGNAL(clicked(QModelIndex)), this, SLOT(onTableClicked(QModelIndex)));

    boxMain = new QVBoxLayout();
    boxMain->addLayout(boxButtons);
    boxMain->addWidget(tblData);
    this->setLayout(boxMain);

    currentRow = -1;
}

TableWidget::~TableWidget()
{
    delete tblData;
    delete btnAdd;
    delete btnEdit;
    delete btnDelete;
    delete boxButtons;
    delete boxMain;
}

void TableWidget::setTable(const QString &tableName)
{
    mdlData->setTable(tableName);
    mdlData->select();
    mdlData->setHeaderData(colID, Qt::Horizontal, tr("UUID"));
    mdlData->setHeaderData(colText, Qt::Horizontal, tr("Text"));
    mdlData->setHeaderData(colDate, Qt::Horizontal, tr("Date"));

    tblData->resizeColumnsToContents();

    btnAdd->setEnabled(true);
}

void TableWidget::onAdd()
{
    RecordEditor *rec = new RecordEditor(remAdd);

    if (rec->exec() == QDialog::Accepted)
    {
        mdlData->database().transaction();

        QSqlRecord record = mdlData->record();
        record.setValue(colID, QVariant(QUuid::createUuid().toString()));
        record.setValue(colText, QVariant(rec->getText()));
        record.setValue(colDate, QVariant(rec->getDate()));

        if (mdlData->insertRecord(-1, record))
        {
            if (mdlData->submitAll())
            {
                mdlData->database().commit();
            }
            else
            {
                QMessageBox::critical(this, tr("Error"), mdlData->lastError().text(), QMessageBox::Ok);
            }
        }
        else
        {
            mdlData->database().rollback();
        }
    }

    delete rec;
}

void TableWidget::onEdit()
{
    if (currentRow > -1)
    {
        RecordEditor *rec = new RecordEditor(remEdit);

        rec->setText(mdlData->index(currentRow, 1).data().toString());
        rec->setDate(mdlData->index(currentRow, 2).data().toDateTime());

        if (rec->exec() == QDialog::Accepted)
        {
            mdlData->database().transaction();

            mdlData->setData(mdlData->index(currentRow, 1), QVariant(rec->getText()));
            mdlData->setData(mdlData->index(currentRow, 2), QVariant(rec->getDate()));

            if (mdlData->submitAll())
            {
                mdlData->database().commit();
                emit tblData->clicked(QModelIndex());
            }
            else
            {
                mdlData->database().rollback();
                QMessageBox::critical(this, tr("Error"), mdlData->lastError().text(), QMessageBox::Ok);
            }
        }

        delete rec;
    }
}

void TableWidget::onDelete()
{
    if (currentRow > -1)
    {
        if (QMessageBox::question(this, tr("Confirm delete"), tr("Do you really want to delete selected row?"),
                                  QMessageBox::Ok | QMessageBox::Cancel) == QMessageBox::Ok)
        {
            mdlData->database().transaction();

            mdlData->removeRow(currentRow);

            if (mdlData->submitAll())
            {
                mdlData->database().commit();
                emit tblData->clicked(QModelIndex());
            }
            else
            {
                mdlData->database().rollback();
                QMessageBox::critical(this, tr("Error"), mdlData->lastError().text(), QMessageBox::Ok);
            }
        }
    }
}

void TableWidget::onTableClicked(const QModelIndex &current)
{
    btnEdit->setEnabled(current.isValid());
    btnDelete->setEnabled(current.isValid());

    if (current.isValid())
    {
        currentRow = current.row();
    }
    else
    {
        currentRow = -1;
    }
}
