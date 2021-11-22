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
* Module definition against multiple inclusion
*****************************************************************************************************/
#ifndef __LCD_HAL_H
#define __LCD_HAL_H

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Variable types and common definitions */
#include "FslTypes.h"

#define MC9S08LL16

/*****************************************************************************************************
* Declaration of project wide TYPES
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of project wide VARIABLES
*****************************************************************************************************/

/*****************************************************************************************************
* Definition of project wide MACROS / #DEFINE-CONSTANTS 
*****************************************************************************************************/

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^      LCD Configuration                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

#define _LCDBACKPLANES			(4)	/** # of backplanes  */

#define _LCDCLKSOURCE			(1)	   /** 0 -- External clock       1 --  Alternate clock  (Internal)*/


#define _LCDCLKPSL					(3)	/**Clock divider to generate the LCD Waveforms*/


#define _LCDCPSEL						(1)		/**0 -- Resistor network   1 -- Charge pump */ 
#define _LCDVSUPPLY					(1)		/**0  --  VLL2 from VDD    1 --   VLL3 from VDD  2 -- VLL1 from VLCD  3 -- VLL3 external or from VIREG*/

#define _LCDLOADADJUST			(0)	/**Charge pump 		0 -- 8000 pf 1 -- 6000 pf  2 -- 4000 pf  3 -- 2000 pf
                                                     Resistor Network		0 -- 2000 pf 1 -- 2000 pf  2 -- 8000 pf   3 -- 8000 pf*/ 

#define _LCDFRAMEINTERRUPT	(0)	/**0 Disabel  Interrupt 1 Enable aLCD interrupt that coincides with the LCD frame frequency*/

#define _LCDBLINKRATE				(0)	/**Blink frequecy preescaler  any number between 0-7*/

#define _CHARNUM					(9)	/** Number of characters on the display*/

#define _LCDTYPE						(4)	/**Number of LCDWF  nedded  to drive one character*/ 

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^      LCD Hardware Connection 			 ^^^^^^^^^^^^^^^^^^^^^^^^*/

#define EnableLCDpins(RegNum,Mask)			LCDPEN##RegNum = Mask
#define  EnableBackplanes(RegNum, Mask)	LCDBPEN##RegNum = Mask   
#define  SetBackplane(ComNum, LCDn)		LCDWF##LCDn  = 1 <<  ComNum
#define  CharacterPlace(LCDn)        				LCDn
#define AllSegmentsON(LCDn,ComMask)		LCDWF##LCDn = ComMask ; 

#define SymbolON(LCDn, BitNumber)			(gu8RamBuffer[LCDn] |= (byte)(1<< BitNumber)); LCDWF##LCDn = gu8RamBuffer[LCDn]
#define SymbolOFF(LCDn, BitNumber)		(gu8RamBuffer[LCDn] &= ~(1<< BitNumber)); LCDWF##LCDn = gu8RamBuffer[LCDn]


#define MapSegment(BitNumber)  				1<< BitNumber 
#define LCDWFRef          							LCDWF0
#define LCD_AlphanumericPlace(Place)			bLCD_CharPosition=_LCDTYPE*##(Place-1)
/**
EnableLCDpins
Habilitate the mcu pin with the characteristics of a LCD pin 
param: RegNum -- Number of register to write     Mask --- Mask that habilitate the LCDx pins
*/
	#define _PEN0()       EnableLCDpins (0,255)
	#define _PEN1()       EnableLCDpins (1,255)
	#define _PEN2()       EnableLCDpins (2,255)
	#define _PEN3()       EnableLCDpins (3,255)
	#define _PEN4()       EnableLCDpins (4,255)
	#define _PEN5()       EnableLCDpins (5,15)


/** 
EnableBackplanes
Enable the LCD pin like a Backplane functionality  
param: RegNum -- Number of register to write     LCDpin --- LCDn pin number that the Backplane it's connected 
*/
	#define   _BPEN0()        EnableBackplanes (0, 15)
	#define   _BPEN1()        EnableBackplanes (1, 0)
	#define   _BPEN2()        EnableBackplanes (2, 0)
	#define   _BPEN3()        EnableBackplanes (3, 0)
	#define   _BPEN4()        EnableBackplanes (4, 0)	

