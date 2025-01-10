#ifndef RECORDEDITVIEW_H
#define RECORDEDITVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>

namespace Ui {
class RecordEditView;
}

class RecordEditView : public QWidget
{
    Q_OBJECT

public:
    explicit RecordEditView(QWidget *parent = nullptr,int index = 0);
    ~RecordEditView();


signals:
    void goPreviousView();

private slots:
    void on_btnCancelRecordEdit_clicked();
    void on_btnSaveRecordEdit_clicked();

private:
    Ui::RecordEditView *ui;
    QDataWidgetMapper *dataMapper; // 数据映射
};

#endif // RECORDEDITVIEW_H
