#ifndef RECORDVIEW_H
#define RECORDVIEW_H

#include <QWidget>

namespace Ui {
class RecordView;
}

class RecordView : public QWidget
{
    Q_OBJECT

public:
    explicit RecordView(QWidget *parent = nullptr);
    ~RecordView();

private slots:
    void on_btnFind_clicked();
    void on_btnIncrease_clicked();
    void on_btnDelete_clicked();
    void on_btnModify_clicked();

signals:
    void goRecordEditView();

private:
    Ui::RecordView *ui;
};

#endif // RECORDVIEW_H
