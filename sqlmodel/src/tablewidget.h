#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

/**
 * @file
 * @~english
 * @brief
 * 
 * @~russian
 * @brief
 */

#include <QWidget>
#include <QSqlDatabase>
#include <QItemSelection>

class QHBoxLayout;
class QVBoxLayout;
class QPushButton;
class QTableView;
class QSqlTableModel;
class QSortFilterProxyModel;

class TableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TableWidget(QSqlDatabase db, QWidget *parent = 0);
    ~TableWidget();
    void setTable(const QString &tableName);
signals:

public slots:

private:
    QVBoxLayout *boxMain;
    QHBoxLayout *boxButtons;
    QPushButton *btnAdd;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QTableView *tblData;
    QSqlTableModel *mdlData;
    QSortFilterProxyModel *mdlSortProxy;
    int currentRow;   
    enum Column
    {
        colID,
        colText,
        colDate
    };
private slots:
    void onAdd();
    void onEdit();
    void onDelete();
    void onTableClicked(const QModelIndex &current);
};

#endif // TABLEWIDGET_H
