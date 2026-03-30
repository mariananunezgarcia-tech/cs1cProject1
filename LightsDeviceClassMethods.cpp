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

void LightsDevice::setBrightness(int brightness)
{
    if (getPower() == false)
    {
        throw PowerException(getName());
    }

    if (brightness > 10 || brightness < 0)
    {
        throw InvalidInputException("Brightness must be between 0 and 10.");
    }
    else
    {
        this -> brightness = brightness;
        cout << "The brightness of this device has been altered" << endl;
    }
}

int LightsDevice::getBrightness() const
{
    return this -> brightness;
}


void LightsDevice::displayDeviceInfo()
{
    cout << "~~~Lights Device Information~~~" << endl;
    cout << "The name of the lights is " << this->getName() << endl;
    cout << "The lights are " << (this->getPower() ? "on" : "off") << endl;
    cout << "The color of the lights is " << this->getColor() << endl;
    cout << "The brightness of the light is " << this->getBrightness() << endl;

}
