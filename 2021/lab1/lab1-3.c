/* 
 * File: main
 * 
 * Author: James A. Smith
 * 
 * Based on Oli Glaser's PIC16 files "Getting started with PIC Microcontrollers"
 * http://blog.irwellsprings.com/getting-started-with-pic-microcontrollers/
 * 
 * Life after PLIB and before Harmony.  The code in EECS 2021 has to be written
 * without the handy macros in PLIB.
 * 
 * While PLIB was really nice, it's not supported anymore.  Harmony is not ready
 * and is overkill... bad pedagogically. 
 * 
 *  References:
 *  1. http://ww1.microchip.com/downloads/en/DeviceDoc/61105E.pdf
 *  2. http://umassamherstm5.org/tech-tutorials/pic32-tutorials/pic32mx220-tutorials/interrupts
 *  3. http://www.johnloomis.org/microchip/pic32/include/peripheral/timer.h.html
 *  4. http://blog.irwellsprings.com/getting-started-with-pic-microcontrollers/
 *  5. http://www.eevblog.com/forum/microcontrollers/pic32mx-quickstart/10/?wap2
 *  6. http://microchip.wikidot.com/32bit:mx-osc-config
 *
 */

// xc.h is the main include file - this contains all the "friendly names"
// for the PIC32 pins and peripherals
#include <xc.h>


// ------------------------  Configuration (begin) ----------------------------
//  There are Four configuration words that need to be dealt with:
// Config. Word 3, Config. Word 2,  Config. Word 1 and Config. Word 0,
// in that order.

// Configuration Word 3 (User ID info)
// This is for the PIC32MX250 with internal fast RC clock @ 8 MHz
// Internal system clock ("sysclock") will run at 187.5 kHz
// using FNOSC, FPLLIDIV, FPLLMUL and FPLLODIV settings.

#pragma config   JTAGEN    = OFF    // JTAG Enable OFF (only use for '250)
#pragma config   FNOSC     = FRCPLL // Fast RC w PLL 8mHz internal rc Osc
#pragma config   FPLLIDIV  = DIV_10  // PLL in 8mHz/10 = 800 kHz
#pragma config   FPLLMUL   = MUL_15 // PLL mul 800 khz * 15 = 12 Mhz
#pragma config   FPLLODIV  = DIV_64  // PLL Out: 12MHz / 64 187.5 kHz
#pragma config   FPBDIV    = DIV_1  // Peripheral Bus Divisor
#pragma config   FCKSM     = CSECME // Clock Switch Enable, FSCM Enabled
#pragma config   POSCMOD   = OFF    // Primary osc disabled
#pragma config   IESO      = OFF    // Internal/external switch over
#pragma config   OSCIOFNC  = OFF    // CLKO Output Signal Active on the OSCO Pin
#pragma config   FWDTEN    = OFF    // Watchdog Timer Enable:

// ------------------------  Configuration (end) ----------------------------

int global_ctr = 0;                 // a global variable counter.
int global_delay_val = 1000;        // vary this to change the pulse's delay.


// Function prototypes
void delay(int d); // This is the prototype declaration for the Delay function


// Main function
int main(int argc, char** argv) {

    
  // Set Port A to be output, in two steps.
  LATA = 0;       // Set value of PORT A output to 0. 
  TRISA = 0;        // Set all pins on PORT A to output
  
  // Infinite Loop.  Keeps repeating.
    while(1) 
    {
        
        // Turn LED on  (takes roughly 1 sec)
        delay(global_delay_val);         // 1000: roughly Delay for roughly 1 second with 187.5 kHz system clock
      LATA = 0x0001;    // Set Pin 0 on PORT A to logic level "high" (3v).    

        // Turn LED off (takes roughly 1 sec)
        delay(global_delay_val);         // 1000: roughly Delay for roughly 1 second with 187.5 kHz system clock
    LATA = 0x0000;    // Set Pin 0 on PORT A to logic level "low" (0v).

        global_ctr++;
    }

  return (EXIT_SUCCESS);
}

// Delay routine
// With an 8MHz internal RC clock and settings to give a system clock
// of 187.5 kHz, the delay() function must be given about 1190 to get 1 sec
// delay:
// stopwatch: 100 complete ON/OFF pulses in 119 seconds.
// 500/((100/119)/2) = 1190
void delay(int d)
{
    int i;  // Declare variable to be used in the loop

    while(d)    // While d > 0
    {
        i = 100;    // set i to 100 for inner loop
        while(i)    // while i > 0
        {
            i--;    // decrement i (e.g. i will equal 99, 98, 97,...)
        }

        d--;    // decrement d
    }
}