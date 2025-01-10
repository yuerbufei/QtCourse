#ifndef DOCTOREDITVIEW_H
#define DOCTOREDITVIEW_H

#include <QWidget>

namespace Ui {
class DoctorEditView;
}

class DoctorEditView : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorEditView(QWidget *parent = nullptr,int index = 0);
    ~DoctorEditView();

private:
    Ui::DoctorEditView *ui;
};

#endif // DOCTOREDITVIEW_H
