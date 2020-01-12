/*************************************************
   powerDownWakeTPL_Done.ino - Example of using tplWDT library.
   
   Code derived from powerDownWakeExternalInterrupt.ino from the
   Low-Power library Examples.
   
   This code initializes the TPL5010 interface to its two pins, Wake and Done.
   The third pin, RESET, is assumed to be tied to the processor reset pin with 
   an external pullup resistor.
   On startup, the initTPL function is called with the two pins identified.
   initTPL() will initialize the pinModes and attach the Wake pin to a processor
   interrupt. It also calls signalDone() function to pulse the Done pin once,
   which must be done after device power on.
   
   After that, the code simply goes to sleep, is woken up by the interrupt,
   and, if the interrupt was from the TPL5010, signals 'Done' and goes back to sleep.
   If signalDone() is NOT called within two timeout periods, the processor
   will be reset.
   
***************************************************/  

// **** INCLUDES *****
#include "LowPower.h"
#include <tplWDT.h>

// Define TPL5010 interface pins
#define wakeUpPin 3
#define donePin   4


void setup()
{
    initTPL(wakeUpPin,donePin);
}

void loop() 
{
    // Enter power down state with ADC and BOD module disabled.
    // Wake up when wake up pin is low.
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
    
    // Woken up!  Why?
    if (bWake_IRQ) {
      // Do something here
      // Example: Read sensor, data logging, data transmission.
      //...
      signalDone();  // since we've gotten the wake, signal done
    } else {
      // woke up for some other reason!! Don't know, don't care!
      // but DON'T signal Done! that will spoil the Watchdog feature.
    }
}
