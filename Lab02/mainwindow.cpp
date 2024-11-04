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

// 新建文件
void MainWindow::on_actionNew_triggered()
{
    if (!userEditConfirmed()) {
        return;
    }

    filePath.clear();  // 清空当前文件路径
    ui->textEdit->clear();  // 清除文本编辑器内容
    setWindowTitle(tr("无标题 - 编辑器"));  // 设置窗口标题
    textChanged = false;  // 重置文本更改标志
}
// 打开文件
void MainWindow::on_actionOpen_triggered()
{
    if (!userEditConfirmed()) {
        return;
    }

    QString filename = QFileDialog::getOpenFileName(this, tr("打开文件"), ".", tr("Text files (*.txt);;All files (*.*)"));

    if (filename.isEmpty()) {
        return;  // 如果用户取消了选择，则直接返回
    }

    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("错误"), tr("无法打开文件"));
        return;
    }

    filePath = filename;
    QTextStream in(&file);
    ui->textEdit->setPlainText(in.readAll());
    file.close();

    setWindowTitle(QFileInfo(filePath).fileName() + " - 编辑器");  // 更新窗口标题
    textChanged = false;  // 重置文本更改标志
}
// 保存文件
void MainWindow::on_actionSave_triggered()
{
    if (filePath.isEmpty()) {
        on_actionSaveAs_triggered();  // 如果没有文件路径，就当作另存为
    } else {
        QFile file(filePath);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, tr("错误"), tr("无法保存文件"));
            return;
        }

        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
        file.flush();
        file.close();

        textChanged = false;  // 保存后重置文本更改标志
    }
}

// 确认用户是否要保存更改
bool MainWindow::userEditConfirmed()
{
    if (textChanged) {
        QString path = !filePath.isEmpty() ? filePath : "无标题.txt";

        QMessageBox msg(this);
        msg.setIcon(QMessageBox::Question);
        msg.setWindowTitle(tr("新建文件"));
        msg.setText(tr("是否将更改保存到\n") + "\"" + path + "\"?");
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        int r = msg.exec();
        switch (r) {
        case QMessageBox::Yes:
            on_actionSave_triggered();
            break;
        case QMessageBox::No:
            textChanged = false;
            break;
        case QMessageBox::Cancel:
            return false;
        default:
            break;
        }
    }

    return true;
}
// 另存为
void MainWindow::on_actionSaveAs_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("另存为"), ".", tr("Text files (*.txt);;All files (*.*)"));

    if (filename.isEmpty()) {
        return;  // 用户取消保存
    }

    QFile file(filename);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("错误"), tr("无法保存文件"));
        return;
    }

    filePath = filename;
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.flush();
    file.close();

    setWindowTitle(QFileInfo(filePath).fileName() + " - 编辑器");  // 更新窗口标题
    textChanged = false;  // 保存后重置文本更改标志
}
// 退出
void MainWindow::on_actionExit_triggered()
{
    qApp->exit(0);
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

// 自动换行
void MainWindow::on_actionWrap_triggered()
{
    if (ui->textEdit->lineWrapMode() == QTextEdit::WidgetWidth) {
        // 如果当前是自动换行模式，则关闭它
        ui->textEdit->setLineWrapMode(QTextEdit::NoWrap);
    } else {
        // 否则启用自动换行
        ui->textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
    }
}
// 字体
void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, ui->textEdit->font(), this);

    if (ok) {
        // 应用选定的字体
        ui->textEdit->setFont(font);
    }
}
// 字体颜色
void MainWindow::on_actionFontColor_triggered()
{
    QColor color = QColorDialog::getColor(ui->textEdit->textColor(), this, tr("选择字体颜色"));

    if (color.isValid()) {
        // 应用选定的颜色
        ui->textEdit->setTextColor(color);
    }
}
// 字体背景色
void MainWindow::on_actionFontBackScenery_triggered()
{
    QColor color = QColorDialog::getColor(ui->textEdit->textBackgroundColor(), this, tr("选择字体背景颜色"));

    if (color.isValid()) {
        // 应用选定的背景颜色
        QTextCharFormat fmt;
        fmt.setBackground(color);
        ui->textEdit->mergeCurrentCharFormat(fmt);
    }
}

