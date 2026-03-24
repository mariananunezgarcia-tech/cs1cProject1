#include "BaseDeviceClassHeader.h"
BaseDevice::BaseDevice()
{
	this -> name = "UNNAMED DEVICE";
}

BaseDevice::BaseDevice(string name)
{
    this->name = name;
}

BaseDevice::~BaseDevice() {}