/**
SetBackplane
 Give the COM number  to the previous enable Backplane     
param: ComNum -- COM number     LCDpin --- LCDn number of pin that its connected  
*/
#define   _SETCOM1()        SetBackplane (0, 0)
#define   _SETCOM2()        SetBackplane (1, 1)
#define   _SETCOM3()        SetBackplane (2, 2)
#define   _SETCOM4()        SetBackplane (3, 3)

/**
Character place
This macro defines the LDCWavefroms directions needed for write the alphanumerics        
param:  LCDpin --- LCDn number of pin that its connected */
#define   CHAR1A         (4)  // LCD Pin 5
#define   CHAR1B         (5)  // LCD Pin 6
#define   CHAR1C         (6)  // LCD Pin 7
#define   CHAR1D         (7)  // LCD Pin 8
#define   CHAR2A         (8)  // LCD Pin 9
#define   CHAR2B         (9)  // LCD Pin 10
#define   CHAR2C         (10)  // LCD Pin 11
#define   CHAR2D         (11)  // LCD Pin 12
#define   CHAR3A         (12)  // LCD Pin 44
#define   CHAR3B         (13)  // LCD Pin 43
#define   CHAR3C         (14)  // LCD Pin 42
#define   CHAR3D         (15)  // LCD Pin 41
#define   CHAR4A         (16)  // LCD Pin 40
#define   CHAR4B         (17)  // LCD Pin 39
#define   CHAR4C         (18)  // LCD Pin 38
#define   CHAR4D         (19)  // LCD Pin 37
#define   CHAR5A         (20)  // LCD Pin 36
#define   CHAR5B         (21)  // LCD Pin 35
#define   CHAR5C         (22)  // LCD Pin 34
#define   CHAR5D         (23)  // LCD Pin 33
#define   CHAR6A         (24)  // LCD Pin 32
#define   CHAR6B         (25)  // LCD Pin 31
#define   CHAR6C         (26)  // LCD Pin 30
#define   CHAR6D         (27)  // LCD Pin 29
#define   CHAR7A         (28)  // LCD Pin 13
#define   CHAR7B         (29)  // LCD Pin 14
#define   CHAR7C         (30)  // LCD Pin 15
#define   CHAR7D         (31)  // LCD Pin 16
#define   CHAR8A         (32)  // LCD Pin 17
#define   CHAR8B         (33)  // LCD Pin 18
#define   CHAR8C         (34)  // LCD Pin 19
#define   CHAR8D         (35)  // LCD Pin 20
#define   CHAR9A         (36)  // LCD Pin 21
#define   CHAR9B         (37)  // LCD Pin 22
#define   CHAR9C         (38)  // LCD Pin 23
#define   CHAR9D         (39)  // LCD Pin 24

