#include "ThermostatDeviceClassHeader.h"

ThermostatDevice::ThermostatDevice()
{
    setName("UNNAMED DEVICE");
    this -> power = 0;
    this -> maxTemp = 100;
    this -> minTemp = 0;
    this -> battery = 100;

    int difference = (this-> maxTemp - this -> minTemp) / 3;
    this -> currentTemp = this -> maxTemp - difference;
    this -> targetTemp = this -> currentTemp;
    this -> tempMode = "Idle";
}

ThermostatDevice::ThermostatDevice(string name, int maxTemp, int minTemp)
{
    this -> name  = name;
    this -> power = 0;
    this -> maxTemp = maxTemp;
    this -> minTemp = minTemp;
    this -> battery = 100;

    int difference = (this-> maxTemp - this -> minTemp) / 3;
    this -> currentTemp = this -> maxTemp - difference;
    this -> targetTemp = this -> currentTemp;
    this -> tempMode = "Idle";
}
ThermostatDevice::~ThermostatDevice() {}

void ThermostatDevice::turnOn()
{
	this -> power = 1;
}

void ThermostatDevice::turnOff()
{
	this -> power = 0;
}

bool ThermostatDevice::getPower() const
{
	return this -> power;
}


void ThermostatDevice::setMaxTemp(int maxTemp)
{
    if (this -> power == false)
    {
        cout << "This device is off" << endl;
        return;
    }
    decrementBattery();
    this -> maxTemp = maxTemp;
}

int ThermostatDevice::getMaxTemp()
{
    return this -> maxTemp;
}

void ThermostatDevice::setMinTemp(int minTemp)
{
    if (this -> power == false)
    {
        cout << "This device is off" << endl;
        return;
    }
    decrementBattery();
    this -> minTemp = minTemp;
}

int ThermostatDevice::getMinTemp()
{
    return this -> minTemp;
}

int ThermostatDevice::isValidTemp(int validTemp)
{
    if (validTemp > this -> maxTemp)
    {
        return 1;
    }
    if (validTemp < this -> minTemp)
    {
        return -1;
    }
    return 0;
}

void ThermostatDevice::setCurrentTemp(int currentTemp)
{
    if (this -> power == false)
    {
        cout << "This device is off" << endl;
        return;
    }
    decrementBattery();
    if (isValidTemp(currentTemp) == 0)
    {
        this -> currentTemp = currentTemp;
    }
    else if (isValidTemp(currentTemp) == -1)
    {
        setTempMode("Heating", this -> minTemp);
    }
    else if (isValidTemp(currentTemp) == 1)
    {
        setTempMode("Cooling", this -> maxTemp);
    }
}

int ThermostatDevice::getCurrentTemp()
{
    return this -> currentTemp;
}

void ThermostatDevice::setTargetTemp(int targetTemp)
{
    if (this -> power == false)
    {
        cout << "This device is off" << endl;
        return;
    }
    decrementBattery();
    this -> targetTemp = targetTemp;
    if (isValidTemp(targetTemp) == 0)
    {
        setTempMode("Idle", targetTemp);
    }
    else if (isValidTemp(targetTemp) == -1)
    {
        setTempMode("Heating", this -> minTemp);
    }
    else if (isValidTemp(targetTemp) == 1)
    {
        setTempMode("Cooling", this -> maxTemp);
    }
}
int ThermostatDevice::getTargetTemp()
{
    return this -> targetTemp;
}

void ThermostatDevice::setTempMode(string tempMode, int target)
{
    if (this -> power == false)
    {
        cout << "This device is off" << endl;
        return;
    }
    decrementBattery();
    if (tempMode == "Idle")
    {
        if (target < this -> currentTemp)
        {
            this -> tempMode = "Cooling";
        }
        else if (target > this -> currentTemp)
        {
            this -> tempMode = "Heating";
        }
    }
    else
    {
        this -> tempMode = tempMode;
    }
    this -> currentTemp = target;
}

void ThermostatDevice::setTempMode(string tempMode)
{
    if (this -> power == false)
    {
        cout << "This device is off" << endl;
        return;
    }
    decrementBattery();
    if (tempMode == "Heating")
    {
        this -> tempMode = tempMode;
        this -> currentTemp += 5;
    }
    else if (tempMode == "Cooling")
    {
        this -> tempMode = tempMode;
        this -> currentTemp -= 5;
    }
    else
    {
        this -> tempMode = tempMode;
    }
    if (isValidTemp(this -> currentTemp) == -1)
    {
        this -> currentTemp = this -> minTemp;
    }
    else if (isValidTemp(this -> currentTemp) == 1)
    {
        this -> currentTemp = this -> maxTemp;
    }
}

string ThermostatDevice::getTempMode()
{
    return this -> tempMode;
}

void ThermostatDevice::setBattery(int battery)
{
    if (battery < 0 || battery > 100)
    {
        cout << "Not a valid battery percentage" << endl;
    }
    else
    {
        this -> battery = battery;
    }
}

void ThermostatDevice::decrementBattery()
{
    this -> battery -= 5;
}

int ThermostatDevice::getBattery() const
{
    if (battery == 0)
    {
        cout << "Your battery for this device has been depleted. Please charge this device to continue its use." << endl;
    }
    return this -> battery;
}

void ThermostatDevice::setName(string name)
{
    this->name = name;
}

string ThermostatDevice::getName()
{
    return this->name;
}
