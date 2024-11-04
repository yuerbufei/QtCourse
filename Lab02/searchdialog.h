#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QTextEdit>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr,QTextEdit * qTextEdit = nullptr);
    ~SearchDialog();

private slots:
    void on_btnFindNext_clicked();  // 当“查找下一个”按钮被点击时调用
    void on_btnCancel_clicked();    // 当“取消”按钮被点击时调用

private:
    Ui::SearchDialog *ui;  // UI 组件
    QTextEdit * textEdit;   // 存储 QTextEdit 控件的指针
};

#endif // SEARCHDIALOG_H
