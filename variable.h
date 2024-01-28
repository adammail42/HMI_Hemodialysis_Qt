#ifndef VARIABLE_H
#define VARIABLE_H

#include "iostream"

//Variable INDEX PAGE
int8_t index_H1;
int8_t index_H2;
int8_t index_H3;
int8_t index_H2_prep;
int8_t index_H2_rinse;
int8_t index_H2_dialys;
int8_t index_H2_maintenance;
int8_t index_H3_maintenance_1;
int8_t index_H3_maintenance_2;

//Variable START STOP
bool status_machine;

//Variable for PREP MODE
int16_t prep_mode_display[8];
bool prep_mode_output[4];
int16_t prep_mode_input[4];
std::string prep_mode_display_text_label[8]= {"test", "test1", "test2", "test3", "test4", "test5", "test6", "test7"};
std::string prep_mode_input_text_label[4]= {"test", "test1", "test2", "test3"};
std::string prep_mode_output_text_label[4]= {"test", "test1", "test2", "test3"};

//Variable for RINSE MODE
int16_t rinse_mode_display[8];
bool rinse_mode_output[4];
int16_t rinse_mode_input[4];
std::string rinse_mode_display_text_label[8]= {"test", "test1", "test2", "test3", "test4", "test5", "test6", "test7"};
std::string rinse_mode_input_text_label[4]= {"test", "test1", "test2", "test3"};
std::string rinse_mode_output_text_label[4]= {"test", "test1", "test2", "test3"};

//Variable for DIALYS MODE
int16_t dialys_mode_display[8];
bool dialys_mode_output[4];
int16_t dialys_mode_input[4];
std::string dialys_mode_display_text_label[8]= {"test", "test1", "test2", "test3", "test4", "test5", "test6", "test7"};
std::string dialys_mode_input_text_label[4]= {"test", "test1", "test2", "test3"};
std::string dialys_mode_output_text_label[4]= {"test", "test1", "test2", "test3"};

//Variable for MAINTENANCE
//Konfigurasi Input Output Tombol Valve
bool maintenance_button_valve[32];
bool maintenance_digital_input[32];
int16_t maintenance_num_display_1[32];
int16_t maintenance_num_display_2[32];

//Konfigurasi Motor
//Motor Peristaltik
int16_t maintenance_setpoint_motor_peristaltik;
int16_t maintenance_real_motor_peristaltik;

//Motor DAC 1
int16_t maintenance_setpoint_motor_DAC_1;
int16_t maintenance_real_motor_DAC_1;

//Motor DAC 2
int16_t maintenance_setpoint_motor_DAC_2;
int16_t maintenance_real_motor_DAC_2;

//Motor Pump_1
int16_t maintenance_setpoint_motor_pump_1;
int16_t maintenance_real_motor_pump_1;

//Motor Pump_2
int16_t maintenance_setpoint_motor_pump_2;
int16_t maintenance_real_motor_pump_2;

//Motor Pump_3
int16_t maintenance_setpoint_motor_pump_3;
int16_t maintenance_real_motor_pump_3;

//Motor Stepper
int16_t maintenance_setpoint_motor_stepper;
int16_t maintenance_real_motor_stepper;
bool maintenance_motor_stepper_injection_status;
bool maintenance_motor_stepper_zero_pos_status;


#endif // VARIABLE_H

