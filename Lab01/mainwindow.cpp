#include "mainwindow.h"  // 包含 MainWindow 类的头文件定义
#include "ui_mainwindow.h"  // 包含由 Qt Designer 生成的 UI
#include <QDebug>
#include <math.h>
#include <Qtimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)  // 调用基类 QMainWindow 的构造函数，并传入 parent 参数
    , ui(new Ui::MainWindow)  // 使用初始化列表创建并初始化指向 UI 对象的指针
{
    ui->setupUi(this);  // 设置 UI 到当前窗口，这会将设计好的界面应用到这个窗口上

    digitBtns = {
                 {Qt::Key_0,ui->btnNum0},
                 {Qt::Key_1,ui->btnNum1},
                 {Qt::Key_2,ui->btnNum2},
                 {Qt::Key_3,ui->btnNum3},
                 {Qt::Key_4,ui->btnNum4},
                 {Qt::Key_5,ui->btnNum5},
                 {Qt::Key_6,ui->btnNum6},
                 {Qt::Key_7,ui->btnNum7},
                 {Qt::Key_8,ui->btnNum8},
                 {Qt::Key_9,ui->btnNum9},
                 };

    // 连接操作数按钮（如btnNum0）的点击信号到槽函数 btnNumClicked
    // 当用户点击该按钮时，会触发 btnNumClicked 函数
    foreach (auto btn, digitBtns) {
        connect(btn,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    }

    // 设置显示文本为"0"
    ui->display->setText("0");

    // 连接操作符按钮（如btnNum0）的点击信号到槽函数 btnNumClicked
    connect(ui->btnAdd, SIGNAL(clicked()),this,SLOT(btnTwoOperatorClicked()));
    connect(ui->btnSub, SIGNAL(clicked()),this,SLOT(btnTwoOperatorClicked()));
    connect(ui->btnMultiply, SIGNAL(clicked()),this,SLOT(btnTwoOperatorClicked()));
    connect(ui->btnDivide, SIGNAL(clicked()),this,SLOT(btnTwoOperatorClicked()));

    connect(ui->btnPercentage, SIGNAL(clicked()),this,SLOT(btnOneOperatorClicked()));
    connect(ui->btnInverse, SIGNAL(clicked()),this,SLOT(btnOneOperatorClicked()));
    connect(ui->btnSquare, SIGNAL(clicked()),this,SLOT(btnOneOperatorClicked()));
    connect(ui->btnSqrt, SIGNAL(clicked()),this,SLOT(btnOneOperatorClicked()));
}

// MainWindow 析构函数
MainWindow::~MainWindow()
{
    delete ui;  // 释放 UI 对象占用的内存
}

// 定义当数字按钮被点击时执行的槽函数
void MainWindow::btnNumClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        QString digit = button->text();

        // 避免出现 "00"
        if (digit == "0" && (operand.isEmpty() || operand == "0")) {
            if (operand.isEmpty()) {
                operand = "0";
            }
            return;
        }

        // 如果当前 operand 是 "0"，重置 operand
        if (operand == "0") {
            operand = digit;  // 直接设置为新输入的数字，而不是清空后再添加
        } else {
            operand += digit;  // 累加到现有的 operand
        }

        ui->display->setText(operand);

        // 更新 currentExpression
        if (opcodes.size() > 0 && operands.size() > 0) {
            currentExpression = operands.front() + opcodes.front() + operand;
        } else {
            currentExpression = operand;
        }
        ui->statusbar->showMessage(currentExpression);
    }
}

// 处理小数点按钮点击
void MainWindow::on_btnPeriod_clicked()
{
    // 获取当前显示的文本
    QString currentText = ui->display->text();

    // 如果当前文本是"0"，则设置为"0."
    if (currentText == "0") {
        operand = "0.";
    } else if (!operand.contains(".")) {  // 如果当前文本不是"0"且不包含小数点
        operand += qobject_cast<QPushButton *>(sender())->text();
    }

    // 更新显示屏
    ui->display->setText(operand);
}

// 处理删除按钮点击
void MainWindow::on_btnDelete_clicked()
{
    operand = operand.left(operand.length() - 1);
    ui->display->setText(operand);
}

// 处理清除按钮点击
void MainWindow::on_btnClear_clicked()
{
    operand.clear();

    // 重置为"0"以保持显示屏始终有内容
    if (operand.isEmpty()) {
        operand = "0";
    }

    ui->display->setText(operand);
}

// 处理全部清除按钮点击
void MainWindow::on_btnClearAll_clicked()
{
    operand.clear();
    operands.clear();
    opcodes.clear();

    // 重置为"0"以保持显示屏始终有内容
    if (operand.isEmpty()) {
        operand = "0";
    }

    ui->display->setText(operand);
}
