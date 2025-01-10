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
    void goDoctorEditView();

private:
    Ui::DoctorView *ui;
};

#endif // DOCTORVIEW_H
