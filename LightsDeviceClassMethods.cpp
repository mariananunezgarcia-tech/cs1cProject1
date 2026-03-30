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

void LightsDevice::setIntensity(int brightness)
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

int LightsDevice::getIntensity()
{
    return this -> brightness;
}

void LightsDevice::increaseIntensity()
{
    if (getPower() == false)
    {
        throw DeviceException("These Lights is off. Cannot change brightness.");
    }
    if (this->brightness == 10)
    {
        throw DeviceException("Lights are already at maximum brightness.");
    }

    this -> brightness = this->brightness + 1;
    cout << "The brightness of the lights has been altered" << endl;
}

void LightsDevice::increaseIntensity(int amount)
{
    if (getPower() == false)
    {
        throw DeviceException("These Lights is off. Cannot change brightness.");
    }
    if (this->brightness == 10)
    {
        throw DeviceException("Lights are already at maximum brightness.");
    }
    else if ((this -> brightness + amount) > 10)
    {
    	this -> brightness = 10;
    }
    else
    {
        this -> brightness = this->brightness + amount;
    }

    cout << "The brightness of the lights has been altered" << endl;
}

void LightsDevice::decreaseIntensity()
{
    if (getPower() == false)
    {
        throw DeviceException("These Lights are off. Cannot change brightness.");
    }
    if (this->brightness == 0)
    {
        throw DeviceException("Lights are already at minimum brightness.");
    }
    this -> brightness = this -> brightness - 1;
    cout << "The brightness of the lights has been altered" << endl;
}

void LightsDevice::decreaseIntensity(int amount)
{
    if (getPower() == false)
    {
        throw DeviceException("These Lights is off. Cannot change brightness.");
    }
    if (this->brightness == 0)
    {
        throw DeviceException("Lights are already at minimum brightness.");
    }
    else if ((this -> brightness - amount) < 0)
    {
    	this -> brightness = 0;
    }
    else
    {
        this -> brightness = this->brightness - amount;
    }

    cout << "The brightness of the lights has been altered" << endl;
}

void LightsDevice::setName(string name)
{
    this->name = name;
}

string LightsDevice::getName()
{
    return this->name;
}

void LightsDevice::displayDeviceInfo()
{
    cout << "~~~Lights Device Information~~~" << endl;
    cout << "The name of the lights is " << this->getName() << endl;
    cout << "The lights are " << (this->getPower() ? "on" : "off") << endl;
    cout << "The color of the lights is " << this->getColor() << endl;
    cout << "The brightness of the light is " << this->getIntensity() << endl;
    cout << endl;
}
