/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PE_Error.h
**     Project     : ECE 594 Project_Group 1
**     Processor   : MCF51EM256CLL
**     Component   : PE_Error
**     Version     : Driver 01.00
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2021-11-17, 16:20, # CodeGen: 1
**     Abstract    :
**         This component "PE_Error" contains internal definitions
**         of the error constants.
**     Contents    :
**         No public methods
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file PE_Error.h
** @version 01.00
** @brief
**         This component "PE_Error" contains internal definitions
**         of the error constants.
*/         
/*!
**  @addtogroup PE_Error_module PE_Error module documentation
**  @{
*/         

#ifndef __PE_Error_H
#define __PE_Error_H

#define ERR_OK           0             /* OK */
#define ERR_SPEED        1             /* This device does not work in the active speed mode. */
#define ERR_RANGE        2             /* Parameter out of range. */
#define ERR_VALUE        3             /* Parameter of incorrect value. */
#define ERR_OVERFLOW     4             /* Timer overflow. */
#define ERR_MATH         5             /* Overflow during evaluation. */
#define ERR_ENABLED      6             /* Device is enabled. */
#define ERR_DISABLED     7             /* Device is disabled. */
#define ERR_BUSY         8             /* Device is busy. */
#define ERR_NOTAVAIL     9             /* Requested value or method not available. */
#define ERR_RXEMPTY      10            /* No data in receiver. */
#define ERR_TXFULL       11            /* Transmitter is full. */
#define ERR_BUSOFF       12            /* Bus not available. */
#define ERR_OVERRUN      13            /* Overrun error is detected. */
#define ERR_FRAMING      14            /* Framing error is detected. */
#define ERR_PARITY       15            /* Parity error is detected. */
#define ERR_NOISE        16            /* Noise error is detected. */
#define ERR_IDLE         17            /* Idle error is detected. */
#define ERR_FAULT        18            /* Fault error is detected. */
#define ERR_BREAK        19            /* Break char is received during communication. */
#define ERR_CRC          20            /* CRC error is detected. */
#define ERR_ARBITR       21            /* A node losts arbitration. This error occurs if two nodes start transmission at the same time. */
#define ERR_PROTECT      22            /* Protection error is detected. */
#define ERR_UNDERFLOW    23            /* Underflow error is detected. */
#define ERR_UNDERRUN     24            /* Underrun error is detected. */
#define ERR_COMMON       25            /* Common error of a device. */
#define ERR_LINSYNC      26            /* LIN synchronization error is detected. */
#define ERR_FAILED       27            /* Requested functionality or process failed. */
#define ERR_QFULL        28            /* Queue is full. */

#endif __PE_Error_H
