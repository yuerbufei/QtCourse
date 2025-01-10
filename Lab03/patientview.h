#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QWidget>

namespace Ui {
class PatientView;
}

class PatientView : public QWidget
{
    Q_OBJECT

public:
    explicit PatientView(QWidget *parent = nullptr);
    ~PatientView();

private slots:
    void on_btnFind_clicked();
    void on_btnIncrease_clicked();
    void on_btnDelete_clicked();
    void on_btnModify_clicked();

signals:
    void goPatientEditview();

private:
    Ui::PatientView *ui;
};

#endif // PATIENTVIEW_H
