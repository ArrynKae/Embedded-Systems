#include "mbed.h"
// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

#define TRAF_GRN2_PIN PC_9
#define TRAF_YEL2_PIN PC_8
#define TRAF_RED2_PIN PC_7

#define TRAF_WHITE_PIN PF_10

#define BTN1_PIN PG_0 
#define BTN2_PIN PG_1
#define BTN3_PIN PG_2 // No pull down -- this button will have to be handled differently
#define BTN4_PIN PG_3 // No pull down -- this button will have to be handled differently

// Inputs
// Modify the current solution to use BusInOut on the switches in place of DigitalInOut
DigitalIn SW2(BTN1_PIN);
DigitalIn SW3(BTN2_PIN);
BusInOut otherSwitches(BTN3_PIN, BTN4_PIN);
//DigitalInOut SW4(BTN3_PIN,PIN_INPUT,PullDown,0);        // use DigitalInOut to configure the switches to use the internal pull-down resistors and there are no physical resistors on the module support board
//DigitalInOut SW5(BTN4_PIN,PIN_INPUT,PullDown,0);        // use DigitalInOut to configure the switches to use the internal pull-down resistors and there are no physical resistors on the module support board

// Outputs
// Configure the push-pull LEDs as outputs.
// instead of using Digital Out like in Task 205, use BusOut
// Bus out will set these LEDs using the decimal value of the 8 bit equivalent (2^3 since we are using 3 leds)
BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);


int main()
{

        // initialise SW4 and SW5 to be inputs and set their modes to pull down as there are no physical pull down resistors
        otherSwitches.input();
        otherSwitches.mode(PullDown);

    while (true) {
        if (SW2 == 1) {
            leds.write(1);
        } else {
            leds.write(0);
        }

        if (SW3.read() == 1) {
            leds.write(2);
        } else {
            leds.write(0);
        }


        if (otherSwitches.read() == 3)
        {
            leds.write(7);
        }
        else {
        leds.write(0);
        }


// old switch code for DigitalInOut switches :)
/*
        if (SW4.read() == 1)
        {
            leds.write(3);
        }
        else {
        leds.write(0);
        }
        if (SW5.read() == 1)
        {
            leds.write(4);
        }
        else {
        leds.write(0);
        }


// Modify the code to use SW4 and SW5
// When SW4 and SW5 are pressed, light all LEDs
        if (SW4.read() == 1 && SW5.read() == 1) {
            leds.write(7);
        }
        else {
        leds.write(0);
        }
*/
    }
}

