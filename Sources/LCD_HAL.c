/****************************************************************************************************/
/*
Copyright (c) 2008 Freescale Semiconductor
Freescale Confidential Proprietary
\file       	app_Ascii.h
\brief      
\author     Alejandra Guzman Castellanos
\author     Technical Information Center (TIC)
\author     
\version    0.1
\date       December/2008
*/
/**************************************************************************************************/
/* 																					*/
/* All software, source code, included documentation, and any implied know-how are property of			*/
/* Freescale Semiconductor and therefore considered CONFIDENTIAL INFORMATION.                       			*/
/* This confidential information is disclosed FOR DEMONSTRATION PURPOSES ONLY.                      			*/
/* 																					*/
/* All Confidential Information remains the property of Freescale Semiconductor and will not be     			*/
/* copied or reproduced without the express written permission of the Discloser, except for copies  			*/
/* that are absolutely necessary in order to fulfill the Purpose.                                   						*/
/* 																					*/
/* Services performed by FREESCALE in this matter are performed AS IS and without any warranty.     			*/
/* CUSTOMER retains the final decision relative to the total design and functionality of the end    			*/
/* product.                                                                                         										*/
/* FREESCALE neither guarantees nor will be held liable by CUSTOMER for the success of this project.*/
/* 																					*/
/* FREESCALE disclaims all warranties, express, implied or statutory including, but not limited to, 			*/
/* implied warranty of merchantability or fitness for a particular purpose on any hardware,         				*/
/* software ore advise supplied to the project by FREESCALE, and or any product resulting from      			*/
/* FREESCALE services.                                                                              									*/
/* In no event shall FREESCALE be liable for incidental or consequential damages arising out of     			*/
/* this agreement. CUSTOMER agrees to hold FREESCALE harmless against any and all claims demands or 		*/
/* actions by anyone on account of any damage,or injury, whether commercial, contractual, or        			*/
/* tortuous, rising directly or indirectly as a result of the advise or assistance supplied CUSTOMER			*/ 
/* in connectionwith product, services or goods supplied under this Agreement.                      				*/
/*  																					*/
/****************************************************************************************************/
/*****************************************************************************************************
* Include files
*****************************************************************************************************/
#include "FslTypes.h"
#include "LCD_HAL.h"
#include "PE_Types.h"
#include "IO_Map.h"
/*****************************************************************************************************
* Declaration of module wide FUNCTIONs - NOT for use in other modules
*****************************************************************************************************/
 /** brief: Enable all the pins of the mcu directly connected to the  LCD on use*/
void vfnEnablePins (void);

/** brief: Enable the function of Backplane and Set the COM number that corresponds*/ 
void vfnLCD_ConfigureBackplanes (void);

/*****************************************************************************************************
* Definition of module wide MACROs / #DEFINE-CONSTANTs - NOT for use in other modules
*****************************************************************************************************/
#define vfnLCD_GoTo(Place)	gu8LCD_CharPosition =(UINT8)(Place*_LCDTYPE) 
#define vfnLCD_Home()			gu8LCD_CharPosition = 0	
/*****************************************************************************************************
* Declaration of module wide TYPEs - NOT for use in other modules
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of module wide VARIABLEs - NOT for use in other modules
*****************************************************************************************************/
UINT8 gu8LCD_CharPosition = 0;
volatile UINT8 gu8RamBuffer[40];

#define pause_write() (void)LCDC0;(void)LCDC0  // dummy read to give time to

void vfnLCD_Write_Char (UINT8 u8Value);
void  vfnLCD_Write_Msg (UINT8 * pu8Message);


