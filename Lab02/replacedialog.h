#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>
#include <QTextEdit>

namespace Ui {
class ReplaceDialog;
}

class ReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReplaceDialog(QWidget *parent = nullptr,QTextEdit * qTextEdit = nullptr);
    ~ReplaceDialog();

private slots:
    void on_btnFindNext_clicked();      // 当“查找下一个”按钮被点击时调用
    void on_btnReplace_clicked();       // 当“替换”按钮被点击时调用
    void on_btnReplaceAll_clicked();    // 当“全部替换”按钮被点击时调用
    void on_btnCancel_clicked();        // 当“取消”按钮被点击时调用

private:
    Ui::ReplaceDialog *ui;
    QTextEdit * textEdit;                // 存储 QTextEdit 控件的指针
    QString currentTarget;              // 当前查找的目标文本
    QString currentReplacement;          // 当前替换的文本
    bool caseSensitive;                 // 是否区分大小写
    bool searchUp;                      // 是否向上查找
};

#endif // REPLACEDIALOG_H
