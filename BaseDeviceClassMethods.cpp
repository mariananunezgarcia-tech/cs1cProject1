#include "BaseDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"

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
        throw DeviceException("Battery must be between 0 and 100.");
    }
    else
    {
        this->battery = battery;
    }
}

void BaseDevice::decrementBattery()
{
    this -> battery -= 5;
}

int BaseDevice::getBattery() const
{
    if (battery == 0)
    {
        throw DeviceException("Your battery for this device has been depleted. Please charge this device to continue its use.");
    }
    return this->battery;
}
