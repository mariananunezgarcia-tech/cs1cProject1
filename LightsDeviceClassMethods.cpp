#include "LightsDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"

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
        throw DeviceException("This light is off. Cannot change color.");
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
        throw DeviceException("This light is off. Cannot change brightness.");
    }

    if (brightness > 10 || brightness < 0)
    {
        throw DeviceException("Brightness must be between 0 and 10.");
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
