#include "BaseDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"

//Default Constructor 
BaseDevice::BaseDevice()
{
    this -> name = "UNNAMED DEVICE";
}

//Overloaded constructor - initializes the name of the device
BaseDevice::BaseDevice(string name)
{
    this->name = name;
}

//Default destructor
BaseDevice::~BaseDevice()
{

}

//Method to return the name of the device
string BaseDevice::getName() const
{
    return this->name;
}

//Method to set the name of the device
void BaseDevice::setName(string name)
{
    this->name = name;
}
