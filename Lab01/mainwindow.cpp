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

// 进行运算操作
QString MainWindow::calculation(bool *ok)
{
    *ok = true;
    if (operands.size() != 2 || opcodes.size() != 1) {
        *ok = false;
        return "Error";
    }

    // 打印输入值
    qDebug() << "Operand 1:" << operands.front();
    qDebug() << "Operand 2:" << operands.back();
    qDebug() << "Opcode:" << opcodes.front();

    double operand1 = operands.front().toDouble();
    double operand2 = operands.back().toDouble();
    QString opcode = opcodes.front();

    // 检查转换后的值
    qDebug() << "Converted Operand 1:" << operand1;
    qDebug() << "Converted Operand 2:" << operand2;

    double result = 0.0;

    if (opcode == "+") {
        result = operand1 + operand2;
    } else if (opcode == "-") {
        result = operand1 - operand2;
    } else if (opcode == "×") {
        result = operand1 * operand2;
    } else if (opcode == "÷") {
        if (operand2 != 0) {
            result = operand1 / operand2;
        } else {
            *ok = false;
            return "Error: Division by zero";
        }


        ui->statusbar->showMessage(QString("calculations is in process: operands size %1, opcodes size %2")
                                       .arg(operands.size()).arg(opcodes.size()));
    } else {
        *ok = false;

        ui->statusbar->showMessage(QString("operands size %1, opcodes size %2")
                                       .arg(operands.size()).arg(opcodes.size()));
        return "Error: Unknown operator";
    }

    // 打印结果
    qDebug() << "Result:" << result;

    return QString::number(result);
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

// 单操作数运算符处理
void MainWindow::btnOneOperatorClicked()
{
    if (operand != "") {
        double result = operand.toDouble();
        operand.clear();  // 清空 operand

        QString opcode = qobject_cast<QPushButton *>(sender())->text();

        if (opcode == "%") {
            result /= 100.0;
        } else if (opcode == "1/x") {
            if (result != 0) {
                result = 1.0 / result;
            } else {
                ui->statusbar->showMessage("除数不能为零");
                return;
            }
        } else if (opcode == "x^2") {
            result *= result;
        } else if (opcode == "2√x") {
            if (result >= 0) {
                result = sqrt(result);
            } else {
                ui->statusbar->showMessage("无法对负数开平方根");
                return;
            }
        }

        // 更新 operand 并在 UI 上显示结果
        operand = QString::number(result);
        ui->display->setText(operand);

        // 清空 operands 和 opcodes，准备下一次计算
        operands.clear();
        opcodes.clear();
    }
}

// 双操作数运算符处理
void MainWindow::btnTwoOperatorClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button) {
        if (!operand.isEmpty()) {
            operands.push_back(operand);
            operand.clear();  // 清空 operand 以准备接收下一个操作数

            QString opcode = button->text();
            opcodes.push_back(opcode);

            // 更新 currentExpression
            if (operands.size() >= 1 && opcodes.size() >= 1) {
                currentExpression = operands.front() + opcodes.front();
                if (operands.size() == 2) {
                    currentExpression += operands.back();
                }
                ui->statusbar->showMessage(currentExpression);
            }

            // 如果已经有两个操作数和一个操作符，立即进行计算
            if (operands.size() == 2 && opcodes.size() == 1) {
                bool ok = true;
                QString result = calculation(&ok);
                if (ok) {
                    ui->display->setText(result);
                    // 清空 operands 和 opcodes，准备下一次计算
                    operands.clear();
                    opcodes.clear();
                    // 将当前结果设置为新的 operand
                    operand = result;

                    // 更新 currentExpression 显示最终结果
                    currentExpression = result;
                    ui->statusbar->showMessage(currentExpression);
                } else {
                    ui->statusbar->showMessage("计算出错");
                }
            }
        }
    }
}


// 等号按钮点击处理
void MainWindow::on_btnEqual_clicked()
{
    // 如果 operand 不为空，则将其添加到 operands 列表中
    if (!operand.isEmpty()) {
        operands.push_back(operand);
        operand.clear();  // 清空 operand 以准备接收下一个操作数
    }

    // 如果已经有两个操作数和一个操作符，立即进行计算
    if (operands.size() == 2 && opcodes.size() == 1) {
        bool ok = true;
        QString result = calculation(&ok);
        if (ok) {
            ui->display->setText(result);
            // 清空 operands 和 opcodes，准备下一次计算
            operands.clear();
            opcodes.clear();
            // 将当前结果设置为新的 operand
            operand = result;

            // 更新 currentExpression 显示最终结果
            currentExpression = result;
            ui->statusbar->showMessage(currentExpression);
        } else {
            ui->statusbar->showMessage("计算出错");
        }
    } else {
        // 如果 operands 或 opcodes 数量不正确，显示错误信息
        ui->statusbar->showMessage(QString("操作数或操作符数量不正确: operands size %1, opcodes size %2")
                                       .arg(operands.size()).arg(opcodes.size()));
    }
}

// 在指定的延迟后模拟按钮点击
void animateButtonClick(QAbstractButton *button, int delay)
{
    QTimer::singleShot(delay, button, &QPushButton::animateClick);
}

// 处理键盘按键事件
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    foreach(auto btnKey,digitBtns.keys()){
        if(event->key() == btnKey){
            // digitBtns[btnKey]->animateClick(100);
            // Too many arguments to function call, expected 0, have 1

            // 定义辅助函数模拟按钮点击
            animateButtonClick(digitBtns[btnKey], 100);

            digitBtns[btnKey]->animateClick();
        }
    }
}

