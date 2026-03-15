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
    this -> color = color;
}

string LightsDevice::getColor() const
{
    return this -> color;
}

void LightsDevice::setBrightness(int brightness)
{
    if (brightness > 10 || brightness < 0)
    {
        cout << "Not a valid brightness level" << endl;
    }
    else
    {
        this -> brightness = brightness;
    }
}

string LightsDevice::getBrightness() const
{
    return this -> brightness;
}
