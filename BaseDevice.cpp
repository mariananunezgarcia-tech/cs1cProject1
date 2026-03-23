#include "BaseDevice.h"
BaseDevice::BaseDevice()
{
	this -> name = "UNNAMED DEVICE";
}

BaseDevice::BaseDevice(string name)
{
    this->name = name;
}

BaseDevice::~BaseDevice() {}

string BaseDevice::getName() const
{
    return this->name;
}

void BaseDevice::setName(string name)
{
    this->name = name;
}
