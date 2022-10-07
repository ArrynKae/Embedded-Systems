#include "uop_msb.h"
using namespace uop_msb;

// Hardware Definitions
#define TRAF_RED1_PIN PC_2

// Inputs
DigitalIn SW_BLUE(USER_BUTTON);

// Outputs
DigitalOut ledRed(TRAF_RED1_PIN);

// Timer(modified version from Timer)
TimerCompat tmr1;

int main()
{
    //Time how long it takes to perform a printf
    tmr1.start();
    printf("Hello World How Are You\n");
    tmr1.stop();

    //Print out how long it took
    unsigned long long dur = tmr1.read_ms();
    printf("The time taken was %llu milliseconds\n", dur);    

/*
    //Now to use a timer to implement a delay
    tmr1.start();
    while (true) {
        //Wait for switch press
        while (SW_BLUE == 0);

        //Turn on LED
        ledRed = 1;

        //Wait for 500ms
        tmr1.reset();
        while (tmr1.elapsed_time() < 500ms); //How about this for C++ magic :)

        wait_us(500000);

        //Turn off LED
        ledRed = 0;
    }

*/

    // Busy wait blocking (no <3)

    while (true)
    {
        // wait for switch press
        while (SW_BLUE == 0)
        {
            // is the LED on?
            // LED ON
            if (ledRed == 1)
            {
                //stop the timer and print the elapsed time on the screen
                tmr1.stop();
                printf("The timer has stopped. Red LED is on. \n");
                //Wait for 10s
                //while (tmr1.elapsed_time() < 10000ms); //How about this for C++ magic :)
               // wait_us(10000000);
                //reset the timer and for elapsed ON time
                tmr1.reset();
            }
            // LED OFF
            else
            {
                tmr1.stop();
                printf("The timer has stopped. Red LED is off. \n");
                // should I print the elapsed timer? maybe? idk
                tmr1.reset();
            }
            // switch is currently not pressed - let's start the timer
            tmr1.reset();
            
        }

        // the switch has been pressed, turn the LED on :)
        while (SW_BLUE == 1)
        {
            // is the led off?
            if (ledRed == 0)
            {
                // stop the timer and turn the LED on!
                tmr1.stop();
                ledRed = 1;
                printf("The switch has been pressed and the LED has been turned on! \n");
                tmr1.reset();
            }

            // led is on
            else {
                // stop the timer and turn the led off
                tmr1.stop();
                ledRed = 0;
                printf("The switch has been pressed and the LED has been turned off! \n");
            }
        }
    }
}