/**
AllSegmentsON
Turns on all the segments of the custom glass   
param: LCDn -- LCDWF that needs to be turn on	ComMask -- Bits that are turn on example: 8 COM = 255   2 COM = 3
*/
	#define SEGMENT1_ON          AllSegmentsON(4,15)
	#define SEGMENT2_ON          AllSegmentsON(5,15)
	#define SEGMENT3_ON          AllSegmentsON(6,15)
	#define SEGMENT4_ON          AllSegmentsON(7,15)
	#define SEGMENT5_ON          AllSegmentsON(8,15)
	#define SEGMENT6_ON          AllSegmentsON(9,15)
	#define SEGMENT7_ON          AllSegmentsON(10,15)
	#define SEGMENT8_ON          AllSegmentsON(11,15)
	#define SEGMENT9_ON          AllSegmentsON(28,15)
	#define SEGMENT10_ON         AllSegmentsON(29,15)
	#define SEGMENT11_ON         AllSegmentsON(30,15)
	#define SEGMENT12_ON         AllSegmentsON(31,15)
	#define SEGMENT13_ON         AllSegmentsON(32,15)
	#define SEGMENT14_ON         AllSegmentsON(33,15)
	#define SEGMENT15_ON         AllSegmentsON(34,15)
	#define SEGMENT16_ON         AllSegmentsON(35,15)
	#define SEGMENT17_ON         AllSegmentsON(36,15)
	#define SEGMENT18_ON         AllSegmentsON(37,15)
	#define SEGMENT19_ON         AllSegmentsON(38,15)
	#define SEGMENT20_ON         AllSegmentsON(39,15)
	#define SEGMENT21_ON         AllSegmentsON(40,15)
	#define SEGMENT22_ON         AllSegmentsON(41,15)
	#define SEGMENT23_ON         AllSegmentsON(42,15)
	#define SEGMENT24_ON         AllSegmentsON(43,15)
	#define SEGMENT25_ON         AllSegmentsON(27,15)
	#define SEGMENT26_ON         AllSegmentsON(26,15)
	#define SEGMENT27_ON         AllSegmentsON(25,15)
	#define SEGMENT28_ON         AllSegmentsON(24,15)
	#define SEGMENT29_ON         AllSegmentsON(23,15)
	#define SEGMENT30_ON         AllSegmentsON(22,15)
	#define SEGMENT31_ON         AllSegmentsON(21,15)
	#define SEGMENT32_ON         AllSegmentsON(20,15)
	#define SEGMENT33_ON         AllSegmentsON(19,15)
	#define SEGMENT34_ON         AllSegmentsON(18,15)
	#define SEGMENT35_ON         AllSegmentsON(17,15)
	#define SEGMENT36_ON         AllSegmentsON(16,15)
	#define SEGMENT37_ON         AllSegmentsON(15,15)
	#define SEGMENT38_ON         AllSegmentsON(14,15)
	#define SEGMENT39_ON         AllSegmentsON(13,15)
	#define SEGMENT40_ON         AllSegmentsON(12,15)

/**
AllSegmentsOFF
Turns on all the segments of the custom glass   
param: LCDn -- LCDWF that needs to be turn on	ComMask -- Bits that are turn on example: 8 COM = 255   2 COM = 3*/
	#define SEGMENT1_OFF         AllSegmentsON (4,0)
	#define SEGMENT2_OFF         AllSegmentsON (5,0)
	#define SEGMENT3_OFF         AllSegmentsON (6,0)
	#define SEGMENT4_OFF         AllSegmentsON (7,0)
	#define SEGMENT5_OFF         AllSegmentsON (8,0)
	#define SEGMENT6_OFF         AllSegmentsON (9, 0)
	#define SEGMENT7_OFF         AllSegmentsON (10,0)
	#define SEGMENT8_OFF         AllSegmentsON (11,0)
	#define SEGMENT9_OFF         AllSegmentsON (28,0)
	#define SEGMENT10_OFF        AllSegmentsON (29,0)
	#define SEGMENT11_OFF        AllSegmentsON (30,0)
	#define SEGMENT12_OFF        AllSegmentsON (31,0)
	#define SEGMENT13_OFF        AllSegmentsON (32,0)
	#define SEGMENT14_OFF        AllSegmentsON (33,0)
	#define SEGMENT15_OFF        AllSegmentsON (34,0)
	#define SEGMENT16_OFF        AllSegmentsON (35,0)
	#define SEGMENT17_OFF        AllSegmentsON (36,0)
	#define SEGMENT18_OFF        AllSegmentsON (37,0)
	#define SEGMENT19_OFF        AllSegmentsON (38,0)
	#define SEGMENT20_OFF        AllSegmentsON (39,0)
	#define SEGMENT21_OFF        AllSegmentsON (40,0)
	#define SEGMENT22_OFF        AllSegmentsON (41,0)
	#define SEGMENT23_OFF        AllSegmentsON (42,0)
	#define SEGMENT24_OFF        AllSegmentsON (43,0)
	#define SEGMENT25_OFF        AllSegmentsON (27,0)
	#define SEGMENT26_OFF        AllSegmentsON (26,0)
	#define SEGMENT27_OFF        AllSegmentsON (25,0)
	#define SEGMENT28_OFF        AllSegmentsON (24,0)
	#define SEGMENT29_OFF        AllSegmentsON (23,0)
	#define SEGMENT30_OFF        AllSegmentsON (22,0)
	#define SEGMENT31_OFF        AllSegmentsON (21,0)
	#define SEGMENT32_OFF        AllSegmentsON (20,0)
	#define SEGMENT33_OFF        AllSegmentsON (19,0)
	#define SEGMENT34_OFF        AllSegmentsON (18,0)
	#define SEGMENT35_OFF        AllSegmentsON (17,0)
	#define SEGMENT36_OFF        AllSegmentsON (16,0)
	#define SEGMENT37_OFF        AllSegmentsON (15,0)
	#define SEGMENT38_OFF        AllSegmentsON (14,0)
	#define SEGMENT39_OFF        AllSegmentsON (13,0)
	#define SEGMENT40_OFF        AllSegmentsON (12,0)