/*****************************************************************************************************
* Definition of module wide (CONST-) CONSTANTs - NOT for use in other modules
*****************************************************************************************************/
 const UINT8 aPlace [ ] =
{
	CHAR1A,   // LCD4 --- Pin:5
	CHAR1B,   // LCD5 --- Pin:6
	CHAR1C,   // LCD6 --- Pin:7
	CHAR1D,   // LCD7 --- Pin:8
	CHAR2A,   // LCD8 --- Pin:9
	CHAR2B,   // LCD9 --- Pin:10
	CHAR2C,   // LCD10 --- Pin:11
	CHAR2D,   // LCD11 --- Pin:12
	CHAR3A,   // LCD12 --- Pin:44
	CHAR3B,   // LCD13 --- Pin:43
	CHAR3C,   // LCD14 --- Pin:42
	CHAR3D,   // LCD15 --- Pin:41
	CHAR4A,   // LCD16 --- Pin:40
	CHAR4B,   // LCD17 --- Pin:39
	CHAR4C,   // LCD18 --- Pin:38
	CHAR4D,   // LCD19 --- Pin:37
	CHAR5A,   // LCD20 --- Pin:36
	CHAR5B,   // LCD21 --- Pin:35
	CHAR5C,   // LCD22 --- Pin:34
	CHAR5D,   // LCD23 --- Pin:33
	CHAR6A,   // LCD24 --- Pin:32
	CHAR6B,   // LCD25 --- Pin:31
	CHAR6C,   // LCD26 --- Pin:30
	CHAR6D,   // LCD27 --- Pin:29
	CHAR7A,   // LCD28 --- Pin:13
	CHAR7B,   // LCD29 --- Pin:14
	CHAR7C,   // LCD30 --- Pin:15
	CHAR7D,   // LCD31 --- Pin:16
	CHAR8A,   // LCD32 --- Pin:17
	CHAR8B,   // LCD33 --- Pin:18
	CHAR8C,   // LCD34 --- Pin:19
	CHAR8D,   // LCD35 --- Pin:20
	CHAR9A,   // LCD36 --- Pin:21
	CHAR9B,   // LCD37 --- Pin:22
	CHAR9C,   // LCD38 --- Pin:23
	CHAR9D,   // LCD39 --- Pin:24
};					   

const UINT8 aBackup [ ] =
{
   _Backupd,
   _Backupc,
   _Backupb,
   _Backupa,
};
 
