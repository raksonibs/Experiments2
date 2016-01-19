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
//  ------------------------    Configuration (begin) ----------------------------
//    There are Four  configuration words that  need  to  be  dealt with:
//  Config. Word  3,  Config. Word  2,    Config. Word  1 and Config. Word  0,
//  in  that  order.
//  Configuration Word  3 (User ID  info)
//  ...nothing  here...
#pragma config      JTAGEN        = OFF       //  JTAG  Enable  OFF (only use for '250)
#pragma config      FNOSC         = FRCPLL  //  Fast  RC  w PLL 8mHz  internal  rc  Osc
#pragma config      FPLLIDIV    = DIV_2   //  PLL in  8mHz/2  = 4mHz
#pragma config      FPLLMUL     = MUL_16  //  PLL mul 4mHz  * 20  = 80mHz 24??
#pragma config      FPLLODIV    = DIV_4   //  PLL Out 8mHz/2= 40  mHz system  frequency osc
#pragma config      FPBDIV        = DIV_1   //  Peripheral  Bus Divisor
#pragma config      FCKSM         = CSECME  //  Clock Switch  Enable, FSCM  Enabled
#pragma config      POSCMOD     = OFF       //  Primary osc disabled
#pragma config      IESO            = OFF       //  Internal/external switch  over
#pragma config      OSCIOFNC    = OFF       //  CLKO  Output  Signal  Active  on  the OSCO  Pin
#pragma config      FWDTEN        = OFF       //  Watchdog  Timer Enable:

int global_ctr = 7; 
/*
 * 
 */
int main(int argc, char** argv) {
//    int local_counter = 0;
//    LATG = 1; port G
//    TRISG6 = 1 pin 6??
//    while (local_counter < 7) {
//    global_ctr = global_crt + 1;
//        if (global_crt > 9) {
//    LATG = 0; port G
//    TRISG6 = 0 pin 6??
    //}
//        local_ctr = local_ctr + 2;
    //    }
    int ix;
    for (ix = 1; ix <= 4; ix++) {
        printf("%d ", ix);
    }
    
    
    return (EXIT_SUCCESS);
}

