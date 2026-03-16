#include "LightsDeviceClassHeader.h"
LightsDevice::LightsDevice()
{

}

LightsDevice::LightsDevice(string name, string color, int brightness)
{
    setName(name);
    this -> color = color;
    this -> brightness = brightness;
}

LightsDevice::~LightsDevice()
{

}

void LightsDevice::setColor(string color)
{
    if (getPower() == false)
    {
        cout << "This device is off" << endl;
        return;
    }
    decrementBattery();
    this -> color = color;
}

string LightsDevice::getColor() const
{
    return this -> color;
}

void LightsDevice::setBrightness(int brightness)
{
    if (getPower() == false)
    {
        cout << "This device is off" << endl;
        return;
    }
    if (brightness > 10 || brightness < 0)
    {
        cout << "Not a valid brightness level" << endl;
    }
    else
    {
        decrementBattery();
        this -> brightness = brightness;
    }
}

int LightsDevice::getBrightness() const
{
    return this -> brightness;
}