// 编辑器背景色
void MainWindow::on_actionEditorBackScenery_triggered()
{
    QDialog dialog(this);
    dialog.setWindowTitle(tr("编辑器背景色"));  // 设置对话框标题

    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    // 预设颜色按钮
    QPushButton *defaultButton = new QPushButton(tr("默认白色"), &dialog);
    QPushButton *yellowButton = new QPushButton(tr("米黄色"), &dialog);
    QPushButton *greenButton = new QPushButton(tr("淡绿色"), &dialog);
    QPushButton *blueButton = new QPushButton(tr("淡蓝色"), &dialog);

    // 连接信号与槽
    connect(defaultButton, &QPushButton::clicked, [this, &dialog] {
        applyBackgroundColor(Qt::white, 1.0);  // 默认不透明
        dialog.accept();
    });
    connect(yellowButton, &QPushButton::clicked, [this, &dialog] {
        applyBackgroundColor(QColor(255, 255, 224), 1.0);  // 米黄色
        dialog.accept();
    });
    connect(greenButton, &QPushButton::clicked, [this, &dialog] {
        applyBackgroundColor(QColor(204, 255, 204), 1.0);  // 淡绿色
        dialog.accept();
    });
    connect(blueButton, &QPushButton::clicked, [this, &dialog] {
        applyBackgroundColor(QColor(204, 229, 255), 1.0);  // 淡蓝色
        dialog.accept();
    });

    // 自定义颜色按钮
    QPushButton *customColorButton = new QPushButton(tr("自定义颜色..."), &dialog);
    connect(customColorButton, &QPushButton::clicked, [this, &dialog] {
        QColor color = QColorDialog::getColor(this->palette().color(QPalette::Window), this, tr("选择背景颜色"));
        if (color.isValid()) {
            applyBackgroundColor(color, 1.0);
            dialog.accept();
        }
    });

    // 上传图片按钮
    QPushButton *imageButton = new QPushButton(tr("上传图片..."), &dialog);
    connect(imageButton, &QPushButton::clicked, [this, &dialog] {
        QString imagePath = QFileDialog::getOpenFileName(this, tr("选择背景图片"), "", tr("Images (*.png *.xpm *.jpg *.bmp *.gif)"));
        if (!imagePath.isEmpty()) {
            setBackgroundImage(imagePath, 1.0);
            dialog.accept();
        }
    });

    // 添加控件到布局
    layout->addWidget(defaultButton);
    layout->addWidget(yellowButton);
    layout->addWidget(greenButton);
    layout->addWidget(blueButton);
    layout->addWidget(customColorButton);
    layout->addWidget(imageButton);

    // 显示对话框
    dialog.exec();
}

// 打开图片文件对话框
void MainWindow::openImageFileDialog()
{
    QString imagePath = QFileDialog::getOpenFileName(this, tr("选择背景图片"), "", tr("Images (*.png *.xpm *.jpg *.bmp *.gif)"));
    if (!imagePath.isEmpty()) {
        setBackgroundImage(imagePath, 1.0);  // 应用默认不透明度
    }
}

// 应用背景颜色
void MainWindow::applyBackgroundColor(const QColor &color, double opacity)
{
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, color);
    this->setPalette(palette);

    QPalette textEditPalette = ui->textEdit->palette();
    textEditPalette.setColor(QPalette::Base, color);
    ui->textEdit->setPalette(textEditPalette);

    // 强制重绘
    this->update();
}

