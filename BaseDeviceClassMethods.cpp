#include "BaseDeviceClassHeader.h"
BaseDevice::BaseDevice()
{

}

BaseDevice::BaseDevice(string name)
{
    this->name = name;
}

BaseDevice::~BaseDevice()
{

}

string BaseDevice::getName() const
{
    return this->name;
}

void BaseDevice::setName(string name)
{
    this->name = name;
}

void BaseDevice::turnOn()
{
    this->power = true;
}

void BaseDevice::turnOff()
{
    this->power = false;
}

bool BaseDevice::getPower() const
{
    return this->power;
}

void BaseDevice::setBattery(int battery)
{
    if (battery < 0 || battery > 100)
    {
        cout << "Not a valid battery percentage" << endl;
    }
    else
    {
        this->battery = battery;
    }
}

int BaseDevice::getBattery() const
{
    return this->battery;
}
