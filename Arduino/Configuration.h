// This file is used to set the parameters (eg: PIN,delay_time etc...).
//===================================================================================
// Warning: On Arduino Mega2560, some PINs are used for Serial communication.
// Serial<DEFAULT> PIN: 1(RX),2(TX)
// Serial<ONE> PIN: 19(RX),18(TX)
// Serial<TWO> PIN: 17(RX),16(TX)
// Serial<THREE> PIN: 15(RX),14(TX)
//===================================================================================
// On Mks Gen Mega2560, 42 Stepper Motor can use three kinds of motor drivers.  
// 1) DRV8825
//===================================================================================
//| 1  | 2  | 3  |                step mode
//-----------------------------------------------------------------------------------
//| 0  | 0  | 0	 | Full step (2-phase excitation) with 71% current  |
//-----------------------------------------------------------------------------------
//| 1  | 0  | 0  |      1/2 step (1-2 phase excitation)             |
//-----------------------------------------------------------------------------------
//| 0  | 1  | 0  |      1/4 step (W1-2 phase excitation)            |
//-----------------------------------------------------------------------------------
//| 1  | 1  | 0  |         8 microsteps/step                        |
//-----------------------------------------------------------------------------------
//| 0  | 0  | 1  |         16 microsteps/step                       |
//-----------------------------------------------------------------------------------
//| 1  | 0  | 1  |         32 microsteps/step                       |
//-----------------------------------------------------------------------------------
//| 0  | 1  | 1  |         32 microsteps/step                       |
//-----------------------------------------------------------------------------------
//| 1  | 1  | 1  |         32 microsteps/step                       |
//===================================================================================
// 2) A4988
//===================================================================================
//| 1  | 2  | 3  |                step mode                         |
//-----------------------------------------------------------------------------------
//| 0  | 0  | 0  |                Full step                         |
//-----------------------------------------------------------------------------------
//| 1  | 0  | 0  |                1/2 step                          |
//-----------------------------------------------------------------------------------
//| 0  | 1  | 0  |                1/4 step                          |
//-----------------------------------------------------------------------------------
//| 1  | 1  | 0  |              8 microsteps/step                   |
//-----------------------------------------------------------------------------------
//| 1  | 1  | 1  |              16 microsteps/step                  |
//===================================================================================
// 3) TMC 2208
//| 1  | 2  | 3  |                step mode                         |
//-----------------------------------------------------------------------------------
//| 1  | 0  | 0  |                  2 step                          |
//-----------------------------------------------------------------------------------
//| 0  | 1  | 0  |                  4 step                          |
//-----------------------------------------------------------------------------------
//| 0  | 0  | 0  |                  8 step                          |
//-----------------------------------------------------------------------------------
//| 1  | 1  | 0  |                  16 step                         |
//===================================================================================
// More information can be found on https://reprap.org/wiki/MKS_GEN#Motor_Driver
//===================================================================================
// Thanks to the MKS.
// Writen down on 2019/3/28 by LYF
#pragma once
#include <Arduino.h>
#include <Servo.h>
#include <ArduinoJson.h>
// Set the PING PONG Test and Times
const String Ping("printerVersion");
const String Pong("BraillePrinter Version.123\r\n");
const int8_t Ping_Pong_Limit_Times = 2;
// ================================================
// Set the Ordinary PIN.
const uint8_t Pin_LED_ON_BOARD = 13;
// Set the Limited Switch Pin.
const uint8_t Pin_Limited_Switch_Paper_Feed_UP = 15;
const uint8_t Pin_Limited_Switch_Probe_Propulsion = 18;
const uint8_t Pin_Limited_Switch_Press_Paper = 19;
// Set the Stepper Motors' PIN.
// Paper_Feed Group
const uint8_t Pin_Stepper_Motor_Paper_Feed_UP_En = 38;
const uint8_t Pin_Stepper_Motor_Paper_Feed_UP_Dir = 55;
const uint8_t Pin_Stepper_Motor_Paper_Feed_UP_Step = 54;
// A Group
const uint8_t Pin_Stepper_Motor_Paper_Feed_A_En = 56;
const uint8_t Pin_Stepper_Motor_Paper_Feed_A_Dir = 61;
const uint8_t Pin_Stepper_Motor_Paper_Feed_A_Step = 60;
// B Group
const uint8_t Pin_Stepper_Motor_Paper_Feed_B_En = 62;
const uint8_t Pin_Stepper_Motor_Paper_Feed_B_Dir = 48;
const uint8_t Pin_Stepper_Motor_Paper_Feed_B_Step = 46;
// Print Probe Propulsion Group
const uint8_t Pin_Stepper_Motor_Probe_Propulsion_En = 24;
const uint8_t Pin_Stepper_Motor_Probe_Propulsion_Dir = 28;
const uint8_t Pin_Stepper_Motor_Probe_Propulsion_Step = 26;
// Press Paper Group
const uint8_t Pin_Stepper_Motor_Press_Paper_En = 30;
const uint8_t Pin_Stepper_Motor_Press_Paper_Dir = 34;
const uint8_t Pin_Stepper_Motor_Press_Paper_Step = 36;

