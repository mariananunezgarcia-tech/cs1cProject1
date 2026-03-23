#include "BaseDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"

BaseDevice::BaseDevice()
{
    this -> name = "UNNAMED DEVICE";
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

/* moved to interfaces
void BaseDevice::turnOn()
{
    cout << "This device has been turned on" << endl << endl;
    this->power = true;
}

void BaseDevice::turnOff()
{
    cout << "This device has been turned off" << endl << endl;
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
    if (battery <= 0)
    {
        throw DeviceException("Your battery for this device has been depleted. Please charge this device to continue its use.");
    }
    return this->battery;
}
*/
