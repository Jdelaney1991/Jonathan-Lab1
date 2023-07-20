#include "mbed.h"

// main() runs in its own thread in the OS
InterruptIn bttn(PC_13);

void buttn_interupt(){
    printf("buttn pressed\r\n");
}

int main ()
{
    bttn.fall(&buttn_interupt);
    while (true){}
}
  



