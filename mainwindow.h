#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_3_clicked(bool checked);

    void on_pushButton_4_clicked(bool checked);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void updateValue();



    void on_pushButton_5_clicked(bool checked);

    void on_pushButton_8_clicked(bool checked);

    void on_pushButton_6_clicked(bool checked);

    void on_pushButton_7_clicked(bool checked);

    void on_spinBox_5_valueChanged(int arg1);

    void on_spinBox_6_valueChanged(int arg1);

    void on_spinBox_7_valueChanged(int arg1);

    void on_spinBox_8_valueChanged(int arg1);

    void on_pushButton_9_clicked(bool checked);

    void on_pushButton_10_clicked(bool checked);

    void on_pushButton_11_clicked(bool checked);

    void on_pushButton_12_clicked(bool checked);

    void on_spinBox_9_valueChanged(int arg1);

    void on_spinBox_10_valueChanged(int arg1);

    void on_spinBox_11_valueChanged(int arg1);

    void on_spinBox_12_valueChanged(int arg1);

    void on_tabWidget_2_currentChanged(int index);

    void on_tabWidget_3_currentChanged(int index);

    void on_tabWidget_4_currentChanged(int index);

    void on_buttonStart_clicked(bool checked);

    void on_buttonValve_1_clicked(bool checked);


    void on_buttonValve_2_clicked(bool checked);

    void on_buttonValve_3_clicked(bool checked);

    void on_buttonValve_4_clicked(bool checked);

    void on_buttonValve_5_clicked(bool checked);

    void on_buttonValve_6_clicked(bool checked);

    void on_buttonValve_7_clicked(bool checked);

    void on_buttonValve_8_clicked(bool checked);

    void on_buttonValve_9_clicked(bool checked);

    void on_buttonValve_10_clicked(bool checked);

    void on_buttonValve_11_clicked(bool checked);

    void on_buttonValve_12_clicked(bool checked);

    void on_buttonValve_13_clicked(bool checked);

    void on_buttonValve_14_clicked(bool checked);


    void on_buttonValve_15_clicked(bool checked);

    void on_buttonValve_16_clicked(bool checked);

    void on_buttonValve_17_clicked(bool checked);

    void on_buttonValve_18_clicked(bool checked);

    void on_buttonValve_19_clicked(bool checked);

    void on_buttonValve_20_clicked(bool checked);

    void on_buttonValve_21_clicked(bool checked);

    void on_buttonValve_22_clicked(bool checked);

    void on_buttonValve_23_clicked(bool checked);

    void on_buttonValve_24_clicked(bool checked);

    void on_buttonValve_25_clicked(bool checked);

    void on_buttonValve_26_clicked(bool checked);

    void on_buttonValve_27_clicked(bool checked);

    void on_buttonValve_28_clicked(bool checked);

    void on_buttonValve_29_clicked(bool checked);

    void on_buttonValve_30_clicked(bool checked);

    void on_buttonValve_31_clicked(bool checked);

    void on_buttonValve_32_clicked(bool checked);

    void on_setpointMotorPeristaltik_valueChanged(int arg1);

    void on_setpointMotorDAC1_valueChanged(int arg1);

    void on_setpointMotorDAC2_valueChanged(int arg1);

    void on_setpointMotorPump1_valueChanged(int arg1);

    void on_setpointMotorPump2_valueChanged(int arg1);

    void on_setpointMotorPump3_valueChanged(int arg1);

    void on_setpointMotorStepper_valueChanged(int arg1);

    void on_tabWidget_5_currentChanged(int index);

    void on_tabWidget_6_currentChanged(int index);

    void on_tabWidget_7_currentChanged(int index);

    void on_tabWidget_1_currentChanged(int index);

private:
    bool firstTimeShown;
    Ui::MainWindow *ui;
    QTimer *updateTimer;

};
#endif // MAINWINDOW_H