/** 
SymbolON
Turns on the  segment that its dedicated to write one Symbol     
param:  LCDpin --- LCDn number of pin that its connected   BitNumber -- COM Number that turns on that Symbol 
*/
	#define _LCD_FREESCALE_ON 	SymbolON(14,3)
	#define _LCD_FIRE_ON			  SymbolON(15,3)
	#define _LCD_SNOW_ON		    SymbolON(19,3)
	#define _LCD_CLOCK_ON		    SymbolON(26,3)
	#define _LCD_BATTERY_ON	    SymbolON(27,3)
	#define _LCD_VOLUME_ON	    SymbolON(42,0)
	#define _LCD_POWER_ON		    SymbolON(30,3)
	#define _LCD_VOL1_ON		   	SymbolON(39,3)
	#define _LCD_VOL2_ON			  SymbolON(40,0)
	#define _LCD_VOL3_ON			  SymbolON(42,1)
	#define _LCD_VOL4_ON			  SymbolON(42,2)
	#define _LCD_VOL5_ON			  SymbolON(42,3)
	#define _LCD_DATE_ON			  SymbolON(10,3)
	#define _LCD_OHM_ON			    SymbolON(40,3)
	#define _LCD_DOT1_ON			  SymbolON(7,2)
	#define _LCD_DOT2_ON			  SymbolON(11,3)
	#define _LCD_DOT3_ON			  SymbolON(23,2)
	#define _LCD_DOT4_ON			  SymbolON(23,2)
	#define _LCD_DOT5_ON			  SymbolON(23,3)
	#define _LCD_DOT6_ON			  SymbolON(27,2)
	#define _LCD_DOT7_ON			  SymbolON(31,3)
	#define _LCD_DOT8_ON			  SymbolON(35,2)
	#define _LCD_DOT9_ON			  SymbolON(39,2)
	#define _LCD_COL1_ON			  SymbolON(11,2)
	#define _LCD_COL2_ON			  SymbolON(23,2)
	#define _LCD_COL3_ON			  SymbolON(31,2)
	#define _LCD_COL4_ON			  SymbolON(38,3)
	#define _LCD_MINUS_ON		    SymbolON(7,3)
	#define _LCD_KWhr_ON			  SymbolON(41,0)
	#define _LCD_AMPS_ON			  SymbolON(41,1)
	#define _LCD_VOLTS_ON		    SymbolON(41,2)
	#define _LCD_PROGRAM_ON     SymbolON(41,3)
	#define _LCD_AM_ON				  SymbolON(40,1)
	#define _LCD_PM_ON				  SymbolON(40,2)
	#define _LCD_TEMP_ON			  SymbolON(3,0)
	#define _LCD_CONTRAST_ON    SymbolON(34,3)
	#define _LCD_MODE_ON		    SymbolON(35,3)

