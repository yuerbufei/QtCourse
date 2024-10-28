#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QWidget>

// 定义一个辅助函数来设置 QLabel 的属性
void setStatusLabel(QLabel &label, const QString &initialText) {
    label.setText(initialText);
    label.adjustSize(); // 自动调整 QLabel 的大小以适应内容
    label.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed); // 设置水平方向为 Preferred，垂直方向为 Fixed
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
{
    ui->setupUi(this);

    // 创建一个水平布局来管理状态栏中的标签
    QHBoxLayout *statusBarLayout = new QHBoxLayout();
    statusBarLayout->setContentsMargins(0, 0, 0, 0); // 移除默认的边距

    // 初始化 documentInfoLabel
    QLabel *docLabel = new QLabel();
    setStatusLabel(*docLabel, "docLength: 0     lines: 1");

    // 初始化 cursorInfoLabel
    QLabel *cursorLabel = new QLabel();
    setStatusLabel(*cursorLabel, "charsBeforeCursor: 0      col: 1");

    // 创建并配置作者名称标签
    QLabel *author = new QLabel(tr("李志罡"));
    author->adjustSize(); // 自动调整作者标签的大小
    author->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    // 将标签和分隔符添加到布局中
    statusBarLayout->addWidget(docLabel);
    statusBarLayout->addWidget(createSeparator());
    statusBarLayout->addWidget(cursorLabel);
    statusBarLayout->addWidget(createSeparator());
    statusBarLayout->addStretch(); // 添加伸缩空间，使作者标签靠右对齐L
    statusBarLayout->addWidget(author);

    // 创建一个 QWidget 来容纳布局
    QWidget *statusBarWidget = new QWidget(this);
    statusBarWidget->setLayout(statusBarLayout);

    // 将 QWidget 添加到状态栏
    ui->statusbar->addPermanentWidget(statusBarWidget);
}

MainWindow::~MainWindow()
{
    // 删除动态分配的 QLabel 对象
    for (auto widget : ui->statusbar->findChildren<QLabel*>()) {
        delete widget;
    }
    delete ui;
}