// 应用背景图片
void MainWindow::setBackgroundImage(const QString &path, double opacity)
{
    QPixmap pixmap(path);
    if (!pixmap.isNull()) {
        pixmap = pixmap.scaled(this->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        pixmap.scaled(this->size());

        QPalette palette = this->palette();
        palette.setBrush(QPalette::Window, QBrush(pixmap));
        this->setPalette(palette);

        QPalette textEditPalette = ui->textEdit->palette();
        textEditPalette.setBrush(QPalette::Base, QBrush(pixmap));
        ui->textEdit->setPalette(textEditPalette);

        // 强制重绘
        this->update();
    }
}

// 工具栏
void MainWindow::on_actionToolBar_triggered()
{
    // 假设 toolBar 是一个 QToolBar 类型的成员变量
    toolBar->setVisible(!toolBar->isVisible());
}

// 状态栏
void MainWindow::on_actionStatus_triggered()
{
    if (statusBarWidget.parent() == nullptr) {
        // 创建状态栏布局
        QHBoxLayout *statusBarLayout = new QHBoxLayout(&statusBarWidget);
        statusBarLayout->setContentsMargins(0, 0, 0, 0);

        // 初始化文档信息标签
        setStatusLabel(docLabel, "docLength: 0     lines: 1");
        docLabel.setObjectName("docLabel");

        // 初始化光标信息标签
        setStatusLabel(cursorLabel, "charsBeforeCursor: 0      col: 1");
        cursorLabel.setObjectName("cursorLabel");

        // 创建并配置作者名称标签
        QLabel author(tr("李志罡"), &statusBarWidget);
        author.adjustSize();
        author.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

        // 将标签和分隔符添加到布局中
        statusBarLayout->addWidget(&docLabel);
        statusBarLayout->addWidget(createSeparator());
        statusBarLayout->addWidget(&cursorLabel);
        statusBarLayout->addWidget(createSeparator());
        statusBarLayout->addStretch();
        statusBarLayout->addWidget(&author);

        // 将 QWidget 添加到状态栏
        ui->statusbar->addPermanentWidget(&statusBarWidget);
    }

    // 切换状态栏的可见性
    on_actionStatus_visibleChanged();
}

// 切换状态栏的可见性
void MainWindow::on_actionStatus_visibleChanged()
{
    statusBarWidget.setVisible(!statusBarWidget.isVisible());
    statusBarVisible = !statusBarVisible;
}

// 处理鼠标按下事件
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // 检查点击是否发生在状态栏上
    if (ui->statusbar->geometry().contains(event->pos())) {
        on_actionStatus_visibleChanged();
    } else {
        QMainWindow::mousePressEvent(event); // 如果不是在状态栏上，则传递给基类处理
    }
}

// 设置标签文本的辅助函数
void MainWindow::setStatusLabel(QLabel &label, const QString &text)
{
    label.setText(text);
}

// 创建分隔符的辅助函数
QWidget* MainWindow::createSeparator()
{
    QWidget *separator = new QWidget(&statusBarWidget);
    separator->setFixedWidth(2);  // 设置分隔符宽度
    return separator;
}

// 文本变化时更新信息
void MainWindow::on_textEdit_textChanged()
{
    updateStatusBar();  // 更新状态栏信息

    if (!textChanged) {
        setWindowTitle("*" + windowTitle());  // 在窗口标题前加星号表示有未保存的更改
        textChanged = true;
    }
}

// 根据更改后文本，更新状态栏信息
void MainWindow::updateStatusBar()
{
    // 获取当前文本
    QString text = ui->textEdit->toPlainText();

    // 计算文档长度（字符数）
    int docLength = text.length();
    // 计算行数
    int lines = text.count('\n') + 1;  // 每个换行符'\n'表示一行，加上最后一行

    // 获取光标位置
    QTextCursor cursor = ui->textEdit->textCursor();
    // 计算光标前的字符数
    int charsBeforeCursor = cursor.position();
    // 计算光标所在列
    int col = cursor.columnNumber() + 1;  // columnNumber 是从0开始的，所以我们加1

    // 更新状态栏中的 QLabel
    QLabel *docLabel = findChild<QLabel*>("docLabel");
    if (docLabel) {
        docLabel->setText(tr("字数: %1     行数: %2").arg(docLength).arg(lines));
    }

    QLabel *cursorLabel = findChild<QLabel*>("cursorLabel");
    if (cursorLabel) {
        cursorLabel->setText(tr("光标位置: %1     列: %2").arg(charsBeforeCursor).arg(col));
    }
}

// 关于对话框
void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dialog;
    dialog.exec();
}
