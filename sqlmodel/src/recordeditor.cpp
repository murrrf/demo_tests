#include "recordeditor.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QDateTimeEdit>

RecordEditor::RecordEditor(RecordEditMode mode, QWidget *parent) :
    QDialog(parent)
{
    this->resize(400, 100);

    switch (mode)
    {
    case remAdd:
        this->setWindowTitle(tr("Add new record"));
        break;

    case remEdit:
        this->setWindowTitle(tr("Edit record"));
        break;

    default:
        break;
    }

    boxGrid = new QGridLayout();

    lblText = new QLabel(tr("Enter text"));
    boxGrid->addWidget(lblText, 0, 0);

    edtText = new QLineEdit();
    edtText->setMaxLength(maxTextLength);
    boxGrid->addWidget(edtText, 0, 1);

    lblDate = new QLabel(tr("Enter date"));
    boxGrid->addWidget(lblDate, 1, 0);

    edtDate = new QDateTimeEdit(QDate::currentDate());
    edtDate->setDisplayFormat("dd.MM.yyyy");
    edtDate->setCalendarPopup(true);
    boxGrid->addWidget(edtDate, 1, 1);

    boxButtons = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Cancel);
    connect(boxButtons, SIGNAL(accepted()), this, SLOT(accept()));
    connect(boxButtons, SIGNAL(rejected()), this, SLOT(reject()));

    boxMain = new QVBoxLayout();
    boxMain->addLayout(boxGrid);
    boxMain->addWidget(boxButtons);
    this->setLayout(boxMain);
}
RecordEditor::~RecordEditor()
{
    delete edtDate;
    delete lblDate;
    delete edtText;
    delete lblText;
    delete boxGrid;
    delete boxButtons;
    delete boxMain;
}

void RecordEditor::setText(const QString &text)
{
    edtText->setText(text);
}

void RecordEditor::setDate(const QDateTime &date)
{
    edtDate->setDate(date.date());
}

QString RecordEditor::getText()
{
    return edtText->text();
}

QDateTime RecordEditor::getDate()
{
    return QDateTime(edtDate->date());
}
