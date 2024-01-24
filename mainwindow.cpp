#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "variable.h"
#include "QTimer"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create a timer and connect its timeout signal to the updateValue slot
    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, MainWindow::updateValue);

    // Set the timer interval (in milliseconds)
    updateTimer->start(1000); // Update the value every 1000 milliseconds (1 second)

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
    }
    else if (index_H1 == 1)
    {
        index_H2 = index_H2_rinse;
    }
    else if (index_H1 == 2)
    {
        index_H2 = index_H2_dialys;
    }
    ui-> labelIndexH1 -> setText(QString::fromStdString(std::to_string(index_H1)));
    ui-> labelIndexH2 -> setText(QString::fromStdString(std::to_string(index_H2)));

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


void MainWindow::on_tabWidget_currentChanged(int index)
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




