#include "replacedialog.h"
#include "ui_replacedialog.h"

#include <QMessageBox>  // 用于显示消息框

ReplaceDialog::ReplaceDialog(QWidget *parent, QTextEdit * qTextEdit)
    : QDialog(parent),
    ui(new Ui::ReplaceDialog)
{   
    ui->setupUi(this);

    textEdit = qTextEdit;
}

ReplaceDialog::~ReplaceDialog()
{
    delete ui;
}

// 当“查找下一个”按钮被点击时调用
void ReplaceDialog::on_btnFindNext_clicked()
{
    // 获取查找文本
    QString target = ui->searchText_2->text();

    if (target.isEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("请输入要查找的文本。"));
        return;
    }

    // 获取当前的 QTextCursor
    QTextCursor cursor = textEdit->textCursor();

    // 检查是否区分大小写
    caseSensitive = ui->cbCaseSensetive->isChecked();

    // 检查方向（向上还是向下）
    searchUp = ui->rbUp->isChecked();

    // 计算查找标志
    QTextDocument::FindFlags flags = caseSensitive ? QTextDocument::FindCaseSensitively : QTextDocument::FindFlag(0);
    if (searchUp) {
        flags |= QTextDocument::FindBackward;
    }

    // 执行查找操作
    bool found = textEdit->find(target, flags);

    if (found) {
        // 如果找到了，更新光标位置
        cursor = textEdit->textCursor();
        textEdit->setTextCursor(cursor);
        currentTarget = target;
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
            currentTarget = target;
        } else {
            // 如果仍然没有找到，显示提示信息
            QMessageBox::information(this, tr("提示"), tr("未找到指定文本。"));
        }
    }
}

// 当“替换”按钮被点击时调用
void ReplaceDialog::on_btnReplace_clicked()
{
    if (currentTarget.isEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("请先查找目标文本。"));
        return;
    }

    // 获取当前的 QTextCursor
    QTextCursor cursor = textEdit->textCursor();

    // 获取替换文本
    QString replacement = ui->searchText->text();

    // 替换当前选中的文本
    cursor.insertText(replacement);
    textEdit->setTextCursor(cursor);

    // 重新查找下一个
    on_btnFindNext_clicked();
}

// 当“全部替换”按钮被点击时调用
void ReplaceDialog::on_btnReplaceAll_clicked()
{
    if (currentTarget.isEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("请先查找目标文本。"));
        return;
    }

    // 获取查找文本和替换文本
    QString target = currentTarget;
    QString replacement = ui->searchText->text();

    // 获取当前的 QTextCursor
    QTextCursor cursor = textEdit->textCursor();

    // 计算查找标志
    QTextDocument::FindFlags flags = caseSensitive ? QTextDocument::FindCaseSensitively : QTextDocument::FindFlag(0);

    // 从文档开头开始查找并替换
    cursor.movePosition(QTextCursor::Start);
    textEdit->setTextCursor(cursor);

    int count = 0;
    while (textEdit->find(target, flags)) {
        cursor = textEdit->textCursor();
        cursor.insertText(replacement);
        count++;
    }

    // 显示替换结果
    QMessageBox::information(this, tr("提示"), tr("已替换 %1 处。").arg(count));
}

// 当“取消”按钮被点击时调用
void ReplaceDialog::on_btnCancel_clicked()
{
    // 关闭对话框
    this->close();
}