const byte aAscii [ ] =
{

( SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+!SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = (,   offset=0
(!SEGN+!SEGE+!SEGF+ SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+ SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = ),   offset=4
( SEGN+!SEGE+!SEGF+ SEGH) , ( SEGM+ SEGG+ SEGJ+!SEGA) , (!SEGD+ SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = *,   offset=8
(!SEGN+!SEGE+!SEGF+!SEGH) , ( SEGM+ SEGG+ SEGJ+!SEGA) , (!SEGD+!SEGL+!SEGK) , (!SEGC+!SEGB),     //Char = +,   offset=12
(!SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+!SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = ´,   offset=16
(!SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+!SEGA) , (!SEGD+!SEGL+!SEGK) , (!SEGC+!SEGB),     //Char = -,   offset=20
(!SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+!SEGL+!SEGK) , (!SEGC+!SEGB),     //Char = .,   offset=24
(!SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+ SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = /,   offset=28 

(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = 0,   offset=0
(!SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+!SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = 1,   offset=4
(!SEGN+ SEGE+!SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+!SEGK) , (!SEGC+ SEGB),     //Char = 2,   offset=8
(!SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = 3,   offset=12
(!SEGN+!SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+!SEGA) , (!SEGD+!SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = 4,   offset=16
(!SEGN+!SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+!SEGB),     //Char = 5,   offset=20
(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+!SEGB),     //Char = 6,   offset=24
(!SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+ SEGA) , (!SEGD+!SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = 7,   offset=28
(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = 8,   offset=32
(!SEGN+!SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = 9,   offset=36
(!SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+!SEGL+!SEGK) , (!SEGC+!SEGB),     //Char = :,   offset=40
(!SEGN+!SEGE+!SEGF+!SEGH) , ( SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+ SEGL+!SEGK) , (!SEGC+!SEGB),     //Char = ;,   offset=44
(!SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+ SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = <,   offset=48
(!SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+!SEGA) , ( SEGD+!SEGL+!SEGK) , (!SEGC+!SEGB),     //Char = =,   offset=52
( SEGN+!SEGE+!SEGF+ SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+!SEGL+!SEGK) , (!SEGC+!SEGB),     //Char = >,   offset=56
( SEGN+!SEGE+!SEGF+ SEGH) , (!SEGM+!SEGG+!SEGJ+ SEGA) , (!SEGD+!SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = ?,   offset=60
( SEGN+ SEGE+ SEGF+ SEGH) , ( SEGM+ SEGG+ SEGJ+ SEGA) , ( SEGD+ SEGL+ SEGK) , ( SEGC+ SEGB),     //Char = @,   offset=64
(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , (!SEGD+!SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = A,   offset=68
(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+!SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+!SEGB),     //Char = B,   offset=72
(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+!SEGK) , (!SEGC+!SEGB),     //Char = C,   offset=76
(!SEGN+ SEGE+!SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+!SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = D,   offset=80
(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+!SEGK) , (!SEGC+!SEGB),     //Char = E,   offset=84
(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , (!SEGD+!SEGL+!SEGK) , (!SEGC+!SEGB),     //Char = F,   offset=88
(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+!SEGB),     //Char = G,   offset=92
(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+!SEGA) , (!SEGD+!SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = H,   offset=96
(!SEGN+!SEGE+!SEGF+!SEGH) , ( SEGM+!SEGG+ SEGJ+ SEGA) , ( SEGD+!SEGL+!SEGK) , (!SEGC+!SEGB),     //Char = I,   offset=100
(!SEGN+ SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = J,   offset=104
(!SEGN+!SEGE+!SEGF+!SEGH) , ( SEGM+!SEGG+ SEGJ+!SEGA) , (!SEGD+ SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = K,   offset=108
(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , ( SEGD+!SEGL+!SEGK) , (!SEGC+!SEGB),     //Char = L,   offset=112
(!SEGN+ SEGE+ SEGF+ SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+!SEGL+ SEGK) , ( SEGC+ SEGB),     //Char = M,   offset=116
(!SEGN+ SEGE+ SEGF+ SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+ SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = N,   offset=120
(!SEGN+ SEGE+!SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+!SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+!SEGB),     //Char = O,   offset=124
(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , (!SEGD+!SEGL+!SEGK) , (!SEGC+ SEGB),     //Char = P,   offset=128
(!SEGN+!SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = Q,   offset=132
(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , (!SEGD+ SEGL+!SEGK) , (!SEGC+ SEGB),     //Char = R,   offset=136
(!SEGN+!SEGE+ SEGF+!SEGH) , (!SEGM+ SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+!SEGB),     //Char = S,   offset=140
(!SEGN+!SEGE+!SEGF+!SEGH) , ( SEGM+!SEGG+ SEGJ+ SEGA) , (!SEGD+!SEGL+!SEGK) , (!SEGC+!SEGB),     //Char = T,   offset=144
(!SEGN+ SEGE+ SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , ( SEGD+!SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = U,   offset=148
(!SEGN+!SEGE+!SEGF+ SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+ SEGL+!SEGK) , ( SEGC+ SEGB),     //Char = V,   offset=152
( SEGN+ SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+ SEGL+!SEGK) , ( SEGC+!SEGB),     //Char = W,   offset=156
( SEGN+!SEGE+!SEGF+ SEGH) , (!SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+ SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = X,   offset=160
(!SEGN+!SEGE+!SEGF+ SEGH) , ( SEGM+!SEGG+!SEGJ+!SEGA) , (!SEGD+!SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = Y,   offset=164
( SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = Z,   offset=168
( SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = [,   offset=172
( SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = \,   offset=176
( SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = ],   offset=180
( SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = ^,   offset=184
( SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = _,   offset=188
( SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = `,   offset=192
( SEGN+!SEGE+!SEGF+!SEGH) , (!SEGM+!SEGG+!SEGJ+ SEGA) , ( SEGD+!SEGL+ SEGK) , (!SEGC+!SEGB),     //Char = a,   offset=196

};

/*****************************************************************************************************
* Code of project wide FUNCTIONS
*****************************************************************************************************/

/****************************************************************************************************/
/**
* \brief  Initialize all the LCD registers on the mcu module   
* \author  Alejandra Guzmán Castellanos 
* \param  void 
* \return   void
* \todo     
*/
/****************************************************************************************************/
 void vfnLCD_Init  (void)
{

 // Disable LCD frame frequency interrupt and configure LCD Module to continue running
  // during wait and stop3 mode
  LCDC1 = 0x00;// | LCDC1_LCDIEN_MASK;
  
  pause_write();  
  
  // Configures 1/4 duty cycle and 128 as LCD clock input divider (LCLK=3)
  // LCD Waveform Base Clock = 256 Hz
  LCDC0 = 0x1B;
  pause_write();
 
#if 0 
/* Drive Vll3 internally from  Vdd*/ 
  LCDSUPPLY =(   LCDSUPPLY_VSUPPLY0_MASK    
              | !LCDSUPPLY_VSUPPLY1_MASK    
              |  LCDSUPPLY_BBYPASS_MASK   
                
              |  LCDSUPPLY_LADJ0_MASK       
              |  LCDSUPPLY_LADJ1_MASK       
              | !LCDSUPPLY_HREFSEL_MASK     
              |  LCDSUPPLY_CPSEL_MASK               // 1= LCD charge pump is selected
              );
 
#else

 /* 
    Configure for Vireg for 3V glass operation see table 24-22 of Reference Manual
    this Configuration allow to control Voltage
 
  */

  LCDSUPPLY =(   LCDSUPPLY_VSUPPLY0_MASK    
              |  LCDSUPPLY_VSUPPLY1_MASK    
              | !LCDSUPPLY_BBYPASS_MASK
                   
              |  LCDSUPPLY_LADJ0_MASK       
              | !LCDSUPPLY_LADJ1_MASK       
              | !LCDSUPPLY_HREFSEL_MASK     
              |  LCDSUPPLY_CPSEL_MASK               // 1= LCD charge pump is selected
              );
 LCDRVC_RVEN = 1; 

 
#endif
  
  pause_write();  
    
  //Configures 2 Hz as LCD blink frequency (blink only individual LCD segments)
  LCDBCTL = 0x02;
  pause_write();  

  //Enable the LCD module frontplane waveform output (FP[39:0])
  LCDPEN0 = 0xFF;
  pause_write();  
  
  LCDPEN1 = 0xFF;
  pause_write();  
  LCDPEN2 = 0xFF;
  pause_write();  
  LCDPEN3 = 0xFF;
  
  pause_write();  
  LCDPEN4 = 0xFF;
  pause_write();  
  LCDPEN5 = 0x0F;
  pause_write();  
  
  LCDBPEN0 = 0x0F;
  pause_write();    
   
 // Set COM on each back plane         
  LCDWF0 = 1;
  pause_write();  
  LCDWF1 = 2;
  pause_write();  
  LCDWF2 = 4;
  pause_write();  
  LCDWF3 = 8;
  pause_write();    
    
  //Enables LCD driver module
  LCDC0  |= 0x80;
  pause_write();  

  }


/****************************************************************************************************/
/**
* \brief   Writes one ASCII character on the next alphanumeric. The global variable gu8LCD_CharPosition 
will indicate the index of the next alphanumeric LCD register to write. 
* \author  Salazar Ruiz Saul Octavio
* \param   UINT8 u8Value --- Ascii to write  
* \return   void
* \todo     
*/
/****************************************************************************************************/
void vfnLCD_Write_Char (UINT8 u8Value)
{
          volatile UINT8 *pu8LCDWF = &LCDWF0;
          UINT8 u8Offset=0;
          UINT8 u8Counter ;
          UINT8 *pu8LCDWFCopy = (UINT8 *)&gu8RamBuffer[0];


 
       /*only ascci character if value not writeable write as @*/
          if (u8Value>='a' && u8Value<='z') u8Value &= ~0x20; // UpperCase
          if (u8Value<'(' || u8Value >'Z') u8Value = ':';        // default value as space
   
   
   
       
			
		      u8Value = (UINT8)((u8Value-'(')*_LCDTYPE);								/**Find the value at the ascii table*/
          u8Counter = _LCDTYPE;																/**Set the number of waveforms needed to write one alphanumeric*/
          
          while (u8Counter--)
          {
          
             u8Offset = aPlace[gu8LCD_CharPosition];											/**Find the Waveform offset*/                       
     
     
      // Remove current waveforms from RamBuffer        
		//	   *(pu8LCDWFCopy + u8Offset)&=(~(aBackup[u8Counter] & 0xFF));	/**Backup of the waveforms*/
		
    
     // Remove current waveforms from RamBuffer        
			   *(pu8LCDWFCopy + u8Offset)&=(aBackup[u8Counter]);	
		// Add the new segements to be turned on	   
             *(pu8LCDWFCopy + u8Offset) |= aAscii[u8Value];
       
   // update LCDWF registers          
			*(pu8LCDWF + u8Offset) = *(pu8LCDWFCopy + u8Offset);
			pause_write();			
				
				
		///		*(pu8LCDWF + u8Offset) =  aAscii[u8Value];			/**Write the value to the waveform*/
				
				
             u8Value++;  
              gu8LCD_CharPosition++;           
          }            
  
}

/****************************************************************************************************/
/**
* \brief Writes one string  on the LCD starting at the first alphanumeric,  this function will stop to write if the size of 
the string is bigger than the number of alphanumerics available at the custom glass (_CHARNUM). In case of smaller strings 
than the alphanumerics available the exceeding places will be writing with ASCII spaces.
* \author  Alejandra Guzmán Castellanos 
* \param   UINT8 *pu8Message  --- pointer to the first ascii number of the string  to write   
* \return   void
* \todo     
*/
/****************************************************************************************************/
void  vfnLCD_Write_Msg (UINT8 * pu8Message)
 {
     UINT8 u8Counter;          
     vfnLCD_Home ();						/**Point to the first alphanumeric 	gu8LCD_CharPosition = 0*/
     u8Counter = _CHARNUM;
     
     
    while (u8Counter--)						
    {
      if (*pu8Message)						/**Write  String*/						 
      {
      
         vfnLCD_Write_Char (*pu8Message);
         pu8Message ++;
      }
      else								/**Write Blanks*/ 
      {
      	vfnLCD_Write_Char(' ');
      }
    }
      
      _LCD_FREESCALE_ON;      
      
 }

/****************************************************************************************************/
/**
* \brief  Writes one string  on the LCD starting at the first alphanumeric,  this function will stop to write if the size of 
the string is bigger than the number of alphanumeric available at the custom glass (_CHARNUM). In case  of smaller 
strings than the alphanumerics available.
* \author  Alejandra Guzmán Castellanos 
* \param   UINT8 *pu8Message  --- pointer to the first ascii number of the string  to write 
* \param   UINT8 u8NumChars  --- number of characters to write from the string
* \param   UINT8 u8Place  --- alphanumeric number to start writing 
* \return   void
* \todo     
*/
/****************************************************************************************************/
void  vfnLCD_Write_MsgPlace(UINT8 * pu8Message, UINT8 u8NumChars, UINT8 u8Place)
 {    
    vfnLCD_GoTo(u8Place);						/**Point to the alphanumeric*/
   
    while (u8NumChars--)							/**Write String*/ 
    {
       if (gu8LCD_CharPosition <= _CHARNUM*_LCDTYPE) 
       {
	       vfnLCD_Write_Char (*pu8Message);
	       pu8Message ++;     
       }
    }
 } 

/****************************************************************************************************/
/**
* \brief  Turns off  all the segments of the LCD    
* \author  Alejandra Guzmán Castellanos 
* \param  void 
* \return   void
* \todo     
*/
/****************************************************************************************************/
void vfnLCD_Set_Display (void)
{
	SEGMENT1_ON;  pause_write();
	SEGMENT2_ON;  pause_write();
	SEGMENT3_ON;  pause_write();
	SEGMENT4_ON;  pause_write();
	SEGMENT5_ON;  pause_write();
	SEGMENT6_ON;  pause_write();
	SEGMENT7_ON;  pause_write();
	SEGMENT8_ON;  pause_write();
	SEGMENT9_ON;  pause_write();
	SEGMENT10_ON; pause_write();
	SEGMENT11_ON; pause_write();
	SEGMENT12_ON; pause_write();
	SEGMENT13_ON; pause_write();
	SEGMENT14_ON; pause_write();
	SEGMENT15_ON; pause_write();
	SEGMENT16_ON; pause_write();
	SEGMENT17_ON; pause_write();
	SEGMENT18_ON; pause_write();
	SEGMENT19_ON; pause_write();
	SEGMENT20_ON; pause_write();
	SEGMENT21_ON; pause_write();
	SEGMENT22_ON; pause_write();
	SEGMENT23_ON; pause_write();
	SEGMENT24_ON; pause_write();
	SEGMENT25_ON; pause_write();
	SEGMENT26_ON; pause_write();
	SEGMENT27_ON; pause_write();
	SEGMENT28_ON; pause_write();
	SEGMENT29_ON; pause_write();
	SEGMENT30_ON; pause_write();
	SEGMENT31_ON; pause_write();
	SEGMENT32_ON; pause_write();
	SEGMENT33_ON; pause_write();
	SEGMENT34_ON; pause_write();
	SEGMENT35_ON; pause_write();
	SEGMENT36_ON; pause_write();
	SEGMENT37_ON; pause_write();
	SEGMENT38_ON; pause_write();
	SEGMENT39_ON; pause_write();
	SEGMENT40_ON; pause_write();

}

/****************************************************************************************************/
/**
* \brief  Turns on  all the segments of the LCD    
* \author  Alejandra Guzmán Castellanos 
* \param  void 
* \return   void
* \todo     
*/
/****************************************************************************************************/
void vfnLCD_Clear_Display (void)
{
	SEGMENT1_OFF;  pause_write();
	SEGMENT2_OFF;  pause_write();
	SEGMENT3_OFF;  pause_write();
	SEGMENT4_OFF;  pause_write();
	SEGMENT5_OFF;  pause_write();
	SEGMENT6_OFF;  pause_write();
	SEGMENT7_OFF;  pause_write();
	SEGMENT8_OFF;  pause_write();
	SEGMENT9_OFF;  pause_write();
	SEGMENT10_OFF; pause_write();
	SEGMENT11_OFF; pause_write();
	SEGMENT12_OFF; pause_write();
	SEGMENT13_OFF; pause_write();
	SEGMENT14_OFF; pause_write();
	SEGMENT15_OFF; pause_write();
	SEGMENT16_OFF; pause_write();
	SEGMENT17_OFF; pause_write();
	SEGMENT18_OFF; pause_write();
	SEGMENT19_OFF; pause_write();
	SEGMENT20_OFF; pause_write();
	SEGMENT21_OFF; pause_write();
	SEGMENT22_OFF; pause_write();
	SEGMENT23_OFF; pause_write();
	SEGMENT24_OFF; pause_write();
	SEGMENT25_OFF; pause_write();
	SEGMENT26_OFF; pause_write();
	SEGMENT27_OFF; pause_write();
	SEGMENT28_OFF; pause_write();
	SEGMENT29_OFF; pause_write();
	SEGMENT30_OFF; pause_write();
	SEGMENT31_OFF; pause_write();
	SEGMENT32_OFF; pause_write();
	SEGMENT33_OFF; pause_write();
	SEGMENT34_OFF; pause_write();
	SEGMENT35_OFF; pause_write();
	SEGMENT36_OFF; pause_write();
	SEGMENT37_OFF; pause_write();
	SEGMENT38_OFF; pause_write();
	SEGMENT39_OFF; pause_write();
	SEGMENT40_OFF; pause_write();
}

/****************************************************************************************************/
/**
* \brief  Enable all the pins of the mcu directly connected to the  LCD on use    
* \author  Alejandra Guzmán Castellanos 
* \param  void 
* \return   void
* \todo     
*/
/****************************************************************************************************/
void vfnEnablePins (void)
  {
  	_PEN0();										/** Give to the LCDx the functionality  of a LCD pin*/
  	_PEN1();
  	_PEN2();
  	_PEN3();
   _PEN4();
   _PEN5();
  }
  
/****************************************************************************************************/
/**
* \brief   Enable the function of Backplane and Set the COM number that corresponds to each backplane
* \author  Alejandra Guzmán Castellanos 
* \param  void 
* \return   void
* \todo     
*/
/****************************************************************************************************/
  void vfnLCD_ConfigureBackplanes (void)
  {
          
          LCDBPEN0 = 0;
          LCDBPEN1 = 0;
          LCDBPEN2 = 0;
          LCDBPEN3 = 0;
          LCDBPEN4 = 0;
            
	_BPEN0(); 										/**Enable the characterisitcs of a Backplane*/
	_BPEN1();
	_BPEN2();
	_BPEN3();
   _BPEN4();

    _SETCOM1();										/**Give to each backplane previously enbale his COM number*/
	_SETCOM2();  
	_SETCOM3();  
	_SETCOM4();  
}
