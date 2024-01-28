#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "variable.h"
#include "QTimer"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Tab Widget to index 0
    for (int i = 1; i <= 7; ++i) {
        QString tabWidgetObjectName = QString("tabWidget_%1").arg(i);
        QTabWidget* currentTabWidget = findChild<QTabWidget*>(tabWidgetObjectName);

        if (currentTabWidget) {
            // Set the current tab index to 0 (the first tab)
            currentTabWidget->setCurrentIndex(0);
        } else {
            // Handle the case where the tab widget with the specified name is not found
            qDebug() << "Tab widget not found: " << tabWidgetObjectName;
        }
    }
    // Create a timer and connect its timeout signal to the updateValue slot
    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, MainWindow::updateValue);

    // Set the timer interval (in milliseconds)
    updateTimer->start(500); // Update the value every 1000 milliseconds (1 second)

    //Name TextLabel Display Variable Prep Mode
    ui-> label   ->setText(QString::fromStdString(prep_mode_display_text_label[0]));
    ui-> label_2 ->setText(QString::fromStdString(prep_mode_display_text_label[1]));
    ui-> label_3 ->setText(QString::fromStdString(prep_mode_display_text_label[2]));
    ui-> label_5 ->setText(QString::fromStdString(prep_mode_display_text_label[3]));
    ui-> label_4 ->setText(QString::fromStdString(prep_mode_display_text_label[4]));
    ui-> label_6 ->setText(QString::fromStdString(prep_mode_display_text_label[5]));
    ui-> label_7 ->setText(QString::fromStdString(prep_mode_display_text_label[6]));
    ui-> label_8 ->setText(QString::fromStdString(prep_mode_display_text_label[7]));

    //Name TextLabel Output Variable Prep Mode
    ui-> pushButton   -> setText(QString::fromStdString(prep_mode_output_text_label[0]));
    ui-> pushButton_2 -> setText(QString::fromStdString(prep_mode_output_text_label[1]));
    ui-> pushButton_3 -> setText(QString::fromStdString(prep_mode_output_text_label[2]));
    ui-> pushButton_4 -> setText(QString::fromStdString(prep_mode_output_text_label[3]));

    //Name TextLabel Input Variable Prep Mode
    ui-> label_9  ->setText(QString::fromStdString(prep_mode_input_text_label[0]));
    ui-> label_10 ->setText(QString::fromStdString(prep_mode_input_text_label[1]));
    ui-> label_11 ->setText(QString::fromStdString(prep_mode_input_text_label[2]));
    ui-> label_12 ->setText(QString::fromStdString(prep_mode_input_text_label[3]));

    //Name TextLabel Display Variable Rinse Mode
    ui-> label_13 ->setText(QString::fromStdString(rinse_mode_display_text_label[0]));
    ui-> label_14 ->setText(QString::fromStdString(rinse_mode_display_text_label[1]));
    ui-> label_15 ->setText(QString::fromStdString(rinse_mode_display_text_label[2]));
    ui-> label_16 ->setText(QString::fromStdString(rinse_mode_display_text_label[3]));
    ui-> label_17 ->setText(QString::fromStdString(rinse_mode_display_text_label[4]));
    ui-> label_18 ->setText(QString::fromStdString(rinse_mode_display_text_label[5]));
    ui-> label_19 ->setText(QString::fromStdString(rinse_mode_display_text_label[6]));
    ui-> label_20 ->setText(QString::fromStdString(rinse_mode_display_text_label[7]));

    //Name TextLabel Output Variable Rinse Mode
    ui-> pushButton_5 -> setText(QString::fromStdString(rinse_mode_output_text_label[0]));
    ui-> pushButton_6 -> setText(QString::fromStdString(rinse_mode_output_text_label[1]));
    ui-> pushButton_7 -> setText(QString::fromStdString(rinse_mode_output_text_label[2]));
    ui-> pushButton_8 -> setText(QString::fromStdString(rinse_mode_output_text_label[3]));

    //Name TextLabel Input Variable Rinse Mode
    ui-> label_21 ->setText(QString::fromStdString(rinse_mode_input_text_label[0]));
    ui-> label_22 ->setText(QString::fromStdString(rinse_mode_input_text_label[1]));
    ui-> label_23 ->setText(QString::fromStdString(rinse_mode_input_text_label[2]));
    ui-> label_24 ->setText(QString::fromStdString(rinse_mode_input_text_label[3]));

    //Name TextLabel Display Variable Dialys Mode
    ui-> label_25 ->setText(QString::fromStdString(dialys_mode_display_text_label[0]));
    ui-> label_26 ->setText(QString::fromStdString(dialys_mode_display_text_label[1]));
    ui-> label_27 ->setText(QString::fromStdString(dialys_mode_display_text_label[2]));
    ui-> label_28 ->setText(QString::fromStdString(dialys_mode_display_text_label[3]));
    ui-> label_29 ->setText(QString::fromStdString(dialys_mode_display_text_label[4]));
    ui-> label_30 ->setText(QString::fromStdString(dialys_mode_display_text_label[5]));
    ui-> label_31 ->setText(QString::fromStdString(dialys_mode_display_text_label[6]));
    ui-> label_32 ->setText(QString::fromStdString(dialys_mode_display_text_label[7]));

    //Name TextLabel Output Variable Dialys Mode
    ui-> pushButton_9  -> setText(QString::fromStdString(dialys_mode_output_text_label[0]));
    ui-> pushButton_10 -> setText(QString::fromStdString(dialys_mode_output_text_label[1]));
    ui-> pushButton_11 -> setText(QString::fromStdString(dialys_mode_output_text_label[2]));
    ui-> pushButton_12 -> setText(QString::fromStdString(dialys_mode_output_text_label[3]));

    //Name TextLabel Input Variable Dialys Mode
    ui-> label_33 ->setText(QString::fromStdString(dialys_mode_input_text_label[0]));
    ui-> label_34 ->setText(QString::fromStdString(dialys_mode_input_text_label[1]));
    ui-> label_35 ->setText(QString::fromStdString(dialys_mode_input_text_label[2]));
    ui-> label_36 ->setText(QString::fromStdString(dialys_mode_input_text_label[3]));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent* event)
{
    QMainWindow::showEvent(event);
    if(firstTimeShown)
    {
       firstTimeShown = false;
       showFullScreen();
    }
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    if(prep_mode_output[0] == 0)
    {
        prep_mode_output[0] = 1;
        ui->pushButton->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        prep_mode_output[0] = 0;
        ui->pushButton->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    // ui->label_13->setText(QString::fromStdString(std::to_string(prep_mode_display[0])));

}

void MainWindow::on_pushButton_2_clicked(bool checked)
{
    if(prep_mode_output[1] == 0)
    {
        prep_mode_output[1] = 1;
        ui->pushButton_2->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        prep_mode_output[1] = 0;
        ui->pushButton_2->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}

void MainWindow::on_pushButton_3_clicked(bool checked)
{
    if(prep_mode_output[2] == 0)
    {
        prep_mode_output[2] = 1;
        ui->pushButton_3->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        prep_mode_output[2] = 0;
        ui->pushButton_3->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_pushButton_4_clicked(bool checked)
{
    if(prep_mode_output[3] == 0)
    {
        prep_mode_output[3] = 1;
        ui->pushButton_4->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        prep_mode_output[3] = 0;
        ui->pushButton_4->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}



void MainWindow::on_spinBox_valueChanged(int arg1)
{
    prep_mode_input[0] = arg1;
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    prep_mode_input[1] = arg1;
}

void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    prep_mode_input[2] = arg1;
}

void MainWindow::on_spinBox_4_valueChanged(int arg1)
{
    prep_mode_input[3] = arg1;
}

void MainWindow::updateValue()
{
    //Value Display Header
    if(index_H1 == 0)
    {
        index_H2 = index_H2_prep;
        index_H3 = 0;
    }
    else if (index_H1 == 1)
    {
        index_H2 = index_H2_rinse;
        index_H3 = 0;
    }
    else if (index_H1 == 2)
    {
        index_H2 = index_H2_dialys;
        index_H3 = 0;
    }
    else if(index_H1 == 3)
    {
        index_H2 = index_H2_maintenance;
        if(index_H2 == 0)
        {
            index_H3 = index_H3_maintenance_1;
        }
        else if(index_H2 == 1)
        {
            index_H3 = index_H3_maintenance_2;
        }
    }
    ui-> labelIndexH1 -> setText(QString::fromStdString(std::to_string(index_H1)));
    ui-> labelIndexH2 -> setText(QString::fromStdString(std::to_string(index_H2)));
    ui-> labelIndexH3 -> setText(QString::fromStdString(std::to_string(index_H3)));

    //Value Display Variable Prep Mode
    ui-> lcdNumber   ->display(prep_mode_display[0]);
    ui-> lcdNumber_2 ->display(prep_mode_display[1]);
    ui-> lcdNumber_3 ->display(prep_mode_display[2]);
    ui-> lcdNumber_4 ->display(prep_mode_display[3]);
    ui-> lcdNumber_5 ->display(prep_mode_display[4]);
    ui-> lcdNumber_6 ->display(prep_mode_display[5]);
    ui-> lcdNumber_7 ->display(prep_mode_display[6]);
    ui-> lcdNumber_8 ->display(prep_mode_display[7]);

    //Value Display Variable Rinse Mode
    ui-> lcdNumber_9  ->display(rinse_mode_display[0]);
    ui-> lcdNumber_10 ->display(rinse_mode_display[1]);
    ui-> lcdNumber_11 ->display(rinse_mode_display[2]);
    ui-> lcdNumber_12 ->display(rinse_mode_display[3]);
    ui-> lcdNumber_13 ->display(rinse_mode_display[4]);
    ui-> lcdNumber_14 ->display(rinse_mode_display[5]);
    ui-> lcdNumber_15 ->display(rinse_mode_display[6]);
    ui-> lcdNumber_16 ->display(rinse_mode_display[7]);

    //Value Display Variable Dialys Mode
    ui-> lcdNumber_17 ->display(dialys_mode_display[0]);
    ui-> lcdNumber_18 ->display(dialys_mode_display[1]);
    ui-> lcdNumber_19 ->display(dialys_mode_display[2]);
    ui-> lcdNumber_20 ->display(dialys_mode_display[3]);
    ui-> lcdNumber_21 ->display(dialys_mode_display[4]);
    ui-> lcdNumber_22 ->display(dialys_mode_display[5]);
    ui-> lcdNumber_23 ->display(dialys_mode_display[6]);
    ui-> lcdNumber_24 ->display(dialys_mode_display[7]);

    //Maintenance Digital Input
    if(maintenance_digital_input[0] == 0)
    {
        ui->input_1->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_1->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[1] == 0)
    {
        ui->input_2->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_2->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[2] == 0)
    {
        ui->input_3->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_3->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[3] == 0)
    {
        ui->input_4->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_4->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[4] == 0)
    {
        ui->input_5->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_5->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[5] == 0)
    {
        ui->input_6->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_6->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[6] == 0)
    {
        ui->input_7->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_7->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[7] == 0)
    {
        ui->input_8->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_8->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[8] == 0)
    {
        ui->input_9->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_9->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[9] == 0)
    {
        ui->input_10->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_10->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[10] == 0)
    {
        ui->input_11->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_11->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[11] == 0)
    {
        ui->input_12->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_12->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[12] == 0)
    {
        ui->input_13->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_13->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[13] == 0)
    {
        ui->input_14->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_14->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[14] == 0)
    {
        ui->input_15->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_15->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[15] == 0)
    {
        ui->input_16->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_16->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[16] == 0)
    {
        ui->input_17->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_17->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[17] == 0)
    {
        ui->input_18->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_18->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[18] == 0)
    {
        ui->input_19->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_19->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[19] == 0)
    {
        ui->input_20->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_20->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[20] == 0)
    {
        ui->input_21->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_21->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[21] == 0)
    {
        ui->input_22->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_22->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[22] == 0)
    {
        ui->input_23->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_23->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[23] == 0)
    {
        ui->input_24->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_24->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[24] == 0)
    {
        ui->input_25->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_25->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[25] == 0)
    {
        ui->input_26->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_26->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[27] == 0)
    {
        ui->input_28->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_28->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[28] == 0)
    {
        ui->input_29->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_29->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[29] == 0)
    {
        ui->input_30->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_30->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[30] == 0)
    {
        ui->input_31->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_31->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_digital_input[31] == 0)
    {
        ui->input_32->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui->input_32->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    //Maintenance Num Display 1

    // QString labelText = QString("Val 1 = %1").arg(maintenance_num_display_1[0]);
    // ui->numDisplay_1->setText(labelText);

    for (int i = 0; i < 32; ++i) {
        int16_t value = maintenance_num_display_1[i];  // Replace with your actual array of integer values
        QString labelText = QString("Val %1 = %2").arg(i + 1).arg(value);
        QString numDisplayObjectName = QString("numDisplay_%1").arg(i + 1);
        QLabel* numDisplayWidget = findChild<QLabel*>(numDisplayObjectName);

        if (numDisplayWidget) {
            numDisplayWidget->setText(labelText);
        } else {
            // Handle the case where the widget with the specified name is not found
            qDebug() << "Widget not found: " << numDisplayObjectName;
        }
    }

    //Maintenance Num Display 2
    for (int i = 0; i < 32; ++i) {
        int16_t value = maintenance_num_display_2[i];  // Replace with your actual array of integer values
        QString labelText = QString("Val %1 = %2").arg(i + 1).arg(value);
        QString numDisplayObjectName = QString("numDisplay_2_%1").arg(i + 1);
        QLabel* numDisplayWidget = findChild<QLabel*>(numDisplayObjectName);

        if (numDisplayWidget) {
            numDisplayWidget->setText(labelText);
        } else {
            // Handle the case where the widget with the specified name is not found
            qDebug() << "Widget not found: " << numDisplayObjectName;
        }
    }

    //Maintenance Konfigurasi Motor
    ui-> realMotorPeristaltik ->display(maintenance_real_motor_peristaltik);
    ui-> realMotorDAC1 -> display(maintenance_real_motor_DAC_1);
    ui-> realMotorDAC2 -> display(maintenance_real_motor_DAC_1);
    ui-> realMotorPump1 -> display(maintenance_real_motor_pump_1);
    ui-> realMotorPump2 -> display(maintenance_real_motor_pump_2);
    ui-> realMotorPump3 -> display(maintenance_real_motor_pump_3);
    ui-> realMotorStepper -> display(maintenance_real_motor_stepper);

    if(maintenance_motor_stepper_injection_status == 0)
    {
        ui-> motorStepper_injectionStatus->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui-> motorStepper_injectionStatus->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

    if(maintenance_motor_stepper_zero_pos_status == 0)
    {
        ui-> motorStepper_zeroPosStatus->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
    else
    {
        ui-> motorStepper_zeroPosStatus->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }

}

void MainWindow::on_pushButton_5_clicked(bool checked)
{
    if(rinse_mode_output[0] == 0)
    {
        rinse_mode_output[0] = 1;
        ui->pushButton_5->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        rinse_mode_output[0] = 0;
        ui->pushButton_5->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_pushButton_6_clicked(bool checked)
{
    if(rinse_mode_output[1] == 0)
    {
        rinse_mode_output[1] = 1;
        ui->pushButton_6->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        rinse_mode_output[1] = 0;
        ui->pushButton_6->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_pushButton_7_clicked(bool checked)
{
    if(rinse_mode_output[2] == 0)
    {
        rinse_mode_output[2] = 1;
        ui->pushButton_7->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        rinse_mode_output[2] = 0;
        ui->pushButton_7->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_pushButton_8_clicked(bool checked)
{
    if(rinse_mode_output[3] == 0)
    {
        rinse_mode_output[3] = 1;
        ui->pushButton_8->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        rinse_mode_output[3] = 0;
        ui->pushButton_8->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_spinBox_5_valueChanged(int arg1)
{
    rinse_mode_input[0] = arg1;

}


void MainWindow::on_spinBox_6_valueChanged(int arg1)
{
    rinse_mode_input[1] = arg1;

}


void MainWindow::on_spinBox_7_valueChanged(int arg1)
{
    rinse_mode_input[2] = arg1;

}


void MainWindow::on_spinBox_8_valueChanged(int arg1)
{
    rinse_mode_input[3] = arg1;

}


void MainWindow::on_pushButton_9_clicked(bool checked)
{
    if(dialys_mode_output[0] == 0)
    {
        dialys_mode_output[0] = 1;
        ui->pushButton_9->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        dialys_mode_output[0] = 0;
        ui->pushButton_9->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_pushButton_10_clicked(bool checked)
{
    if(dialys_mode_output[1] == 0)
    {
        dialys_mode_output[1] = 1;
        ui->pushButton_10->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        dialys_mode_output[1] = 0;
        ui->pushButton_10->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_pushButton_11_clicked(bool checked)
{
    if(dialys_mode_output[2] == 0)
    {
        dialys_mode_output[2] = 1;
        ui->pushButton_11->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        dialys_mode_output[2] = 0;
        ui->pushButton_11->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_pushButton_12_clicked(bool checked)
{
    if(dialys_mode_output[3] == 0)
    {
        dialys_mode_output[3] = 1;
        ui->pushButton_12->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        dialys_mode_output[3] = 0;
        ui->pushButton_12->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_spinBox_9_valueChanged(int arg1)
{
    dialys_mode_input[0] = arg1;
}


void MainWindow::on_spinBox_10_valueChanged(int arg1)
{
    dialys_mode_input[1] = arg1;
}


void MainWindow::on_spinBox_11_valueChanged(int arg1)
{
    dialys_mode_input[2] = arg1;
}


void MainWindow::on_spinBox_12_valueChanged(int arg1)
{
    dialys_mode_input[3] = arg1;
}

void MainWindow::on_tabWidget_1_currentChanged(int index)
{
    index_H1 = index;
}


void MainWindow::on_tabWidget_2_currentChanged(int index)
{
    index_H2_prep = index;
}


void MainWindow::on_tabWidget_3_currentChanged(int index)
{
    index_H2_rinse = index;
}


void MainWindow::on_tabWidget_4_currentChanged(int index)
{
    index_H2_dialys = index;
}

void MainWindow::on_tabWidget_5_currentChanged(int index)
{
    index_H2_maintenance = index;
}

void MainWindow::on_tabWidget_6_currentChanged(int index)
{
    index_H3_maintenance_1 = index;
}

void MainWindow::on_tabWidget_7_currentChanged(int index)
{
    index_H3_maintenance_2 = index;
}

void MainWindow::on_buttonStart_clicked(bool checked)
{
    if(status_machine == 0)
    {
        status_machine = 1;
        ui->buttonStart->setStyleSheet("background-color: #FF0000; color: #ffffff;");
    }
    else
    {
        status_machine = 0;
        ui->buttonStart->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


//Maintenance Tombol Valve


void MainWindow::on_buttonValve_1_clicked(bool checked)
{
    if(maintenance_button_valve[0] == 0)
    {
        maintenance_button_valve[0] = 1;
        ui->buttonValve_1->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[0] = 0;
        ui->buttonValve_1->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_2_clicked(bool checked)
{
    if(maintenance_button_valve[1] == 0)
    {
        maintenance_button_valve[1] = 1;
        ui->buttonValve_2->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[1] = 0;
        ui->buttonValve_2->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_3_clicked(bool checked)
{
    if(maintenance_button_valve[2] == 0)
    {
        maintenance_button_valve[2] = 1;
        ui->buttonValve_3->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[2] = 0;
        ui->buttonValve_3->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_4_clicked(bool checked)
{
    if(maintenance_button_valve[3] == 0)
    {
        maintenance_button_valve[3] = 1;
        ui->buttonValve_4->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[3] = 0;
        ui->buttonValve_4->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_5_clicked(bool checked)
{
    if(maintenance_button_valve[4] == 0)
    {
        maintenance_button_valve[4] = 1;
        ui->buttonValve_5->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[4] = 0;
        ui->buttonValve_5->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_6_clicked(bool checked)
{
    if(maintenance_button_valve[5] == 0)
    {
        maintenance_button_valve[5] = 1;
        ui->buttonValve_6->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[5] = 0;
        ui->buttonValve_6->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_7_clicked(bool checked)
{
    if(maintenance_button_valve[6] == 0)
    {
        maintenance_button_valve[6] = 1;
        ui->buttonValve_7->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[6] = 0;
        ui->buttonValve_7->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_8_clicked(bool checked)
{
    if(maintenance_button_valve[7] == 0)
    {
        maintenance_button_valve[7] = 1;
        ui->buttonValve_8->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[7] = 0;
        ui->buttonValve_8->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_9_clicked(bool checked)
{
    if(maintenance_button_valve[8] == 0)
    {
        maintenance_button_valve[8] = 1;
        ui->buttonValve_9->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[8] = 0;
        ui->buttonValve_9->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_10_clicked(bool checked)
{
    if(maintenance_button_valve[9] == 0)
    {
        maintenance_button_valve[9] = 1;
        ui->buttonValve_10->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[9] = 0;
        ui->buttonValve_10->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_11_clicked(bool checked)
{
    if(maintenance_button_valve[10] == 0)
    {
        maintenance_button_valve[10] = 1;
        ui->buttonValve_11->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[10] = 0;
        ui->buttonValve_11->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_12_clicked(bool checked)
{
    if(maintenance_button_valve[11] == 0)
    {
        maintenance_button_valve[11] = 1;
        ui->buttonValve_12->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[11] = 0;
        ui->buttonValve_12->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_13_clicked(bool checked)
{
    if(maintenance_button_valve[12] == 0)
    {
        maintenance_button_valve[12] = 1;
        ui->buttonValve_13->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[12] = 0;
        ui->buttonValve_13->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_14_clicked(bool checked)
{
    if(maintenance_button_valve[13] == 0)
    {
        maintenance_button_valve[13] = 1;
        ui->buttonValve_14->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[13] = 0;
        ui->buttonValve_14->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_15_clicked(bool checked)
{
    if(maintenance_button_valve[14] == 0)
    {
        maintenance_button_valve[14] = 1;
        ui->buttonValve_15->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[14] = 0;
        ui->buttonValve_15->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_16_clicked(bool checked)
{
    if(maintenance_button_valve[15] == 0)
    {
        maintenance_button_valve[15] = 1;
        ui->buttonValve_16->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[15] = 0;
        ui->buttonValve_16->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_17_clicked(bool checked)
{
    if(maintenance_button_valve[16] == 0)
    {
        maintenance_button_valve[16] = 1;
        ui->buttonValve_17->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[16] = 0;
        ui->buttonValve_17->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_18_clicked(bool checked)
{
    if(maintenance_button_valve[17] == 0)
    {
        maintenance_button_valve[17] = 1;
        ui->buttonValve_18->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[17] = 0;
        ui->buttonValve_18->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_19_clicked(bool checked)
{
    if(maintenance_button_valve[18] == 0)
    {
        maintenance_button_valve[18] = 1;
        ui->buttonValve_19->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[18] = 0;
        ui->buttonValve_19->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_20_clicked(bool checked)
{
    if(maintenance_button_valve[19] == 0)
    {
        maintenance_button_valve[19] = 1;
        ui->buttonValve_20->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[19] = 0;
        ui->buttonValve_20->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_21_clicked(bool checked)
{
    if(maintenance_button_valve[20] == 0)
    {
        maintenance_button_valve[20] = 1;
        ui->buttonValve_21->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[20] = 0;
        ui->buttonValve_21->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_22_clicked(bool checked)
{
    if(maintenance_button_valve[21] == 0)
    {
        maintenance_button_valve[21] = 1;
        ui->buttonValve_22->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[21] = 0;
        ui->buttonValve_22->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_23_clicked(bool checked)
{
    if(maintenance_button_valve[22] == 0)
    {
        maintenance_button_valve[22] = 1;
        ui->buttonValve_23->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[22] = 0;
        ui->buttonValve_23->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_24_clicked(bool checked)
{
    if(maintenance_button_valve[23] == 0)
    {
        maintenance_button_valve[23] = 1;
        ui->buttonValve_24->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[23] = 0;
        ui->buttonValve_24->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_25_clicked(bool checked)
{
    if(maintenance_button_valve[24] == 0)
    {
        maintenance_button_valve[24] = 1;
        ui->buttonValve_25->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[24] = 0;
        ui->buttonValve_25->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_26_clicked(bool checked)
{
    if(maintenance_button_valve[25] == 0)
    {
        maintenance_button_valve[25] = 1;
        ui->buttonValve_26->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[25] = 0;
        ui->buttonValve_26->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_27_clicked(bool checked)
{
    if(maintenance_button_valve[26] == 0)
    {
        maintenance_button_valve[26] = 1;
        ui->buttonValve_27->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[26] = 0;
        ui->buttonValve_27->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_28_clicked(bool checked)
{
    if(maintenance_button_valve[27] == 0)
    {
        maintenance_button_valve[27] = 1;
        ui->buttonValve_28->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[27] = 0;
        ui->buttonValve_28->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_29_clicked(bool checked)
{
    if(maintenance_button_valve[28] == 0)
    {
        maintenance_button_valve[28] = 1;
        ui->buttonValve_29->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[28] = 0;
        ui->buttonValve_29->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_30_clicked(bool checked)
{
    if(maintenance_button_valve[29] == 0)
    {
        maintenance_button_valve[29] = 1;
        ui->buttonValve_30->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[29] = 0;
        ui->buttonValve_30->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_31_clicked(bool checked)
{
    if(maintenance_button_valve[30] == 0)
    {
        maintenance_button_valve[30] = 1;
        ui->buttonValve_31->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[30] = 0;
        ui->buttonValve_31->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_buttonValve_32_clicked(bool checked)
{
    if(maintenance_button_valve[31] == 0)
    {
        maintenance_button_valve[31] = 1;
        ui->buttonValve_32->setStyleSheet("background-color: #3498db; color: #ffffff;");
    }
    else
    {
        maintenance_button_valve[31] = 0;
        ui->buttonValve_32->setStyleSheet("background-color: #FFFFFF; color: #000000;");
    }
}


void MainWindow::on_setpointMotorPeristaltik_valueChanged(int arg1)
{
    maintenance_setpoint_motor_peristaltik = arg1;
}


void MainWindow::on_setpointMotorDAC1_valueChanged(int arg1)
{
    maintenance_setpoint_motor_DAC_1 = arg1;
}


void MainWindow::on_setpointMotorDAC2_valueChanged(int arg1)
{
    maintenance_setpoint_motor_DAC_2 = arg1;
}


void MainWindow::on_setpointMotorPump1_valueChanged(int arg1)
{
    maintenance_setpoint_motor_pump_1 = arg1;
}


void MainWindow::on_setpointMotorPump2_valueChanged(int arg1)
{
    maintenance_setpoint_motor_pump_2 = arg1;
}


void MainWindow::on_setpointMotorPump3_valueChanged(int arg1)
{
    maintenance_setpoint_motor_pump_3 = arg1;
}


void MainWindow::on_setpointMotorStepper_valueChanged(int arg1)
{
    maintenance_setpoint_motor_stepper = arg1;
}








