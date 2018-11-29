#ifndef RECORDEDITOR_H
#define RECORDEDITOR_H

/**
 * @file
 * @~english
 * @brief
 * 
 * @~russian
 * @brief
 */

#include <QDialog>

#include "consts.h"

enum RecordEditMode
{
    remAdd,
    remEdit
};

//Forward declarations
class QVBoxLayout;
class QGridLayout;
class QLabel;
class QLineEdit;
class QDialogButtonBox;
class QDateTimeEdit;

class RecordEditor : public QDialog
{
    Q_OBJECT
public:
    explicit RecordEditor(RecordEditMode mode, QWidget *parent = 0);
    ~RecordEditor();
    void setText(const QString &text);
    void setDate(const QDateTime &date);
    QString getText();
    QDateTime getDate();
signals:

public slots:

private:
    QVBoxLayout *boxMain;
    QGridLayout *boxGrid;
    QLabel *lblText;
    QLineEdit *edtText;
    QLabel *lblDate;
    QDateTimeEdit *edtDate;
    QDialogButtonBox *boxButtons;
};

#endif // RECORDEDITOR_H
