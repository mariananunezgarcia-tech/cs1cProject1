#include <iostream>
#include "BaseDeviceClassHeader.h"
#include "LightsDeviceClassHeader.h"
using namespace std;
int main() {

    LightsDevice kitchenLights("Kitchen Lights", "White", 7);
    cout << "The name of the lights is " << kitchenLights.getName() << endl;
    cout << "The lights are " << (kitchenLights.getPower() ? "on" : "off") << endl;
    cout << "The color of the lights is " << kitchenLights.getColor() << endl;
    cout << "The brightness of the light is " << kitchenLights.getBrightness() << endl;
    cout << "The battery percentage is " << kitchenLights.getBattery() << "%" << endl;

    cout << endl;

    kitchenLights.turnOn();
    kitchenLights.setBrightness(10);
    kitchenLights.setColor("Green");
    kitchenLights.setBattery(90);

    cout << "The name of the lights is " << kitchenLights.getName() << endl;
    cout << "The lights are " << (kitchenLights.getPower() ? "on" : "off") << endl;
    cout << "The color of the lights is " << kitchenLights.getColor() << endl;
    cout << "The brightness of the light is " << kitchenLights.getBrightness() << endl;
    cout << "The battery percentage is " << kitchenLights.getBattery() << "%" << endl;

    return 0;
}
