#ifndef VARIABLE_H
#define VARIABLE_H

#include "iostream"

//Variable INDEX PAGE
int8_t index_H1;
int8_t index_H2;
int8_t index_H2_prep;
int8_t index_H2_rinse;
int8_t index_H2_dialys;

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
//Konfigutasi Input Output Tombol Valve
bool maintenance_button_valve[32];
bool maintenance_digital_input[32];


#endif // VARIABLE_H

