/* ###################################################################
**     Filename    : main.c
**     Project     : main
**     Processor   : MCF51EM256CLL
**     Version     : Driver 01.00
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2013-07-29, 16:12, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Input.h"
#include "TI1.h"
#include "Bit1.h"
#include "Bit1.h"
#include "password.h"
/* Include shared modules, which are used for whole project */
#include "LCD_HAL.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
byte display_buffer[10] = {'0',0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00};
int key;

bool entering_password = TRUE;
bool flag = FALSE;
bool TI1 = FALSE;
void main(void)
{
  /* Write your local variable definition here */
	unsigned char lock[]="lock";
	unsigned char unlock[]="unlock";
	unsigned char Invalid[]="Invalid";
	unsigned char codeset[]="Code set";
	int index = 0; // {Length, hasNumber, hasLetter}
	int guesses = 0;
	int i;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  vfnLCD_Init();
  vfnLCD_Set_Display();
  vfnLCD_Clear_Display();
  init_password();
  for(;;)
  {
	  if(!entering_password && key == 14 && TI1) //resetting if invalid
	  {
		  index = -1;
		  for(i = 1;i < 9;i++)
		  {
			  display_buffer[i] = 0x20;
		  }
		  entering_password = TRUE;
	  }
	  else if(!entering_password && key == 13 && TI1 && guesses < 1) //setting new password or when password is entered correctly
	  {
		  index = -1;
		  init_password();
			for (i = 1; i < 9; i++)
			{
				display_buffer[i] = 0x20;
			}
		  entering_password = TRUE;
	  }
	  else if(entering_password && guesses < 10)
	  {
		  vfnLCD_Write_Msg(display_buffer);
		  if(key == 14) //SW3 (PTB6) as Pin0 forwards
		  {
			  //ascii numbers(48-57) & letters(65-90)
			  if(display_buffer[index] >= 57 && display_buffer[index] < 65)
			  {
				  display_buffer[index] = 65;
			  }
			  else if(display_buffer[index] >= 90)
			  {
				  display_buffer[index] = 48;
			  }
			  else
			  {
				  display_buffer[index]++;
			  }
			  key = 0;
		  }
		  if(key == 13) //SW4 (PTB7) as Pin1 backwards
		  {
			  //ascii numbers(48-57) & letters(65-90)
			  if(display_buffer[index] <= 48)
			  {
				  display_buffer[index] = 90;
			  }
			  else if(display_buffer[index] <= 65 && display_buffer[index] > 57)
			  {
				  display_buffer[index] = 57;
			  }
			  else
			  {
				  display_buffer[index]--;
			  }
			  key = 0;
		  }
		  if(key == 11 && TI1) //MCU Pin 38 (PTB1) enter and go forward to next number (ENTER)
		  {
			  if(index < 8)
			  {
				  index++;
				  display_buffer[index] = '0';
			  }
			  key = 0;
		  }
		  if(key == 07 && TI1) //MCU Pin 5 (PTB3) save password into hash (CONFIRM)
		  {
			  int correct_msg = 0;
			  if(validate_password((char*)display_buffer,(byte)index+1))
			  {
				  if(!is_password_set())
				  {
					  set_password((char*)display_buffer,(byte)index+1);
					  correct_msg = 1;
				  }
				  else if (authenticate_password((char*)display_buffer,(byte)index+1))
				  {
					  guesses = 0;
					  Bit1_NegVal(); // Unlock or Lock Door 
					  correct_msg = 2;
				  }
				  else
				  {
					  guesses++;
				  }
			  }
			  else
			  {
				  guesses++;
			  }
			  if(correct_msg == 2)
			  {
				  if(Bit1_GetVal())
					  vfnLCD_Write_Msg(lock); //locking door (Bit1 LED off) with first time confirming correct password
				  else
					  vfnLCD_Write_Msg(unlock); //unlocking door (Bit1 LED on) with second time confirming correct password
			  }
			  else if (correct_msg == 1) //password is correct
				  vfnLCD_Write_Msg(codeset);
			  
			  else if (correct_msg == 0) //password is Invalid
				  vfnLCD_Write_Msg(Invalid);
			  
			  entering_password = FALSE;
			  key = 0;
		  }
		  TI1 = FALSE;
	  }
  }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.2 [05.07]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
