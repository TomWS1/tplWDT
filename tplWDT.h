/*=============================================================================
*   tplWDT.h - source code for WDT using TPL5010
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
//#define USE_SERIAL    // comment to remove all Serial code when testing actual power consumption
//#define DEBUG_MODE    // force shorter timeout cycles

#ifndef __TPL_WDT_H__
#define __TPL_WDT_H__

extern volatile bool
  bWake_IRQ;
  
void initTPL(uint8_t wakePin, uint8_t donePin);
void signalDone(void);

#endif
