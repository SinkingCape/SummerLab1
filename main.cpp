#include "mbed.h"
#include <cstdio>
/*
An interrupt service procedure is configured by this programme to start when a button attached to pin PC_13 falls or is pressed.
Pressing the button causes flag int_trig to be set to 1.
If this flag is set, the main loop checks it, writes "bttnFall" to the serial monitor and then resets it. 
*/

InterruptIn bluebtn(PC_13);
volatile int int_trig = 0;


void bttnFall(){
    int_trig = 1;

}


// main() runs in its own thread in the OS
int main()
{
    bluebtn.fall(&bttnFall);


    while (true) {
        if(int_trig == 1){
            int_trig = 0;
            printf("bttnFall \r\n");

        }
    }
}

