/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QStackedWidget *stackedWidget;
    QWidget *loginPage;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QFrame *loginFrame;
    QGridLayout *gridLayout_2;
    QPushButton *submitButton;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLineEdit *serverAddressEdit;
    QLineEdit *userNameEdit;
    QLabel *label_3;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QWidget *chatPage;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *inputLineEdit;
    QPushButton *sendButton;
    QPushButton *logoutButton;
    QHBoxLayout *horizontalLayout;
    QTextEdit *roomTextEdit;
    QListWidget *userListWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("#titleLabel {\n"
"    background: white;\n"
"    border: none;\n"
"    border-bottom: 1px solid black;\n"
"    padding: 5px;\n"
"    font: 24pt \"\351\273\221\344\275\223\";\n"
"    color: rgb(255, 255, 255);\n"
"    background-color: rgba(0, 170, 127, 255);\n"
"}\n"
"\n"
"#mainFrame {\n"
"    border: none;\n"
"    background: white;\n"
"}\n"
"\n"
"#loginFrame {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ddf, stop: 1 #aaf);\n"
"    border: 1px solid gray;\n"
"    padding: 10px;\n"
"    border-radius: 25px;\n"
"}"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");

        verticalLayout->addWidget(titleLabel);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("#titleLabel {\n"
"    background: white;\n"
"    border: none;\n"
"    border-bottom: 1px solid black;\n"
"    padding: 5px;\n"
"    font: 24pt \"\351\273\221\344\275\223\";\n"
"    color: rgb(255, 255, 255);\n"
"    background-color: rgba(0, 170, 127, 255);\n"
"}\n"
"\n"
"#mainFrame {\n"
"    border: none;\n"
"    background: white;\n"
"}\n"
"\n"
"#loginFrame {\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ddf, stop: 1 #aaf);\n"
"    border: 1px solid gray;\n"
"    padding: 10px;\n"
"    border-radius: 25px;\n"
"}"));
        loginPage = new QWidget();
        loginPage->setObjectName("loginPage");
        loginPage->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(loginPage);
        gridLayout_3->setObjectName("gridLayout_3");
        verticalSpacer_2 = new QSpacerItem(20, 176, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(253, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        loginFrame = new QFrame(loginPage);
        loginFrame->setObjectName("loginFrame");
        loginFrame->setFrameShape(QFrame::Shape::StyledPanel);
        loginFrame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_2 = new QGridLayout(loginFrame);
        gridLayout_2->setObjectName("gridLayout_2");
        submitButton = new QPushButton(loginFrame);
        submitButton->setObjectName("submitButton");

        gridLayout_2->addWidget(submitButton, 3, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        serverAddressEdit = new QLineEdit(loginFrame);
        serverAddressEdit->setObjectName("serverAddressEdit");

        gridLayout->addWidget(serverAddressEdit, 0, 1, 2, 1);

        userNameEdit = new QLineEdit(loginFrame);
        userNameEdit->setObjectName("userNameEdit");

        gridLayout->addWidget(userNameEdit, 2, 1, 1, 1);

        label_3 = new QLabel(loginFrame);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_2 = new QLabel(loginFrame);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 2, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 4, 0, 1, 1);


        gridLayout_3->addWidget(loginFrame, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(253, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 176, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 2, 1, 1, 1);

        stackedWidget->addWidget(loginPage);
        chatPage = new QWidget();
        chatPage->setObjectName("chatPage");
        gridLayout_4 = new QGridLayout(chatPage);
        gridLayout_4->setObjectName("gridLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        inputLineEdit = new QLineEdit(chatPage);
        inputLineEdit->setObjectName("inputLineEdit");

        horizontalLayout_2->addWidget(inputLineEdit);

        sendButton = new QPushButton(chatPage);
        sendButton->setObjectName("sendButton");

        horizontalLayout_2->addWidget(sendButton);

        logoutButton = new QPushButton(chatPage);
        logoutButton->setObjectName("logoutButton");

        horizontalLayout_2->addWidget(logoutButton);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        roomTextEdit = new QTextEdit(chatPage);
        roomTextEdit->setObjectName("roomTextEdit");

        horizontalLayout->addWidget(roomTextEdit);

        userListWidget = new QListWidget(chatPage);
        userListWidget->setObjectName("userListWidget");
        userListWidget->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(userListWidget);


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);

        stackedWidget->addWidget(chatPage);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\201\212\345\244\251\345\256\244\345\256\242\346\210\267\347\253\257", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\346\235\216\345\277\227\347\275\241\347\232\204\350\201\212\345\244\251\345\256\244 ", nullptr));
        submitButton->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225\345\210\260\350\201\212\345\244\251\345\256\244", nullptr));
        serverAddressEdit->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        userNameEdit->setText(QCoreApplication::translate("MainWindow", "user01", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "    \346\230\265\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
