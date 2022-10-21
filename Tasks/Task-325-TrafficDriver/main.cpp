#include "mbed.h"
#include "TrafficLight.h"

#define BTN1_PIN PG_0 


TrafficLight lights;
DigitalIn sw(USER_BUTTON);
DigitalIn button(BTN1_PIN);

TrafficLight::LIGHT_STATE s;

int main()
{
    while (true) {

        //Wait for switch press
        while (sw==0);
        //while (button == 0);

        //Update lights
        s = lights.nextState();
        //Debounce switch
        wait_us(300000);

        //Wait for switch release
        while (sw==1);
        //while (button == 1);

        //Switch debounce
        wait_us(300000);



    // try to get the stop function working later :)

    }
}

