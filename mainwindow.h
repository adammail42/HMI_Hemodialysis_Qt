#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>

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

    void updateValue();

    QImage convertToRed(const QImage &image);

    void on_button_valve_v55_clicked(bool checked);

    void on_button_valve_ufp_clicked(bool checked);

    void on_button_valve_v19_clicked(bool checked);

    void on_button_valve_v9a_clicked(bool checked);

    void on_button_valve_v9b_clicked(bool checked);

    void on_button_valve_elisio_clicked(bool checked);

    void on_button_valve_fs2_clicked(bool checked);

    void on_button_valve_v10_clicked(bool checked);

    void on_button_valve_v4_clicked(bool checked);

    void on_button_valve_v57_clicked(bool checked);

    void on_button_valve_v17_clicked(bool checked);

    void on_button_valve_v56_clicked(bool checked);

    void on_button_valve_v12_clicked(bool checked);

    void on_button_valve_fs3_clicked(bool checked);

    void on_button_valve_fsw_clicked(bool checked);

    void on_button_valve_p2_clicked(bool checked);

    void on_button_valve_v35_clicked(bool checked);

    void on_button_valve_v6a_clicked(bool checked);

    void on_button_valve_v6b_clicked(bool checked);


    void on_button_valve_v5a_clicked(bool checked);

    void on_button_valve_v5b_clicked(bool checked);

    void on_button_valve_v7a_clicked(bool checked);

    void on_button_valve_v7b_clicked(bool checked);

    void on_button_valve_v8a_clicked(bool checked);

    void on_button_valve_v8b_clicked(bool checked);

    void on_button_valve_v1_clicked(bool checked);

    void on_button_valve_h1_clicked(bool checked);

    void on_button_valve_h2_clicked(bool checked);

    void on_button_valve_p1_clicked(bool checked);

    void on_button_valve_fs1_clicked(bool checked);

    void on_button_valve_v21_clicked(bool checked);

    void on_button_valve_v34_clicked(bool checked);

    void on_button_valve_p4_clicked(bool checked);

    void on_button_valve_v25_clicked(bool checked);

    void on_button_valve_v11_clicked(bool checked);

    void on_button_valve_v33_clicked(bool checked);

    void on_button_valve_p3_clicked(bool checked);

    void on_button_valve_v43_clicked(bool checked);

    void on_button_valve_v45_clicked(bool checked);

    void on_button_valve_v46_clicked(bool checked);

private:
    bool firstTimeShown = 1;
    Ui::MainWindow *ui;
    QTimer *updateTimer;
    QImage redImage;
    QPixmap oriPixmap, redPixmap;
    QImage redImageRotate;
    QPixmap oriPixmapRotate, redPixmapRotate;
    QImage redImageCircle;
    QPixmap oriPixmapCircle, redPixmapCircle;

};
#endif // MAINWINDOW_H
