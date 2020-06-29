#pragma once
#include "Braille_Printer_Machine.h"
// Private Methods
Servo Print_Probe;
void Braille_Printer_Machine::Step_Motor_Open_Enable()const
{
	// Paper_Feed Group
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_UP_En, LOW);
	// A Group
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_A_En, LOW);
	// B Group
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_B_En, LOW);
	// Print Probe Propulsion Group
	digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_En, LOW);
	// Press Paper Group
	digitalWrite(Pin_Stepper_Motor_Press_Paper_En, LOW);
}
void Braille_Printer_Machine::Step_Motor_Close_Enable()const
{
	// Paper_Feed Group
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_UP_En, HIGH);
	// A Group
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_A_En, HIGH);
	// B Group
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_B_En, HIGH);
	// Print Probe Propulsion Group
	digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_En, HIGH);
	// Press Paper Group
	digitalWrite(Pin_Stepper_Motor_Press_Paper_En, HIGH);
}
void Braille_Printer_Machine::Step_Motor_Initialize_Direction()const
{
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_UP_Dir, Stepper_Motor_Paper_Feed_UP_Initialize_Dir);
	digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Dir, Stepper_Motor_Probe_Initialize_Dir);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, Stepper_Motor_Probe_Initialize_Dir);
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_A_Dir, Stepper_Motor_Paper_Feed_A_Work_Dir);
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_B_Dir, Stepper_Motor_Paper_Feed_B_Work_Dir);
}
void Braille_Printer_Machine::Step_Motor_Work_Direction()const
{
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_UP_Dir, Stepper_Motor_Paper_Feed_UP_Work_Dir);
	digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Dir, Stepper_Motor_Probe_Work_Dir);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, Stepper_Motor_Probe_Work_Dir);
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_A_Dir, Stepper_Motor_Paper_Feed_A_Work_Dir);
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_B_Dir, Stepper_Motor_Paper_Feed_B_Work_Dir);
}
bool Braille_Printer_Machine::Limited_Switch_Paper_Feed_UP_Trigged()const
{
	if (digitalRead(Pin_Limited_Switch_Paper_Feed_UP) == LOW)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Braille_Printer_Machine::Limited_Switch_Probe_Propulsion_Trigged()const
{
	if (digitalRead(Pin_Limited_Switch_Probe_Propulsion) == LOW)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Braille_Printer_Machine::Limited_Switch_Press_Paper_Trigged()const
{
	if (digitalRead(Pin_Limited_Switch_Press_Paper) == LOW)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//void Braille_Printer_Machine::Change_Probe_Direction()
//{
//	uint8_t direction_temp = m_Stepper_Motor_Probe_Initialize_Dir;
//	m_Stepper_Motor_Probe_Initialize_Dir = m_Stepper_Motor_Probe_Work_Dir;
//	m_Stepper_Motor_Probe_Work_Dir = direction_temp;
//	digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Dir, m_Stepper_Motor_Probe_Work_Dir);
//	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);
//}
void Braille_Printer_Machine::Probe_Propulsion_Synchronize()const
{
	for (uint32_t i = 0; i < Stepper_Motor_Probe_Loop_Times_Synchronize; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
	}
}
void Braille_Printer_Machine::Press_Paper_Synchronize()const
{
	for (uint32_t i = 0; i < Stepper_Motor_Probe_Loop_Times_Synchronize; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
	}
}
// Public Methods
// Construction
Braille_Printer_Machine::Braille_Printer_Machine()
{

}
void Braille_Printer_Machine::Braille_Printer_Machine_Character_Point_Zero()const // Used when we print a Character Point
{
	Print_Probe.write(Servo_Print_Probe_Default_Position);
}

// Used for Print Mode
// ===============
// TODO: Need More Details Information
//================
void Braille_Printer_Machine::Braille_Printer_Machine_Print_Character_Point_Zero()const // Used when we print a Character Point
{
	//this->Probe_Propulsion_Synchronize();
	//Print_Probe.write(Servo_Print_Probe_Default_Position);
	//delay(Probe_Delay);
	//this->Press_Paper_Synchronize();
	//delay(Probe_Delay);
	//digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Initialize_Dir);
	//this->Press_Paper_Synchronize();
	//delay(Probe_Delay);
	//digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);
	//this->Press_Paper_Synchronize();
	//delay(Probe_Delay);
	this->Braille_Printer_Machine_Character_Point_Zero();
	delay(Probe_Delay);
}
void Braille_Printer_Machine::Braille_Printer_Machine_Print_Character_Point_One()const // Used when we print a Character Point
{
	//this->Probe_Propulsion_Synchronize();
	Print_Probe.write(Servo_Print_Probe_One_Position);
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Initialize_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	//this->Press_Paper_Synchronize();
	//delay(Probe_Delay);
	this->Braille_Printer_Machine_Character_Point_Zero();
	delay(Probe_Delay);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
}
void Braille_Printer_Machine::Braille_Printer_Machine_Print_Character_Point_Two()const // Used when we print a Character Point
{
	//this->Probe_Propulsion_Synchronize();
	Print_Probe.write(Servo_Print_Probe_Two_Position);
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Initialize_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	//this->Press_Paper_Synchronize();
	//delay(Probe_Delay);
	this->Braille_Printer_Machine_Character_Point_Zero();
	delay(Probe_Delay);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
}
void Braille_Printer_Machine::Braille_Printer_Machine_Print_Character_Point_Three()const // Used when we print a Character Point
{
	//this->Probe_Propulsion_Synchronize();
	Print_Probe.write(Servo_Print_Probe_Three_Position);
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Initialize_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	//this->Press_Paper_Synchronize();
	//delay(Probe_Delay);
	this->Braille_Printer_Machine_Character_Point_Zero();
	delay(Probe_Delay);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
}
void Braille_Printer_Machine::Braille_Printer_Machine_Print_Character_Point_Four()const // Used when we print a Character Point
{
	//this->Probe_Propulsion_Synchronize();
	Print_Probe.write(Servo_Print_Probe_Four_Position);
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Initialize_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	//this->Press_Paper_Synchronize();
	//delay(Probe_Delay);
	this->Braille_Printer_Machine_Character_Point_Zero();
	delay(Probe_Delay);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
}
void Braille_Printer_Machine::Braille_Printer_Machine_Print_Character_Point_Five()const // Used when we print a Character Point
{
	//this->Probe_Propulsion_Synchronize();
	Print_Probe.write(Servo_Print_Probe_Five_Position);
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Initialize_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	//this->Press_Paper_Synchronize();
	//delay(Probe_Delay);
	this->Braille_Printer_Machine_Character_Point_Zero();
	delay(Probe_Delay);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
}
void Braille_Printer_Machine::Braille_Printer_Machine_Print_Character_Point_Six()const // Used when we print a Character Point
{
	Print_Probe.write(Servo_Print_Probe_Six_Position);
	delay(Probe_Delay);
	// Sync 
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	//this->Probe_Propulsion_Synchronize();
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Initialize_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	//this->Press_Paper_Synchronize();
	//delay(Probe_Delay);
	this->Braille_Printer_Machine_Character_Point_Zero();
	delay(Probe_Delay);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
}
void Braille_Printer_Machine::Braille_Printer_Machine_Print_Character_Point_Seven()const // Used when we print a Character Point
{
	//this->Probe_Propulsion_Synchronize();
	Print_Probe.write(Servo_Print_Probe_Seven_Position);
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Initialize_Dir);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
	delay(Probe_Delay);
	//this->Press_Paper_Synchronize();
	//delay(Probe_Delay);
	this->Braille_Printer_Machine_Character_Point_Zero();
	delay(Probe_Delay);
	this->Press_Paper_Synchronize();
	this->Press_Paper_Synchronize();
}
void Braille_Printer_Machine::Braille_Printer_Machine_Skip_Space_Between_Character_Point()
{
	this->Braille_Printer_Machine_Print_Character_Point_Zero();
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);

	for (uint32_t i = 0; i < this->m_Stepper_Motor_Probe_Loop_Times_Character_Point; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
	}
	for (uint32_t i = 0; i < this->m_Stepper_Motor_Probe_Loop_Times_Character_Point; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
	}
}
void Braille_Printer_Machine::Braille_Printer_Machine_Skip_Space_Between_Character_Word()
{
	this->Braille_Printer_Machine_Print_Character_Point_Zero();
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);

	for (uint32_t i = 0; i < this->m_Stepper_Motor_Probe_Loop_Times_Character_Word; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
	}
	for (uint32_t i = 0; i < this->m_Stepper_Motor_Probe_Loop_Times_Character_Word; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
	}
}
void Braille_Printer_Machine::Braille_Printer_Machine_Change_Line()
{
	this->Braille_Printer_Machine_Print_Character_Point_Zero();
	delay(Probe_Delay);
	for (uint32_t i = 0; i < this->m_Stepper_Motor_Paper_Feed_Loop_Times_Line; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_A_Step, HIGH);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_B_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Paper_Feed_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_A_Step, LOW);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_B_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Paper_Feed_LOW_Dealyms);
	}
	//digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);   //when change line  use
	//this->Press_Paper_Synchronize();
	//this->Press_Paper_Synchronize();
	//this->Press_Paper_Synchronize();
	//this->Press_Paper_Synchronize();
	//this->Change_Probe_Direction();

}
void Braille_Printer_Machine::Braille_Printer_Machine_Print_Margin_Page_Top()
{
	this->Braille_Printer_Machine_Print_Character_Point_Zero();
	delay(Probe_Delay);
	for (uint32_t i = 0; i < this->m_Stepper_Motor_Paper_Feed_Loop_Times_Margin_Page_Top; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_A_Step, HIGH);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_B_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Paper_Feed_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_A_Step, LOW);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_B_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Paper_Feed_LOW_Dealyms);
	}
}
void Braille_Printer_Machine::Braille_Printer_Machine_Print_Margin_Page_Bottom()
{
	this->Braille_Printer_Machine_Print_Character_Point_Zero();
	delay(Probe_Delay);
	for (uint32_t i = 0; i < this->m_Stepper_Motor_Paper_Feed_Loop_Times_Margin_Page_Bottom; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_A_Step, HIGH);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_B_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Paper_Feed_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_A_Step, LOW);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_B_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Paper_Feed_LOW_Dealyms);
	}
}
void Braille_Printer_Machine::Braille_Printer_Machine_Print_Margin_Page_Left()
{
	this->Braille_Printer_Machine_Print_Character_Point_Zero();
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);

	for (uint32_t i = 0; i < this->m_Stepper_Motor_Probe_Loop_Times_Margin_Page_Left; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
	}
	for (uint32_t i = 0; i < this->m_Stepper_Motor_Probe_Loop_Times_Margin_Page_Left; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
	}
}
void Braille_Printer_Machine::Braille_Printer_Machine_Print_Margin_Page_Right()
{
	this->Braille_Printer_Machine_Print_Character_Point_Zero();
	delay(Probe_Delay);
	digitalWrite(Pin_Stepper_Motor_Press_Paper_Dir, m_Stepper_Motor_Probe_Work_Dir);

	for (uint32_t i = 0; i < this->m_Stepper_Motor_Probe_Loop_Times_Margin_Page_Right; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
	}
	for (uint32_t i = 0; i < this->m_Stepper_Motor_Probe_Loop_Times_Margin_Page_Right; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
	}
}

