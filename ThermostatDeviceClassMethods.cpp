#include "ThermostatDeviceClassHeader.h"

ThermostatDevice::ThermostatDevice()
{

}
ThermostatDevice::ThermostatDevice(string name, int maxTemp, int minTemp)
{
    setName(name);
    this -> maxTemp = maxTemp;
    this -> minTemp = minTemp;
    int difference = (this-> maxTemp - this -> minTemp) / 3;
    this -> currentTemp = this -> maxTemp - difference;
}
ThermostatDevice::~ThermostatDevice()
{

}

void ThermostatDevice::setMaxTemp(int maxTemp)
{
    if (getPower() == false)
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
    if (getPower() == false)
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
    if (getPower() == false)
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
    if (getPower() == false)
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
    if (getPower() == false)
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
    if (getPower() == false)
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
