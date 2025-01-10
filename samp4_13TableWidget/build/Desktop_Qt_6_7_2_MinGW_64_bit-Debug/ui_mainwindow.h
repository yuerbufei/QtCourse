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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitterMain;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *btnIniData;
    QPushButton *btnSetRows;
    QPushButton *btnAppendRow;
    QPushButton *btnAutoWidth;
    QCheckBox *chkBoxHeaderH;
    QPushButton *btnDelCurRow;
    QPushButton *btnSetHeader;
    QCheckBox *chkBoxHeaderV;
    QRadioButton *rBtnSelectItem;
    QSpinBox *spinRowCount;
    QCheckBox *chkBoxRowColor;
    QCheckBox *chkBoxTabEditable;
    QRadioButton *rBtnSelectRow;
    QPushButton *btnReadToEdit;
    QPushButton *btnAutoHeght;
    QPushButton *btnInsertRow;
    QSplitter *splitter;
    QTableWidget *tableInfo;
    QPlainTextEdit *textEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(791, 486);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        splitterMain = new QSplitter(centralWidget);
        splitterMain->setObjectName("splitterMain");
        splitterMain->setOrientation(Qt::Orientation::Horizontal);
        groupBox = new QGroupBox(splitterMain);
        groupBox->setObjectName("groupBox");
        groupBox->setMaximumSize(QSize(300, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        btnIniData = new QPushButton(groupBox);
        btnIniData->setObjectName("btnIniData");
        btnIniData->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(btnIniData, 4, 0, 1, 2);

        btnSetRows = new QPushButton(groupBox);
        btnSetRows->setObjectName("btnSetRows");
        btnSetRows->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(btnSetRows, 3, 0, 1, 1);

        btnAppendRow = new QPushButton(groupBox);
        btnAppendRow->setObjectName("btnAppendRow");

        gridLayout->addWidget(btnAppendRow, 5, 1, 1, 1);

        btnAutoWidth = new QPushButton(groupBox);
        btnAutoWidth->setObjectName("btnAutoWidth");

        gridLayout->addWidget(btnAutoWidth, 7, 1, 1, 1);

        chkBoxHeaderH = new QCheckBox(groupBox);
        chkBoxHeaderH->setObjectName("chkBoxHeaderH");
        chkBoxHeaderH->setChecked(true);

        gridLayout->addWidget(chkBoxHeaderH, 10, 0, 1, 1);

        btnDelCurRow = new QPushButton(groupBox);
        btnDelCurRow->setObjectName("btnDelCurRow");

        gridLayout->addWidget(btnDelCurRow, 6, 0, 1, 2);

        btnSetHeader = new QPushButton(groupBox);
        btnSetHeader->setObjectName("btnSetHeader");
        btnSetHeader->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(btnSetHeader, 0, 0, 1, 2);

        chkBoxHeaderV = new QCheckBox(groupBox);
        chkBoxHeaderV->setObjectName("chkBoxHeaderV");
        chkBoxHeaderV->setChecked(true);

        gridLayout->addWidget(chkBoxHeaderV, 10, 1, 1, 1);

        rBtnSelectItem = new QRadioButton(groupBox);
        rBtnSelectItem->setObjectName("rBtnSelectItem");
        rBtnSelectItem->setChecked(true);

        gridLayout->addWidget(rBtnSelectItem, 11, 1, 1, 1);

        spinRowCount = new QSpinBox(groupBox);
        spinRowCount->setObjectName("spinRowCount");
        spinRowCount->setMinimum(2);
        spinRowCount->setValue(10);

        gridLayout->addWidget(spinRowCount, 3, 1, 1, 1);

        chkBoxRowColor = new QCheckBox(groupBox);
        chkBoxRowColor->setObjectName("chkBoxRowColor");
        chkBoxRowColor->setChecked(true);

        gridLayout->addWidget(chkBoxRowColor, 9, 1, 1, 1);

        chkBoxTabEditable = new QCheckBox(groupBox);
        chkBoxTabEditable->setObjectName("chkBoxTabEditable");
        chkBoxTabEditable->setChecked(true);

        gridLayout->addWidget(chkBoxTabEditable, 9, 0, 1, 1);

        rBtnSelectRow = new QRadioButton(groupBox);
        rBtnSelectRow->setObjectName("rBtnSelectRow");
        rBtnSelectRow->setChecked(false);

        gridLayout->addWidget(rBtnSelectRow, 11, 0, 1, 1);

        btnReadToEdit = new QPushButton(groupBox);
        btnReadToEdit->setObjectName("btnReadToEdit");
        btnReadToEdit->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(btnReadToEdit, 8, 0, 1, 2);

        btnAutoHeght = new QPushButton(groupBox);
        btnAutoHeght->setObjectName("btnAutoHeght");

        gridLayout->addWidget(btnAutoHeght, 7, 0, 1, 1);

        btnInsertRow = new QPushButton(groupBox);
        btnInsertRow->setObjectName("btnInsertRow");

        gridLayout->addWidget(btnInsertRow, 5, 0, 1, 1);

        splitterMain->addWidget(groupBox);
        splitter = new QSplitter(splitterMain);
        splitter->setObjectName("splitter");
        splitter->setFrameShadow(QFrame::Shadow::Plain);
        splitter->setLineWidth(2);
        splitter->setOrientation(Qt::Orientation::Vertical);
        tableInfo = new QTableWidget(splitter);
        if (tableInfo->columnCount() < 8)
            tableInfo->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableInfo->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableInfo->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableInfo->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableInfo->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableInfo->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableInfo->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableInfo->rowCount() < 6)
            tableInfo->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableInfo->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableInfo->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableInfo->setItem(0, 7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableInfo->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableInfo->setItem(2, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableInfo->setItem(5, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableInfo->setItem(5, 7, __qtablewidgetitem12);
        tableInfo->setObjectName("tableInfo");
        tableInfo->setAlternatingRowColors(true);
        tableInfo->setShowGrid(true);
        tableInfo->setGridStyle(Qt::PenStyle::SolidLine);
        tableInfo->setRowCount(6);
        tableInfo->setColumnCount(8);
        splitter->addWidget(tableInfo);
        tableInfo->horizontalHeader()->setVisible(true);
        tableInfo->horizontalHeader()->setDefaultSectionSize(80);
        tableInfo->verticalHeader()->setVisible(true);
        tableInfo->verticalHeader()->setDefaultSectionSize(27);
        textEdit = new QPlainTextEdit(splitter);
        textEdit->setObjectName("textEdit");
        splitter->addWidget(textEdit);
        splitterMain->addWidget(splitter);

        verticalLayout->addWidget(splitterMain);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QTableWidget\347\232\204\344\275\277\347\224\250", nullptr));
        groupBox->setTitle(QString());
        btnIniData->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\350\241\250\346\240\274\346\225\260\346\215\256", nullptr));
        btnSetRows->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\350\241\214\346\225\260", nullptr));
        btnAppendRow->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\241\214", nullptr));
        btnAutoWidth->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\350\260\203\350\212\202\345\210\227\345\256\275", nullptr));
        chkBoxHeaderH->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\260\264\345\271\263\350\241\250\345\244\264", nullptr));
        btnDelCurRow->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\350\241\214", nullptr));
        btnSetHeader->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\260\264\345\271\263\350\241\250\345\244\264", nullptr));
        chkBoxHeaderV->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\236\202\347\233\264\350\241\250\345\244\264", nullptr));
        rBtnSelectItem->setText(QCoreApplication::translate("MainWindow", "\345\215\225\345\205\203\346\240\274\351\200\211\346\213\251", nullptr));
        chkBoxRowColor->setText(QCoreApplication::translate("MainWindow", "\351\227\264\351\232\224\350\241\214\345\272\225\350\211\262", nullptr));
        chkBoxTabEditable->setText(QCoreApplication::translate("MainWindow", "\350\241\250\346\240\274\345\217\257\347\274\226\350\276\221", nullptr));
        rBtnSelectRow->setText(QCoreApplication::translate("MainWindow", "\350\241\214\351\200\211\346\213\251", nullptr));
        btnReadToEdit->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\350\241\250\346\240\274\345\206\205\345\256\271\345\210\260\346\226\207\346\234\254", nullptr));
        btnAutoHeght->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\350\260\203\350\212\202\350\241\214\351\253\230", nullptr));
        btnInsertRow->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\346\200\247\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\345\207\272\347\224\237\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableInfo->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\346\260\221\346\227\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableInfo->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\345\210\206\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableInfo->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\346\230\257\345\220\246\345\205\232\345\221\230", nullptr));

        const bool __sortingEnabled = tableInfo->isSortingEnabled();
        tableInfo->setSortingEnabled(false);
        tableInfo->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
