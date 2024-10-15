#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QKeyEvent>
#include <QMap>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // MainWindow 构造函数
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString operand;
    QString opcode;
    QStack<QString> operands;
    QStack<QString> opcodes;
    QMap<int, QPushButton *> digitBtns;

    QString calculation(bool *ok=NULL);

private slots:
    void btnNumClicked();

    void btnTwoOperatorClicked();

    void btnOneOperatorClicked();

    void on_btnPeriod_clicked();

    void on_btnDelete_clicked();

    void on_btnClear_clicked();

    void on_btnClearAll_clicked();

    void on_btnEqual_clicked();

    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    void clicked();

    QString currentExpression;  // 用于保存当前的表达式
};
#endif // MAINWINDOW_H
