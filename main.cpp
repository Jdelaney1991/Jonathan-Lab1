//Error message : Mutex: 0x20000160, Not allowed in ISR context SRAM1
// the issue was directly using printf in an ISR is relatively slow and resource-intensive function. ISR are suppose to be short and fast to handle interrupts without affecting the timing. Using printf in and ISR can lead to unexpected behavior
//to get a decent output avoid using printf directly . Instead set a flag in the ISR to indicate the button has been pressed and then handle the printing outside the ISR main loop 

#include "mbed.h"

// main() runs in its own thread in the OS

InterruptIn bttn(PC_13);
volatile bool buttonPressed = false;

void buttn_interupt(){
    buttonPressed = true;
}

int main ()
{
    bttn.fall(&buttn_interupt);
    
    while (true) {
        if (buttonPressed) {
            printf("Button pressed\r\n");
            buttonPressed = false; // Reset the flag
        }
        
    }
}

  



