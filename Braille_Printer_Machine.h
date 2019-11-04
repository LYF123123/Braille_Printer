#pragma once
#include "Configuration.h"
class Braille_Printer_Machine
{
private:
	// Parameters
	// Recommend 800; At least "HIGH"+"LOW">=400 AND ("HIGH">=20 OR "LOW">=20)
	// Feed Paper Group
	mutable uint32_t m_Stepper_Motor_Paper_Feed_Loop_Times_Line = Stepper_Motor_Paper_Feed_Loop_Times_Line;
	mutable uint32_t m_Stepper_Motor_Paper_Feed_Loop_Times_Margin_Page_Top = Stepper_Motor_Paper_Feed_Loop_Times_Margin_Page_Top;
	mutable uint32_t m_Stepper_Motor_Paper_Feed_Loop_Times_Margin_Page_Bottom = Stepper_Motor_Paper_Feed_Loop_Times_Margin_Page_Bottom;
	mutable uint32_t m_Stepper_Motor_Paper_Feed_HIGH_Dealyms = Stepper_Motor_Paper_Feed_HIGH_Dealyms;
	mutable uint32_t m_Stepper_Motor_Paper_Feed_LOW_Dealyms = Stepper_Motor_Paper_Feed_LOW_Dealyms;
	// Print Probe Propulsion Group
	mutable uint8_t m_Stepper_Motor_Probe_Initialize_Dir = Stepper_Motor_Probe_Initialize_Dir;
	mutable uint8_t m_Stepper_Motor_Probe_Work_Dir = Stepper_Motor_Probe_Work_Dir;
	mutable uint32_t m_Stepper_Motor_Probe_Loop_Times_Character_Point = Stepper_Motor_Probe_Loop_Times_Character_Point;
	mutable uint32_t m_Stepper_Motor_Probe_Loop_Times_Character_Word = Stepper_Motor_Probe_Loop_Times_Character_Word;
	mutable uint32_t m_Stepper_Motor_Probe_Loop_Times_Margin_Page_Left = Stepper_Motor_Probe_Loop_Times_Margin_Page_Left;
	mutable uint32_t m_Stepper_Motor_Probe_Loop_Times_Margin_Page_Right = Stepper_Motor_Probe_Loop_Times_Margin_Page_Right;
	mutable uint32_t m_Stepper_Motor_Probe_HIGH_Dealyms = Stepper_Motor_Probe_HIGH_Dealyms;
	mutable uint32_t m_Stepper_Motor_Probe_LOW_Dealyms = Stepper_Motor_Probe_LOW_Dealyms;

	// Press Paper Group
	// methods
	void Step_Motor_Open_Enable()const;
	void Step_Motor_Close_Enable()const;
	void Step_Motor_Initialize_Direction()const;
	void Step_Motor_Work_Direction()const;
	bool Limited_Switch_Paper_Feed_UP_Trigged()const;
	bool Limited_Switch_Probe_Propulsion_Trigged()const;
	bool Limited_Switch_Press_Paper_Trigged()const;
	void Change_Probe_Direction();
	void Probe_Propulsion_Synchronize()const;
	void Press_Paper_Synchronize()const;
	void Braille_Printer_Machine_Print_Character_Point_Zero()const; // Used when we print a Character Point
	// TODO~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Other Motors' Events
public:
	// Construction
	Braille_Printer_Machine();
	// Used for Print Mode
	// 1/2 +point +1/2
	void Braille_Printer_Machine_Print_Character_Point_One()const; // Used when we print a Character Point
	void Braille_Printer_Machine_Print_Character_Point_Two()const; // Used when we print a Character Point
	void Braille_Printer_Machine_Print_Character_Point_Three()const; // Used when we print a Character Point
	void Braille_Printer_Machine_Print_Character_Point_Four()const; // Used when we print a Character Point
	void Braille_Printer_Machine_Print_Character_Point_Five()const; // Used when we print a Character Point
	void Braille_Printer_Machine_Print_Character_Point_Six()const; // Used when we print a Character Point
	void Braille_Printer_Machine_Print_Character_Point_Seven()const; // Used when we print a Character Point
	// Servo Position: 0 + 1
	void Braille_Printer_Machine_Skip_Space_Between_Character_Point();
	void Braille_Printer_Machine_Skip_Space_Between_Character_Word();
	void Braille_Printer_Machine_Change_Line();
	void Braille_Printer_Machine_Print_Margin_Page_Top();
	void Braille_Printer_Machine_Print_Margin_Page_Bottom();
	void Braille_Printer_Machine_Print_Margin_Page_Left();
	void Braille_Printer_Machine_Print_Margin_Page_Right();

	// Used for Configuration Mode
	void Braille_Printer_Machine_Adjust_Space_Between_Character_Point(const uint32_t space);
	void Braille_Printer_Machine_Adjust_Space_Between_Character_Word(const uint32_t space);
	void Braille_Printer_Machine_Adjust_Space_Between_Line(const uint32_t space);
	void Braille_Printer_Machine_Adjust_Margin_Page_Top(const uint32_t space);
	void Braille_Printer_Machine_Adjust_Margin_Page_Bottom(const uint32_t space);
	void Braille_Printer_Machine_Adjust_Margin_Page_Left(const uint32_t space);
	void Braille_Printer_Machine_Adjust_Margin_Page_Right(const uint32_t space);

	// Used for Other Instruction
	void Braille_Printer_Machine_Default_Initialization()const;	// Used when we open or reset the Braille_Printer.
	void Braille_Printer_Machine_Customize_Initialization()const;	// Used when we open or reset the Braille_Printer.
	void Braille_Printer_Machine_Feed_Paper()const;	// Used when we feed paper.
	void Braille_Printer_Machine_Pause()const;	// Used when we pause the Braille_Printer.
	void Braille_Printer_Machine_Resume()const;	// Used when we resumen the Braille_Printer.
	void Braille_Printer_Machine_Stop()const;	// Used when we stop the Braille_Printer.

};