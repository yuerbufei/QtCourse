#ifndef MEDICALEDITVIEW_H
#define MEDICALEDITVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>

namespace Ui {
class MedicalEditView;
}

class MedicalEditView : public QWidget
{
    Q_OBJECT

public:
    explicit MedicalEditView(QWidget *parent = nullptr,int index = 0);
    ~MedicalEditView();

private slots:
    void on_btnCancelMedicalEdit_clicked();
    void on_btnSaveMedicalEdit_clicked();

signals:
    void goPreviousView();

private:
    Ui::MedicalEditView *ui;
    QDataWidgetMapper *dataMapper;
};

#endif // MEDICALEDITVIEW_H