/**
SymbolOFF
 Turns off the  segment   that its dedicated to write one Symbol     
param:  LCDpin --- LCDn number of pin that its connected   BitNumber -- COM Number that turns off that Symbol 
*/
	#define _LCD_FREESCALE_OFF  SymbolOFF(14,3)
	#define _LCD_FIRE_OFF			  SymbolOFF(15,3)
	#define _LCD_SNOW_OFF		    SymbolOFF(19,3)
	#define _LCD_CLOCK_OFF		  SymbolOFF(26,3)
	#define _LCD_BATTERY_OFF	  SymbolOFF(27,3)
	#define _LCD_VOLUME_OFF	    SymbolOFF(42,0)
	#define _LCD_POWER_OFF	  	SymbolOFF(30,3)
	#define _LCD_VOL1_OFF		  	SymbolOFF(39,3)
	#define _LCD_VOL2_OFF		  	SymbolOFF(40,0)
	#define _LCD_VOL3_OFF		  	SymbolOFF(42,1)
	#define _LCD_VOL4_OFF		  	SymbolOFF(42,2)
	#define _LCD_VOL5_OFF		  	SymbolOFF(42,3)
	#define _LCD_DATE_OFF		  	SymbolOFF(10,3)
	#define _LCD_OHM_OFF		  	SymbolOFF(40,3)
	#define _LCD_DOT1_OFF		  	SymbolOFF( 7,2)
	#define _LCD_DOT2_OFF	    	SymbolOFF(11,3)
	#define _LCD_DOT3_OFF	    	SymbolOFF(23,2)
	#define _LCD_DOT4_OFF		    SymbolOFF(23,2)
	#define _LCD_DOT5_OFF		    SymbolOFF(23,3)
	#define _LCD_DOT6_OFF		    SymbolOFF(27,2)
	#define _LCD_DOT7_OFF		    SymbolOFF(31,3)
	#define _LCD_DOT8_OFF		    SymbolOFF(35,2)
	#define _LCD_DOT9_OFF		    SymbolOFF(39,2)
	#define _LCD_COL1_OFF		  	SymbolOFF(11,2)
	#define _LCD_COL2_OFF		  	SymbolOFF(23,2)
	#define _LCD_COL3_OFF		  	SymbolOFF(31,2)
	#define _LCD_COL4_OFF		  	SymbolOFF(38,3)
	#define _LCD_MINUS_OFF	  	SymbolOFF( 7,3)
	#define _LCD_KWhr_OFF	  		SymbolOFF(41,0)
	#define _LCD_AMPS_OFF			  SymbolOFF(41,1)
	#define _LCD_VOLTS_OFF		  SymbolOFF(41,2)
	#define _LCD_PROGRAM_OFF    SymbolOFF(41,3)
	#define _LCD_AM_OFF		    	SymbolOFF(40,1)
	#define _LCD_PM_OFF			  	SymbolOFF(40,2)
	#define _LCD_TEMP_OFF		  	SymbolOFF( 3,3)
	#define _LCD_CONTRAST_OFF   SymbolOFF(34,3)
	#define _LCD_MODE_OFF		    SymbolOFF(35,3)

/**
Name Segments 
Create a mask to turn on alphanumeric segments
*/ 

          #define  SEG1               MapSegment (H,0)
          #define  SEG2               MapSegment (F,1)
          #define  SEG3               MapSegment (E,2)
          #define  SEG4               MapSegment (N,3)

          #define  SEG5               MapSegment (A,0)
          #define  SEG6               MapSegment (J,1)
          #define  SEG7               MapSegment (G,2)
          #define  SEG8               MapSegment (M,3)
          
          
          #define  SEG9               MapSegment (K,0)
          #define  SEG10              MapSegment (L,1)
          #define  SEG11              MapSegment (D,2)
          
          
          #define  SEG12              MapSegment (B,0)
          #define  SEG13              MapSegment (C,1)




/*Map segment to COM mask*/
#define  SEGB   0x01
#define  SEGC   0x02

#define  SEGH   0x01
#define  SEGF   0x02
#define  SEGE   0x04
#define  SEGN   0x08

#define  SEGA   0x01
#define  SEGJ   0x02
#define  SEGG   0x04
#define  SEGM   0x08

#define  SEGK   0x01
#define  SEGL   0x02
#define  SEGD   0x04


#define _Backupa		((SEGN+ SEGE+ SEGF+ SEGH) ^ 0xFF)
#define _Backupb		((SEGM+ SEGG+ SEGJ+ SEGA)	^ 0xFF)
#define _Backupc		((SEGD+ SEGL+ SEGK)  ^ 0xFF)
#define _Backupd		((SEGC+ SEGB) ^ 0xFF)		 




/*****************************************************************************************************
* Declaration of project wide FUNCTIONS
*****************************************************************************************************/

/*****************************************************************************************************
* Declaration of module wide FUNCTIONs - NOT for use in other modules
*****************************************************************************************************/
void  vfnLCD_Write_Msg (UINT8 * pu8Message);
void vfnLCD_Init  (void);
void vfnLCD_Set_Display (void);
void vfnLCD_Clear_Display (void);
#endif /* __LCD_HAL_H */
