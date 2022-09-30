#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

#define TRAF_GRN2_PIN PC_9
#define TRAF_YEL2_PIN PC_8
#define TRAF_RED2_PIN PC_7

#define TRAF_WHITE_PIN PF_10

//BusInOut Traffic_Lights_2(PC_7,PC_8,PC_9);
DigitalInOut grnLED(TRAF_GRN2_PIN, PinDirection::PIN_OUTPUT, PinMode::OpenDrainNoPull, 0);
// Add another LED which flashes in the state opposite to the green led.
// Create a DigitalInOut object with the red led pin label, in output mode, and the configuration is open-drain with no internal pull-up or pull-down resistor
DigitalInOut redLED(TRAF_RED2_PIN, PinDirection::PIN_OUTPUT, PinMode::OpenDrainNoPull, 0);

int main()
{
    //Note the logic
    while (true) {
        grnLED = 1;
        redLED = 0;     // opposite state to green led
        wait_us(1000000);
        grnLED = 0;
        redLED = 1;     // opposite state to green led
        wait_us(1000000);
    }
}

