#include "searchdialog.h"
#include "ui_searchdialog.h"

#include <QTextEdit>
#include <QMessageBox>  // 用于显示消息框

SearchDialog::SearchDialog(QWidget *parent,QTextEdit * qTextEdit)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
{
    ui->setupUi(this);

    textEdit = qTextEdit;
}

SearchDialog::~SearchDialog()
{
    delete ui;
}


// 当“查找下一个”按钮被点击时调用
void SearchDialog::on_btnFindNext_clicked()
{
    // 获取查找文本
    QString target = ui->searchText->text();

    if (target.isEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("请输入要查找的文本。"));
        return;
    }

    // 获取当前的 QTextCursor
    QTextCursor cursor = textEdit->textCursor();

    // 检查是否区分大小写
    bool caseSensitive = ui->cbCaseSensetive->isChecked();

    // 检查方向（向上还是向下）
    bool searchUp = ui->rbUp->isChecked();

    // 计算查找标志
    QTextDocument::FindFlags flags = caseSensitive ? QTextDocument::FindCaseSensitively : QTextDocument::FindFlag(0);
    if (searchUp) {
        flags |= QTextDocument::FindBackward;
    }

    // 保存当前光标位置
    int currentPosition = cursor.position();

    // 执行查找操作
    bool found = textEdit->find(target, flags);

    if (found) {
        // 如果找到了，更新光标位置
        cursor = textEdit->textCursor();
        textEdit->setTextCursor(cursor);
    } else {
        // 如果没有找到，尝试从文档开头/结尾重新查找
        if (searchUp) {
            // 向上查找，从文档开头开始
            cursor.movePosition(QTextCursor::Start);
            textEdit->setTextCursor(cursor);
            found = textEdit->find(target, flags);
        } else {
            // 向下查找，从文档结尾开始
            cursor.movePosition(QTextCursor::End);
            textEdit->setTextCursor(cursor);
            found = textEdit->find(target, flags);
        }

        if (found) {
            cursor = textEdit->textCursor();
            textEdit->setTextCursor(cursor);
        } else {
            // 如果仍然没有找到，显示提示信息
            QMessageBox::information(this, tr("提示"), tr("未找到指定文本。"));
        }
    }
}

// 当“取消”按钮被点击时调用
void SearchDialog::on_btnCancel_clicked()
{
    // 关闭对话框
    this->close();
}


