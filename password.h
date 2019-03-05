#ifndef PASSWORD_H
#define PASSWORD_H

#include <QDialog>

namespace Ui {
class Password;
}

class Password : public QDialog
{
    Q_OBJECT

public:
    explicit Password(QWidget *parent = 0);
    void Clear_Password();
    ~Password();

private slots:
    void on_Confirm_clicked();

    void on_Cancel_clicked();

private:
    Ui::Password *ui;
};

#endif // PASSWORD_H
