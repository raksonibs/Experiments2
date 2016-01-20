/* 
 * File:   newmain.c
 * Author: oskarniburski
 *
 * Created on January 19, 2016, 5:25 PM
 */

#include <stdio.h>
#include <stdlib.h>
//  main  include file  - this  contains  all the "friendly names"
//  for the pins  and peripherals
#include  <xc.h>
#include <proc/p32mx695f512l.h>
//  ------------------------    Configuration (begin) ----------------------------
//    There are Four  configuration words that  need  to  be  dealt with:
//  Config. Word  3,  Config. Word  2,    Config. Word  1 and Config. Word  0,
//  in  that  order.
//  Configuration Word  3 (User ID  info)
//  ...nothing  here...
//#pragma config   JTAGEN    = OFF    // JTAG Enable OFF (only use for '250)
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

int global_ctr = 7; 
/*
 * 
 */
int main(int argc, char** argv) {
    int local_counter = 0;
    LATG = 1; 
    TRISGbits.TRISG6 = 1;
    while (local_counter < 7) {
        global_ctr = global_ctr + 1;
        if (global_ctr > 9) {
            LATG = 0;
            TRISGbits.TRISG6 = 0;
        }
       local_counter = local_counter + 2;
    }
    
//    int ix;
//    int local_ctr = 0;
//    for (ix = 1; ix <= 4; ix++) {
//        local_ctr = local_ctr + 1;
//    }
    
    
    return (EXIT_SUCCESS);
}