// Set the Print Probe Servo's Pin.
// This Pin must support PWM. PWM Pin on board with ~; For example ~11
const uint8_t Pin_Servo_Print_Probe = 11;
// =============================================
// Set the Serials' Bit rate
const unsigned long Serial_Zero_Bit_Rate = 115200;
// Set the Stepper Motors' Parameter.
// Recommend 800; At least "HIGH"+"LOW">=400 AND ("HIGH">=20 OR "LOW">=20)
const uint8_t Stepper_Motor_Paper_Feed_UP_Initialize_Dir = HIGH;
const uint8_t Stepper_Motor_Paper_Feed_UP_Work_Dir = LOW;
const uint32_t Stepper_Motor_Paper_Feed_UP_Loop_Times = 0;
const uint32_t Stepper_Motor_Paper_Feed_Up_A_B_Loop_Times = 4000;
const uint32_t Stepper_Motor_Paper_Feed_UP_HIGH_Dealyms = 800;
const uint32_t Stepper_Motor_Paper_Feed_UP_LOW_Dealyms = 800;
// Feed Paper Group
const uint8_t Stepper_Motor_Paper_Feed_A_Work_Dir = HIGH;
const uint8_t Stepper_Motor_Paper_Feed_B_Work_Dir = LOW;
const uint32_t Stepper_Motor_Paper_Feed_Loop_Times_Line = 749;
const uint32_t Stepper_Motor_Paper_Feed_Loop_Times_Margin_Page_Top = 1000;
const uint32_t Stepper_Motor_Paper_Feed_Loop_Times_Margin_Page_Bottom = 1000;
const uint32_t Stepper_Motor_Paper_Feed_HIGH_Dealyms = 400;
const uint32_t Stepper_Motor_Paper_Feed_LOW_Dealyms = 400;
// Print Probe Group
const uint8_t Stepper_Motor_Probe_Initialize_Dir = HIGH;
const uint8_t Stepper_Motor_Probe_Work_Dir = LOW;
const uint32_t Stepper_Motor_Probe_Loop_Times_Character_Point = 360;
const uint32_t Stepper_Motor_Probe_Loop_Times_Character_Word = 518;
const uint32_t Stepper_Motor_Probe_Loop_Times_Margin_Page_Left = 1000;
const uint32_t Stepper_Motor_Probe_Loop_Times_Margin_Page_Right = 1000;
const uint32_t Stepper_Motor_Probe_Loop_Times_Initialize_Position = 2500;
const uint32_t Stepper_Motor_Probe_HIGH_Dealyms = 400;
const uint32_t Stepper_Motor_Probe_LOW_Dealyms = 400;
// Synchronize
const uint32_t Stepper_Motor_Probe_Loop_Times_Synchronize = 250; 
const unsigned long Probe_Delay = 500;
// Set the Print Probe Servo's Default Position.
// The value range from 0 to 180.
// Each block need 22
const int Servo_Print_Probe_Default_Position = 0;
const int Servo_Print_Probe_One_Position = 23;
const int Servo_Print_Probe_Two_Position = 49;
const int Servo_Print_Probe_Three_Position = 74;
const int Servo_Print_Probe_Four_Position = 100;
const int Servo_Print_Probe_Five_Position = 126;
const int Servo_Print_Probe_Six_Position = 145;
const int Servo_Print_Probe_Seven_Position = 165;
// =============================================
// Set the Printer's Instruction
// Instruction in Print Mode
const uint8_t Print_Character_Point_Zero = 0x81;
const uint8_t Print_Character_Point_One = 0x82;
const uint8_t Print_Character_Point_Two = 0x83;
const uint8_t Print_Character_Point_Three = 0x84;
const uint8_t Print_Character_Point_Four = 0x85;
const uint8_t Print_Character_Point_Five = 0x86;
const uint8_t Print_Character_Point_Six = 0x87;
const uint8_t Print_Character_Point_Seven = 0x88;
const uint8_t Print_Space_Between_Character_Point = 0x89;
const uint8_t Print_Space_Between_Character_Word = 0x8A;
const uint8_t Print_Change_Line = 0x8B;
// Page Margin
const uint8_t Print_Margin_Page_Top = 0x91;
const uint8_t Print_Margin_Page_Bottom = 0x92;
const uint8_t Print_Margin_Page_Left = 0x93;
const uint8_t Print_Margin_Page_Right = 0x94;
// Instruction in Configuration Mode
const uint8_t Adjust_Space_Between_Character_Point = 0xA1;
const uint8_t Adjust_Space_Between_Character_Word = 0xA2;
const uint8_t Adjust_Space_Between_Line = 0xA3;
const uint8_t Adjust_Margin_Page_Top = 0xA4;
const uint8_t Adjust_Margin_Page_Bottom = 0xA5;
const uint8_t Adjust_Margin_Page_Left = 0xA6;
const uint8_t Adjust_Margin_Page_Right = 0xA7;
// Other Instruction
const uint8_t Printer_Default_Initialization = 0xB1;
const uint8_t Printer_Customize_Initialization = 0xB2;
const uint8_t Printer_Feed_Paper = 0xB3;
const uint8_t Printer_Pause = 0xB4;
const uint8_t Printer_Resume = 0xB5;
const uint8_t Printer_Stop = 0xB6;

