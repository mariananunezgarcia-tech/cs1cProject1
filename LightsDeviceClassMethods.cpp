#include "LightsDeviceClassHeader.h"

LightsDevice::LightsDevice()
{
	setName("UNNAMED DEVICE");
    this -> color = "White";
    this -> brightness = 10;
    this -> power = 0;
}

LightsDevice::LightsDevice(string name, string color, int brightness)
{
    this -> name  = name;
    this -> color = color;
    this -> brightness = brightness;
    this -> power = 0;
}

LightsDevice::~LightsDevice() {}

void LightsDevice::turnOn()
{
	this -> power = 1;
}

void LightsDevice::turnOff()
{
	this -> power = 0;
}

bool LightsDevice::getPower() const
{
	return this -> power;
}

void LightsDevice::setColor(string color)
{
    if (this -> power == false)
    {
        cout << "This device is off" << endl;
        return;
    }
    this -> color = color;
}

string LightsDevice::getColor() const
{
    return this -> color;
}

void LightsDevice::setBrightness(int brightness)
{
    if (this -> power == false)
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
        this -> brightness = brightness;
    }
}

int LightsDevice::getBrightness() const
{
    return this -> brightness;
}

void LightsDevice::setName(string name)
{
    this->name = name;
}

string LightsDevice::getName()
{
    return this->name;
}
