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

void LightsDevice::turnOn()
{
    cout << "This device has been turned on" << endl << endl;
    this->power = true;
}

void LightsDevice::turnOff()
{
    cout << "This device has been turned off" << endl << endl;
    this->power = false;
}

bool LightsDevice::getPower() const
{
    return this->power;
}

void LightsDevice::setColor(string color)
{

    if (getPower() == false)
    {
        throw PowerException(getName());
    }
    this -> color = color;
    cout << "The color of this device has been altered" << endl;
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


void LightsDevice::displayDeviceInfo()
{
    cout << "~~~Lights Device Information~~~" << endl;
    cout << "The name of the lights is " << this->getName() << endl;
    cout << "The lights are " << (this->getPower() ? "on" : "off") << endl;
    cout << "The color of the lights is " << this->getColor() << endl;
    cout << "The brightness of the light is " << this->getIntensity() << endl << endl;

}
