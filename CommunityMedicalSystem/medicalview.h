#ifndef MEDICALVIEW_H
#define MEDICALVIEW_H

#include <QWidget>

namespace Ui {
class MedicalView;
}

class MedicalView : public QWidget
{
    Q_OBJECT

public:
    explicit MedicalView(QWidget *parent = nullptr);
    ~MedicalView();

private slots:
    void on_btnDelete_clicked();
    void on_btnFind_clicked();
    void on_btnIncrease_clicked();
    void on_btnModify_clicked();

signals:
    void goMedicalEditView();

private:
    Ui::MedicalView *ui;
};

#endif // MEDICALVIEW_H