// Used for Configuration Mode
void Braille_Printer_Machine::Braille_Printer_Machine_Adjust_Space_Between_Character_Point(const uint32_t space)
{
	this->m_Stepper_Motor_Probe_Loop_Times_Character_Point = space;
}
void Braille_Printer_Machine::Braille_Printer_Machine_Adjust_Space_Between_Character_Word(const uint32_t space)
{
	this->m_Stepper_Motor_Probe_Loop_Times_Character_Word = space;
}
void Braille_Printer_Machine::Braille_Printer_Machine_Adjust_Space_Between_Line(const uint32_t space)
{
	this->m_Stepper_Motor_Paper_Feed_Loop_Times_Line = space;
}
void Braille_Printer_Machine::Braille_Printer_Machine_Adjust_Margin_Page_Top(const uint32_t space)
{
	this->m_Stepper_Motor_Paper_Feed_Loop_Times_Margin_Page_Top = space;
}
void Braille_Printer_Machine::Braille_Printer_Machine_Adjust_Margin_Page_Bottom(const uint32_t space)
{
	this->m_Stepper_Motor_Paper_Feed_Loop_Times_Margin_Page_Bottom = space;
}
void Braille_Printer_Machine::Braille_Printer_Machine_Adjust_Margin_Page_Left(const uint32_t space)
{
	this->m_Stepper_Motor_Probe_Loop_Times_Margin_Page_Left = space;
}
void Braille_Printer_Machine::Braille_Printer_Machine_Adjust_Margin_Page_Right(const uint32_t space)
{
	this->m_Stepper_Motor_Probe_Loop_Times_Margin_Page_Right = space;
}
// Used for Other Instruction
void Braille_Printer_Machine::Braille_Printer_Machine_Default_Initialization()const	// Used when we open or reset the Braille_Printer.
{
	// Reset Position
	Print_Probe.attach(Pin_Servo_Print_Probe);
	Print_Probe.write(Servo_Print_Probe_Default_Position);
	this->Step_Motor_Open_Enable();
	this->Step_Motor_Initialize_Direction();
	/*while (this->Limited_Switch_Paper_Feed_UP_Trigged() != true)
	{
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_UP_Step, HIGH);
	delayMicroseconds(Stepper_Motor_Paper_Feed_UP_HIGH_Dealyms);
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_UP_Step, LOW);
	delayMicroseconds(Stepper_Motor_Paper_Feed_UP_LOW_Dealyms);
	}*/

	while (true)
	{

		if (this->Limited_Switch_Probe_Propulsion_Trigged() != true)
		{
			digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, HIGH);
			delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
			digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, LOW);
			delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
		}
		if (this->Limited_Switch_Press_Paper_Trigged() != true)
		{
			digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, HIGH);
			delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
			digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, LOW);
			delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
		}
		if ((this->Limited_Switch_Probe_Propulsion_Trigged() == true) && (this->Limited_Switch_Press_Paper_Trigged()))
		{
			break;
		}
	}
	this->Step_Motor_Work_Direction();

	for (uint32_t i = 0; i < Stepper_Motor_Probe_Loop_Times_Initialize_Position; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, HIGH);
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, LOW);
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
	}
	this->Probe_Propulsion_Synchronize();
	this->Probe_Propulsion_Synchronize();
}
void Braille_Printer_Machine::Braille_Printer_Machine_Customize_Initialization()const	// Used when we open or reset the Braille_Printer.
{
	Print_Probe.attach(Pin_Servo_Print_Probe);
	Print_Probe.write(Servo_Print_Probe_Default_Position);
	this->Step_Motor_Open_Enable();
	this->Step_Motor_Initialize_Direction();
	while (true)
	{

		if (this->Limited_Switch_Probe_Propulsion_Trigged() != true)
		{
			digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, HIGH);
			delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
			digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, LOW);
			delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
		}
		if (this->Limited_Switch_Press_Paper_Trigged() != true)
		{
			digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, HIGH);
			delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
			digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, LOW);
			delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
		}
		if ((this->Limited_Switch_Probe_Propulsion_Trigged() == true) && (this->Limited_Switch_Press_Paper_Trigged()))
		{
			break;
		}
	}
	this->Step_Motor_Work_Direction();

	for (uint32_t i = 0; i < Stepper_Motor_Probe_Loop_Times_Initialize_Position; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, HIGH);
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Probe_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Probe_Propulsion_Step, LOW);
		digitalWrite(Pin_Stepper_Motor_Press_Paper_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Probe_LOW_Dealyms);
	}
}
void Braille_Printer_Machine::Braille_Printer_Machine_Feed_Paper()const	// Used when we feed paper.
{
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_UP_Dir, Stepper_Motor_Paper_Feed_UP_Work_Dir);
	for (uint32_t i = 0; i < Stepper_Motor_Paper_Feed_UP_Loop_Times; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_UP_Step, HIGH);
		delayMicroseconds(Stepper_Motor_Paper_Feed_UP_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_UP_Step, LOW);
		delayMicroseconds(Stepper_Motor_Paper_Feed_UP_LOW_Dealyms);
	}
	for (uint32_t i = 0; i < Stepper_Motor_Paper_Feed_Up_A_B_Loop_Times; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_A_Step, HIGH);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_B_Step, HIGH);
		delayMicroseconds(this->m_Stepper_Motor_Paper_Feed_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_A_Step, LOW);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_B_Step, LOW);
		delayMicroseconds(this->m_Stepper_Motor_Paper_Feed_LOW_Dealyms);
	}
	digitalWrite(Pin_Stepper_Motor_Paper_Feed_UP_Dir, Stepper_Motor_Paper_Feed_UP_Initialize_Dir);
	for (uint32_t i = 0; i < Stepper_Motor_Paper_Feed_UP_Loop_Times; ++i)
	{
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_UP_Step, HIGH);
		delayMicroseconds(Stepper_Motor_Paper_Feed_UP_HIGH_Dealyms);
		digitalWrite(Pin_Stepper_Motor_Paper_Feed_UP_Step, LOW);
		delayMicroseconds(Stepper_Motor_Paper_Feed_UP_LOW_Dealyms);
	}
}
void Braille_Printer_Machine::Braille_Printer_Machine_Pause()const	// Used when we pause the Braille_Printer.
{

}
void Braille_Printer_Machine::Braille_Printer_Machine_Resume()const	// Used when we resumen the Braille_Printer.
{

}
void Braille_Printer_Machine::Braille_Printer_Machine_Stop()const	// Used when we stop the Braille_Printer.
{
	this->Step_Motor_Close_Enable();
}
