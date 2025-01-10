#ifndef DOCTORVIEW_H
#define DOCTORVIEW_H

#include <QWidget>

namespace Ui {
class DoctorView;
}

class DoctorView : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorView(QWidget *parent = nullptr);
    ~DoctorView();

signals:
    void goDoctorEditView(int index);

private slots:
    void on_btnDelete_clicked();
    void on_btnFind_clicked();
    void on_btnIncrease_clicked();
    void on_btnModify_clicked();

private:
    Ui::DoctorView *ui;
};

#endif // DOCTORVIEW_H
