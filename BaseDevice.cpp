#include "BaseDevice.h"

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

// Slight Changed from Lila's code
// (added an if statement in case battery < 5)
void BaseDevice::decrementBattery()
{
    if (battery >= 5)
        this->battery -= 5;
    else
        this->battery = 0;
}


int BaseDevice::getBattery() const
{
    if (battery == 0)
    {
        cout << "Your battery for this device has been depleted. Please charge this device to continue its use." << endl;
    }
    return this->battery;
}
