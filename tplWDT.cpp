/*=============================================================================
*   tplWDT.cpp - source code for WDT using TPL5010
*
*******************************************************************************/
//   Copyright (c) 2016, Liminal System Designs
//
// **********************************************************************************
// License
// **********************************************************************************
// This program is free software; you can redistribute it 
// and/or modify it under the terms of the GNU General    
// Public License as published by the Free Software       
// Foundation; either version 3 of the License, or        
// (at your option) any later version.                    
//                                                        
// This program is distributed in the hope that it will   
// be useful, but WITHOUT ANY WARRANTY; without even the  
// implied warranty of MERCHANTABILITY or FITNESS FOR A   
// PARTICULAR PURPOSE. See the GNU General Public        
// License for more details.                              
//                                                        
// You should have received a copy of the GNU General    
// Public License along with this program.
// If not, see <http://www.gnu.org/licenses/>.
//                                                        
// License can be viewed at                               
// http://www.gnu.org/licenses/gpl-3.0.txt
//
// Please maintain this license information along with authorship
// and copyright notices in any redistribution of this code
// **********************************************************************************
//======================================================================
#include <Arduino.h>
#include <tplWDT.h>

volatile bool
  bWake_IRQ=false;
  
static uint8_t
  _wakePin=0,
  _donePin=0;
  
//==================================================================
//
//==================================================================
static void WAKE_IRQ_HANDLER(void)
{
  bWake_IRQ = true;
}


//==================================================================
//
//==================================================================
void initTPL(uint8_t wakePin, uint8_t donePin)
{
  _wakePin = wakePin;
  _donePin = donePin;
  
  digitalWrite(_donePin,LOW);
  pinMode(_donePin, OUTPUT);
  pinMode(_wakePin, INPUT);
  bWake_IRQ = false;
  attachInterrupt(digitalPinToInterrupt(_wakePin), WAKE_IRQ_HANDLER, RISING);
  signalDone();
}

//==================================================================
//
//==================================================================
void signalDone(void)
{
  bWake_IRQ = false;
  digitalWrite(_donePin,HIGH);
  delayMicroseconds(2);        // need to guarantee 100nS minimum, this will do it for all processor clock frequencies
  digitalWrite(_donePin,LOW);
}


