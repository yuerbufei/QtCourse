#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "searchdialog.h"
#include "replacedialog.h"

#include <QHBoxLayout>
#include <QWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QFontDialog>
#include <QTextEdit>

#include <QColorDialog>
#include <QPixmap>
#include <QPalette>
#include <QGraphicsOpacityEffect>  // 透明度
#include <QSlider>  // 滑块

#include <QFileDialog>
#include <QTextStream>

#include <QDebug>


// 初始化常量颜色
const QColor MainWindow::DefaultBackgroundColor(Qt::white);
const QColor MainWindow::LightYellow(255, 250, 205); // 米黄色
const QColor MainWindow::LightGreen(208, 232, 211);  // 淡绿色
const QColor MainWindow::LightBlue(204, 229, 255);   // 淡蓝色


// 辅助函数：设置 QLabel 的属性
void setStatusLabel(QLabel &label, const QString &initialText) {
    label.setText(initialText);
    label.adjustSize();  // 自动调整 QLabel 的大小以适应内容
    label.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);  // 设置水平方向为 Preferred，垂直方向为 Fixed
}

// 创建分隔符标签
QLabel *createSeparator() {
    QLabel *separator = new QLabel("    ");
    separator->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    return separator;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , textChanged(false)
    , toolBar(new QToolBar(this))
    , statusBarVisible(true) // 初始化工具栏
// , opacityEffect(new QGraphicsOpacityEffect(this))
{
    ui->setupUi(this);

    // 初始化并触发新建文件操作
    on_actionNew_triggered();
}

MainWindow::~MainWindow()
{
    // 删除动态分配的 QLabel 对象
    for (auto widget : ui->statusbar->findChildren<QLabel*>()) {
        delete widget;
    }
    delete ui;
}

// 撤销操作
void MainWindow::on_actionUndo_triggered()
{
    if (ui->textEdit->document()->isUndoAvailable()) {
        ui->textEdit->undo();
    }
}
// 恢复操作
void MainWindow::on_actionRedo_triggered()
{
    if (ui->textEdit->document()->isRedoAvailable()) {
        ui->textEdit->redo();
    }
}
// 复制
void MainWindow::on_actionCopy_triggered()
{
    if (ui->textEdit->textCursor().hasSelection()) {
        ui->textEdit->copy();
    } else {
        // 如果没有选中文本，则可以显示一个提示信息
        QMessageBox::information(this, tr("复制"), tr("请先选择要复制的文本。"));
    }
}
// 剪切
void MainWindow::on_actionCut_triggered()
{
    if (ui->textEdit->textCursor().hasSelection()) {
        ui->textEdit->cut();
    } else {
        // 如果没有选中文本，则可以显示一个提示信息
        QMessageBox::information(this, tr("剪切"), tr("请先选择要剪切的文本。"));
    }
}
// 粘贴
void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

// 全选
void MainWindow::on_actionSelectAll_triggered()
{
    ui->textEdit->selectAll();
}

// 查找对话框
void MainWindow::on_actionFind_triggered()
{
    SearchDialog dialog(this,ui->textEdit);
    dialog.exec();
}
// 替换对话框
void MainWindow::on_actionReplace_triggered()
{
    ReplaceDialog dialog(this,ui->textEdit);
    dialog.exec();
}

// 关于对话框
void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dialog;
    dialog.exec();
}