inline void Initialize_PIN_Data()	// This function is used for Initializing 
{

	// Set PinMode
	pinMode(Pin_LED_ON_BOARD, OUTPUT);
	// Paper_Feed Group
	pinMode(Pin_Stepper_Motor_Paper_Feed_UP_En, OUTPUT);
	pinMode(Pin_Stepper_Motor_Paper_Feed_UP_Dir, OUTPUT);
	pinMode(Pin_Stepper_Motor_Paper_Feed_UP_Step, OUTPUT);
	// A Group
	pinMode(Pin_Stepper_Motor_Paper_Feed_A_En, OUTPUT);
	pinMode(Pin_Stepper_Motor_Paper_Feed_A_Dir, OUTPUT);
	pinMode(Pin_Stepper_Motor_Paper_Feed_A_Step, OUTPUT);
	// B Group
	pinMode(Pin_Stepper_Motor_Paper_Feed_B_En, OUTPUT);
	pinMode(Pin_Stepper_Motor_Paper_Feed_B_Dir, OUTPUT);
	pinMode(Pin_Stepper_Motor_Paper_Feed_B_Step, OUTPUT);
	// Print Probe Propulsion Group
	pinMode(Pin_Stepper_Motor_Probe_Propulsion_En, OUTPUT);
	pinMode(Pin_Stepper_Motor_Probe_Propulsion_Dir, OUTPUT);
	pinMode(Pin_Stepper_Motor_Probe_Propulsion_Step, OUTPUT);
	// Press Paper Group
	pinMode(Pin_Stepper_Motor_Press_Paper_En, OUTPUT);
	pinMode(Pin_Stepper_Motor_Press_Paper_Dir, OUTPUT);
	pinMode(Pin_Stepper_Motor_Press_Paper_Step, OUTPUT);
	// Limited Switch Pin.
	pinMode(Pin_Limited_Switch_Paper_Feed_UP, INPUT_PULLUP);
	pinMode(Pin_Limited_Switch_Probe_Propulsion, INPUT_PULLUP);
	pinMode(Pin_Limited_Switch_Press_Paper, INPUT_PULLUP);
}
