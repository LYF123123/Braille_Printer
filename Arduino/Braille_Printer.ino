/*
 Name:		Braille_Printer.ino
 Created:	2019/10/2 8:37:32
 Author:	Luyifeng
 E-mail:    luyifeng3@163.com
*/
//===========================================================================
// Special thanks to MKS and my work group.
// Hardware designed by other member in my group.
//===========================================================================
#pragma once
#include "Braille_Printer_Machine.h"
Braille_Printer_Machine braille_printer_machine;
String str = "";
int8_t times = 0;// Already "Ping Pong" how many times?
uint32_t variable_temp = 0;
StaticJsonDocument<300> doc;
// the setup function runs once when you press reset or power the board
void setup() {
	// Initialize the Serial
	pinMode(13, OUTPUT);
	digitalWrite(13, LOW);
	Serial.begin(Serial_Zero_Bit_Rate);
	Initialize_PIN_Data();
	//braille_printer_machine.Braille_Printer_Machine_Default_Initialization();
}

// the loop function runs over and over again until power down or reset
void loop() {
	while (Serial.available() > 0)
	{
		//String json (Serial.readString());
		deserializeJson(doc, Serial);
		char* str = doc["version"];
		String version(str);
		if (version.equals(Ping))
		{
			doc["version"] = Pong;
			serializeJsonPretty(doc, Serial);
		}

		
		//char ch = temp;
		//if (ch != 0)
		//{
		//	//Serial.print(ch);
		//	if (times < Ping_Pong_Limit_Times)
		//	{
		//		str += ch;
		//		//Serial.print(str); Serial.print(" ");
		//	}
		//	//else
		//	//{	// every Serial statement will be deleted in the release package
		//	//	// Instruction in Print Mode
		//	//	if (temp == Print_Character_Point_Zero)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Print_Character_Point_Zero();
		//	//		Serial.println(Print_Character_Point_Zero);
		//	//	}
		//	//	if (temp == Print_Character_Point_One)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Print_Character_Point_One();
		//	//		Serial.println(Print_Character_Point_One);
		//	//	}
		//	//	if (temp == Print_Character_Point_Two)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Print_Character_Point_Two();
		//	//		Serial.println(Print_Character_Point_Two);
		//	//	}
		//	//	if (temp == Print_Character_Point_Three)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Print_Character_Point_Three();
		//	//		Serial.println(Print_Character_Point_Three);
		//	//	}
		//	//	if (temp == Print_Character_Point_Four)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Print_Character_Point_Four();
		//	//		Serial.println(Print_Character_Point_Four);
		//	//	}
		//	//	if (temp == Print_Character_Point_Five)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Print_Character_Point_Five();
		//	//		Serial.println(Print_Character_Point_Five);
		//	//	}
		//	//	if (temp == Print_Character_Point_Six)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Print_Character_Point_Six();
		//	//		Serial.println(Print_Character_Point_Six);
		//	//	}
		//	//	if (temp == Print_Character_Point_Seven)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Print_Character_Point_Seven();
		//	//		Serial.println(Print_Character_Point_Seven);
		//	//	}
		//	//	else if (temp == Print_Space_Between_Character_Point)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Skip_Space_Between_Character_Point();
		//	//		Serial.println(Print_Space_Between_Character_Point);
		//	//	}
		//	//	else if (temp == Print_Space_Between_Character_Word)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Skip_Space_Between_Character_Word();
		//	//		Serial.println(Print_Space_Between_Character_Word);
		//	//	}
		//	//	else if (temp == Print_Change_Line)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Change_Line();
		//	//		Serial.println(Print_Change_Line);
		//	//	}
		//	//	else if (temp == Print_Margin_Page_Top)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Print_Margin_Page_Top();
		//	//		Serial.println(Print_Margin_Page_Top);
		//	//	}
		//	//	else if (temp == Print_Margin_Page_Bottom)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Print_Margin_Page_Bottom();
		//	//		Serial.println(Print_Margin_Page_Bottom);
		//	//	}
		//	//	else if (temp == Print_Margin_Page_Left)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Print_Margin_Page_Left();
		//	//		Serial.println(Print_Margin_Page_Left);
		//	//	}
		//	//	else if (temp == Print_Margin_Page_Right)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Print_Margin_Page_Right();
		//	//		Serial.println(Print_Margin_Page_Right);
		//	//	}
		//	//	// Instruction in Configuration Mode
		//	//	else if (temp == Adjust_Space_Between_Character_Point)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Adjust_Space_Between_Character_Point(variable_temp);
		//	//		int var = variable_temp;
		//	//		Serial.print("Adjust_Space_Between_Character_Point: ");
		//	//		Serial.println(var);
		//	//		variable_temp = 0;
		//	//	}
		//	//	else if (temp == Adjust_Space_Between_Character_Word)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Adjust_Space_Between_Character_Word(variable_temp);
		//	//		int var = variable_temp;
		//	//		Serial.print("Adjust_Space_Between_Character_Word: ");
		//	//		Serial.println(var);
		//	//		variable_temp = 0;
		//	//	}

		//	//	else if (temp == Adjust_Space_Between_Line)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Adjust_Space_Between_Line(variable_temp);
		//	//		int var = variable_temp;
		//	//		Serial.print("Adjust_Space_Between_Line: ");
		//	//		Serial.println(var);
		//	//		variable_temp = 0;
		//	//	}
		//	//	else if (temp == Adjust_Margin_Page_Top)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Adjust_Margin_Page_Top(variable_temp);
		//	//		int var = variable_temp;
		//	//		Serial.print("Adjust_Margin_Page_Top: ");
		//	//		Serial.println(var);
		//	//		variable_temp = 0;
		//	//	}
		//	//	else if (temp == Adjust_Margin_Page_Bottom)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Adjust_Margin_Page_Bottom(variable_temp);
		//	//		int var = variable_temp;
		//	//		Serial.print("Adjust_Margin_Page_Bottom: ");
		//	//		Serial.println(var);
		//	//		variable_temp = 0;
		//	//	}
		//	//	else if (temp == Adjust_Margin_Page_Left)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Adjust_Margin_Page_Left(variable_temp);
		//	//		int var = variable_temp;
		//	//		Serial.print("Adjust_Margin_Page_Left: ");
		//	//		Serial.println(var);
		//	//		variable_temp = 0;
		//	//	}
		//	//	else if (temp == Adjust_Margin_Page_Right)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Adjust_Margin_Page_Right(variable_temp);
		//	//		int var = variable_temp;
		//	//		Serial.print("Adjust_Margin_Page_Right: ");
		//	//		Serial.println(var);
		//	//		variable_temp = 0;
		//	//	}
		//	//	// Other Instruction
		//	//	else if (temp == Printer_Default_Initialization)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Default_Initialization();
		//	//		times = 0;
		//	//		Serial.println("Braille_Printer_Machine_Default_Initialization");
		//	//	}
		//	//	else if (temp == Printer_Customize_Initialization)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Customize_Initialization();
		//	//		Serial.println("Braille_Printer_Machine_Customize_Initialization");
		//	//	}
		//	//	else if (temp == Printer_Feed_Paper)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Feed_Paper();
		//	//		Serial.println(Printer_Feed_Paper);
		//	//	}
		//	//	else if (temp == Printer_Pause)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Pause();
		//	//		Serial.println(Printer_Pause);
		//	//	}
		//	//	else if (temp == Printer_Resume)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Resume();
		//	//		Serial.println(Printer_Resume);
		//	//	}
		//	//	else if (temp == Printer_Stop)
		//	//	{
		//	//		braille_printer_machine.Braille_Printer_Machine_Stop();
		//	//		times = 0;
		//	//		Serial.println();
		//	//	}
		//	//	else
		//	//	{
		//	//		// Data process.
		//	//		variable_temp = variable_temp * 10;
		//	//		variable_temp += temp;
		//	//	}
		//	//	//temp = 0x00;
		//	//	//str = "";
		//	//}

		//}
		//if (str.equals(Ping))
		//{
		//	times++;
		//	Serial.print(Pong);
		//	str = "";
		//}
	}



}
