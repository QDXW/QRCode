/********************************************************************************
** Form generated from reading UI file 'password.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORD_H
#define UI_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Password
{
public:
    QLineEdit *User_name;
    QLabel *label_Password;
    QPushButton *Cancel;
    QLineEdit *Password_QLine;
    QLabel *label_name;
    QPushButton *Confirm;

    void setupUi(QDialog *Password)
    {
        if (Password->objectName().isEmpty())
            Password->setObjectName(QStringLiteral("Password"));
        Password->resize(400, 300);
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        Password->setFont(font);
        User_name = new QLineEdit(Password);
        User_name->setObjectName(QStringLiteral("User_name"));
        User_name->setGeometry(QRect(180, 40, 171, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(20);
        User_name->setFont(font1);
        label_Password = new QLabel(Password);
        label_Password->setObjectName(QStringLiteral("label_Password"));
        label_Password->setGeometry(QRect(30, 120, 131, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(18);
        label_Password->setFont(font2);
        label_Password->setFrameShape(QFrame::WinPanel);
        label_Password->setFrameShadow(QFrame::Raised);
        Cancel = new QPushButton(Password);
        Cancel->setObjectName(QStringLiteral("Cancel"));
        Cancel->setGeometry(QRect(210, 220, 131, 51));
        Cancel->setFont(font1);
        Password_QLine = new QLineEdit(Password);
        Password_QLine->setObjectName(QStringLiteral("Password_QLine"));
        Password_QLine->setGeometry(QRect(180, 120, 171, 51));
        Password_QLine->setFont(font1);
        Password_QLine->setEchoMode(QLineEdit::Password);
        Password_QLine->setCursorMoveStyle(Qt::LogicalMoveStyle);
        label_name = new QLabel(Password);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(30, 40, 131, 51));
        label_name->setFont(font2);
        label_name->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_name->setFrameShape(QFrame::WinPanel);
        label_name->setFrameShadow(QFrame::Raised);
        Confirm = new QPushButton(Password);
        Confirm->setObjectName(QStringLiteral("Confirm"));
        Confirm->setGeometry(QRect(30, 220, 131, 51));
        Confirm->setFont(font1);

        retranslateUi(Password);

        QMetaObject::connectSlotsByName(Password);
    } // setupUi

    void retranslateUi(QDialog *Password)
    {
        Password->setWindowTitle(QApplication::translate("Password", "Dialog", Q_NULLPTR));
        User_name->setText(QApplication::translate("Password", "Admin", Q_NULLPTR));
        label_Password->setText(QApplication::translate("Password", "Password:", Q_NULLPTR));
        Cancel->setText(QApplication::translate("Password", "Cancel", Q_NULLPTR));
        Password_QLine->setText(QString());
        label_name->setText(QApplication::translate("Password", "User Name:", Q_NULLPTR));
        Confirm->setText(QApplication::translate("Password", "Confirm", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Password: public Ui_Password {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_H
