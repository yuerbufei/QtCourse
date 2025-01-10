#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QToolButton>
#include <QFont>
#include <QColor>
#include <QDate>
#include <QTableWidgetItem>
#include <QRandomGenerator>

// 模拟从PDF中解析学生名单的函数
QList<QMap<QString, QVariant>> parseStudentListFromPDF()
{
    QList<QMap<QString, QVariant>> students;
    // 模拟数据
    students.append({{"学号", "202105001"}, {"姓名", "张三"}, {"性别", "男"}, {"行政班几", "1班"}, {"院系", "计算机学院"}, {"专业", "软件工程"}, {"修读性质", "全日制"}});
    students.append({{"学号", "202105002"}, {"姓名", "李四"}, {"性别", "女"}, {"行政班几", "2班"}, {"院系", "经济管理学院"}, {"专业", "会计学"}, {"修读性质", "全日制"}});
    students.append({{"学号", "202105003"}, {"姓名", "王五"}, {"性别", "男"}, {"行政班几", "3班"}, {"院系", "机械工程学院"}, {"专业", "机械设计制造及其自动化"}, {"修读性质", "全日制"}});
    students.append({{"学号", "202105004"}, {"姓名", "赵六"}, {"性别", "女"}, {"行政班几", "4班"}, {"院系", "外国语学院"}, {"专业", "英语"}, {"修读性质", "全日制"}});
    students.append({{"学号", "202105005"}, {"姓名", "孙七"}, {"性别", "男"}, {"行政班几", "5班"}, {"院系", "数学科学学院"}, {"专业", "数学与应用数学"}, {"修读性质", "全日制"}});
    students.append({{"学号", "202105006"}, {"姓名", "周八"}, {"性别", "女"}, {"行政班几", "6班"}, {"院系", "物理科学学院"}, {"专业", "物理学"}, {"修读性质", "全日制"}});
    students.append({{"学号", "202105007"}, {"姓名", "吴九"}, {"性别", "男"}, {"行政班几", "7班"}, {"院系", "化学化工学院"}, {"专业", "化学"}, {"修读性质", "全日制"}});
    students.append({{"学号", "202105008"}, {"姓名", "郑十"}, {"性别", "女"}, {"行政班几", "8班"}, {"院系", "生命科学学院"}, {"专业", "生物技术"}, {"修读性质", "全日制"}});
    return students;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建工具栏和工具按钮
    QToolBar *toolBar = addToolBar("Tools");
    QToolButton *btnSetStudentList = new QToolButton(this);
    btnSetStudentList->setText("设置学生名单");
    btnSetStudentList->setToolTip("设置学生名单");
    connect(btnSetStudentList, &QToolButton::clicked, this, &MainWindow::on_btnSetStudentList_clicked);
    toolBar->addWidget(btnSetStudentList);

    // 状态栏初始化创建
    labCellIndex = new QLabel("当前单元格坐标：", this);
    labCellIndex->setMinimumWidth(250);

    labCellType = new QLabel("当前单元格类型：", this);
    labCellType->setMinimumWidth(200);

    labStudID = new QLabel("学生ID：", this);
    labStudID->setMinimumWidth(200);

    ui->statusBar->addWidget(labCellIndex); // 添加到状态栏
    ui->statusBar->addWidget(labCellType);
    ui->statusBar->addWidget(labStudID);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSetStudentList_clicked()
{
    // 从PDF中解析学生名单
    QList<QMap<QString, QVariant>> students = parseStudentListFromPDF();

    // 设置表头
    QStringList headers;
    headers << "学号" << "姓名" << "性别" << "行政班几" << "院系" << "专业" << "修读性质";
    ui->tableInfo->setColumnCount(headers.size());
    for (int i = 0; i < headers.size(); ++i) {
        QTableWidgetItem *headerItem = new QTableWidgetItem(headers[i]);
        headerItem->setFont(QFont("Microsoft YaHei", 11, QFont::Bold));
        headerItem->setForeground(Qt::red);
        ui->tableInfo->setHorizontalHeaderItem(i, headerItem);
    }

    // 清除现有内容
    ui->tableInfo->clearContents();

    // 填充表格内容
    int rowCount = qMin(5, students.size()); // 取前两行和后两行，一共5行
    ui->tableInfo->setRowCount(rowCount);
    for (int i = 0; i < rowCount; ++i) {
        int index = (i < 2) ? i : students.size() - 3 + i; // 计算实际索引
        const QMap<QString, QVariant> &student = students[index];
        for (int col = 0; col < headers.size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(student.value(headers[col]).toString());
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->tableInfo->setItem(i, col, item);
        }

        // 设置特定学生的字体和颜色
        if (student["学号"] == "202105003" && student["姓名"] == "王五") { // 替换为目标学生的学号和姓名
            for (int col = 0; col < headers.size(); ++col) {
                QTableWidgetItem *item = ui->tableInfo->item(i, col);
                if (item) {
                    item->setFont(QFont("Microsoft YaHei", 11, QFont::Bold));
                    item->setForeground(Qt::red);
                }
            }
        }
    }
}

void MainWindow::on_btnSetHeader_clicked()
{
    // 定义表头文本列表
    QStringList headerText;
    headerText << "姓名" << "性别" << "出生日期" << "民族" << "分数" << "是否党员";

    // 设置表格列数为表头文本的数量
    ui->tableInfo->setColumnCount(headerText.size());

    // 遍历每一列，设置表头项
    for (int i = 0; i < ui->tableInfo->columnCount(); i++) {
        QTableWidgetItem *headerItem = new QTableWidgetItem(headerText.at(i));

        // 设置字体加粗和颜色
        QFont font = headerItem->font();
        font.setBold(true);
        font.setPointSize(11);
        headerItem->setForeground(QBrush(Qt::red));
        headerItem->setFont(font);

        // 将设置好的表头项应用到表格中
        ui->tableInfo->setHorizontalHeaderItem(i, headerItem);
    }
}

void MainWindow::on_btnSetRows_clicked()
{
    // 根据spinRowCount控件的值设置表格行数
    ui->tableInfo->setRowCount(ui->spinRowCount->value());

    // 根据chkBoxRowColor复选框的状态设置交替行颜色
    ui->tableInfo->setAlternatingRowColors(ui->chkBoxRowColor->isChecked());
}

void MainWindow::on_btnIniData_clicked()
{
    // 初始化一个出生日期对象
    QDate birth(2001, 4, 6);

    // 清除表格现有内容
    ui->tableInfo->clearContents();

    // 循环遍历每一行，填充数据
    for (int i = 0; i < ui->tableInfo->rowCount(); i++) {
        QString strName = QString("学生%1").arg(i);  // 生成姓名
        QString strSex = ((i % 2) == 0) ? "男" : "女";  // 根据行号确定性别
        bool isParty = ((i % 2) == 0) ? false : true;  // 根据行号确定是否党员
        int score = QRandomGenerator::global()->bounded(60, 100);  // 随机生成分数

        // 调用辅助函数为当前行创建并设置单元格
        createItemsARow(i, strName, strSex, birth, "汉族", isParty, score);

        // 更新出生日期
        birth = birth.addDays(20);
    }
}

void MainWindow::on_chkBoxTabEditable_clicked(bool checked)
{
    // 根据复选框状态设置表格是否可编辑
    if (checked)
        ui->tableInfo->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
    else
        ui->tableInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::on_chkBoxHeaderH_clicked(bool checked)
{
    // 根据复选框状态设置水平表头可见性
    ui->tableInfo->horizontalHeader()->setVisible(checked);
}

void MainWindow::on_chkBoxHeaderV_clicked(bool checked)
{
    // 根据复选框状态设置垂直表头可见性
    ui->tableInfo->verticalHeader()->setVisible(checked);
}

void MainWindow::on_chkBoxRowColor_clicked(bool checked)
{
    // 根据复选框状态设置交替行颜色
    ui->tableInfo->setAlternatingRowColors(checked);
}

void MainWindow::on_rBtnSelectItem_clicked()
{
    // 设置选择行为为按单元格选择
    ui->tableInfo->setSelectionBehavior(QAbstractItemView::SelectItems);
}

void MainWindow::on_rBtnSelectRow_clicked()
{
    // 设置选择行为为按整行选择
    ui->tableInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::on_btnReadToEdit_clicked()
{
    // 清空textEdit控件的内容
    ui->textEdit->clear();

    // 循环读取表格中的每一行数据，并将其格式化后添加到textEdit中
    for (int i = 0; i < ui->tableInfo->rowCount(); i++) {
        QString str = QString::asprintf("第 %d 行： ", i + 1);
        for (int j = 0; j < ui->tableInfo->columnCount() - 1; j++) {
            QTableWidgetItem *item = ui->tableInfo->item(i, j);
            str += item->text() + "   ";
        }

        // 处理“是否党员”这一列的数据
        QTableWidgetItem *item = ui->tableInfo->item(i, colPartyM);
        str += (item->checkState() == Qt::Checked) ? "党员" : "群众";

        // 将处理后的字符串添加到textEdit中
        ui->textEdit->appendPlainText(str);
    }
}

void MainWindow::on_tableInfo_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    Q_UNUSED(previousRow);
    Q_UNUSED(previousColumn);

    // 获取当前单元格的QTableWidgetItem指针
    QTableWidgetItem *item = ui->tableInfo->item(currentRow, currentColumn);
    if (!item)
        return;

    // 显示当前单元格的坐标
    labCellIndex->setText(QString::asprintf("当前单元格坐标：%d 行，%d 列", currentRow, currentColumn));

    // 显示当前单元格的类型
    int cellType = item->type();
    labCellType->setText(QString::asprintf("当前单元格类型：%d", cellType));

    // 获取并显示当前行第一列（姓名）对应的学生ID
    item = ui->tableInfo->item(currentRow, MainWindow::colName);
    uint ID = item->data(Qt::UserRole).toUInt();
    labStudID->setText(QString::asprintf("学生ID：%d", ID));
}

void MainWindow::on_btnInsertRow_clicked()
{
    // 在当前选定行位置插入新行
    int curRow = ui->tableInfo->currentRow();
    ui->tableInfo->insertRow(curRow);

    // 为新行创建并设置单元格
    createItemsARow(curRow, "新学生", "男", QDate::fromString("2002-10-1", "yyyy-M-d"), "苗族", true, 80);
}

void MainWindow::on_btnAppendRow_clicked()
{
    // 在最后一行之后追加新行
    int curRow = ui->tableInfo->rowCount();
    ui->tableInfo->insertRow(curRow);

    // 为新行创建并设置单元格
    createItemsARow(curRow, "新生", "女", QDate::fromString("2002-6-5", "yyyy-M-d"), "满族", false, 76);
}

void MainWindow::on_btnDelCurRow_clicked()
{
    // 删除当前选定行
    int curRow = ui->tableInfo->currentRow();
    ui->tableInfo->removeRow(curRow);
}

void MainWindow::on_btnAutoHeght_clicked()
{
    // 自动调整所有行的高度以适应内容
    ui->tableInfo->resizeRowsToContents();
}

void MainWindow::on_btnAutoWidth_clicked()
{
    // 自动调整所有列的宽度以适应内容
    ui->tableInfo->resizeColumnsToContents();
}

// 辅助函数：为指定行创建并设置所有单元格
void MainWindow::createItemsARow(int rowNo, QString name, QString sex, QDate birth, QString nation, bool isPM, int score)
{
    uint studID = 202105000;  // 学号基数
    studID += rowNo;  // 计算学号

    // 创建并设置“姓名”单元格
    QTableWidgetItem *item = new QTableWidgetItem(name, MainWindow::ctName);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    item->setData(Qt::UserRole, QVariant(studID));  // 存储学号作为用户角色数据
    ui->tableInfo->setItem(rowNo, MainWindow::colName, item);

    // 创建并设置“性别”单元格
    QIcon icon;
    if (sex == "男")
        icon.addFile(":/images/icons/boy.ico");
    else
        icon.addFile(":/images/icons/girl.ico");

    item = new QTableWidgetItem(sex, MainWindow::ctSex);
    item->setIcon(icon);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    Qt::ItemFlags flags = Qt::ItemIsSelectable | Qt::ItemIsEnabled;
    item->setFlags(flags);
    ui->tableInfo->setItem(rowNo, MainWindow::colSex, item);

    // 创建并设置“出生日期”单元格
    QString str = birth.toString("yyyy-MM-dd");
    item = new QTableWidgetItem(str, MainWindow::ctBirth);
    item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    ui->tableInfo->setItem(rowNo, MainWindow::colBirth, item);

    // 创建并设置“民族”单元格
    item = new QTableWidgetItem(nation, MainWindow::ctNation);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableInfo->setItem(rowNo, MainWindow::colNation, item);

    // 创建并设置“是否党员”单元格
    item = new QTableWidgetItem("党员", MainWindow::ctPartyM);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    flags = Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
    item->setFlags(flags);
    if (isPM)
        item->setCheckState(Qt::Checked);
    else
        item->setCheckState(Qt::Unchecked);
    item->setBackground(QBrush(Qt::yellow));
    ui->tableInfo->setItem(rowNo, MainWindow::colPartyM, item);

    // 创建并设置“分数”单元格
    str.setNum(score);
    item = new QTableWidgetItem(str, MainWindow::ctScore);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableInfo->setItem(rowNo, MainWindow::colScore, item);
}








