#include "ThermostatDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"

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

void ThermostatDevice::turnOn()
{
    cout << "This device has been turned on" << endl << endl;
    this->power = true;
}

void ThermostatDevice::turnOff()
{
    cout << "This device has been turned off" << endl << endl;
    this->power = false;
}

bool ThermostatDevice::getPower() const
{
    return this->power;
}

void ThermostatDevice::setMaxTemp(int maxTemp)
{
    if (getPower() == false)
    {
        throw DeviceException("This thermostat is off. Cannot set max temperature.");
    }

    if (maxTemp <= minTemp)
    {
        throw DeviceException("Max temperature must be greater than min temperature.");
    }

    decrementBattery();
    this -> maxTemp = maxTemp;
    cout << "The max temp of this thermostat has been altered" << endl;

}

int ThermostatDevice::getMaxTemp()
{
    return this -> maxTemp;
}

void ThermostatDevice::setMinTemp(int minTemp)
{
    if (getPower() == false)
    {
        throw DeviceException("This thermostat is off. Cannot set min temperature.");
    }

    if (minTemp >= maxTemp)
    {
        throw DeviceException("Min temperature must be less than max temperature.");
    }

    decrementBattery();
    this -> minTemp = minTemp;
    cout << "The min temp of this thermostat has been altered" << endl;

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
        throw DeviceException("This thermostat is off. Cannot set current temperature.");
    }
    decrementBattery();

    if (isValidTemp(currentTemp) == 0)
    {
        this -> currentTemp = currentTemp;
    }
    else if (isValidTemp(currentTemp) == -1)
    {
        throw DeviceException("Temperature below minimum. Switching to heating.");
        setTempMode("Heating", this -> minTemp);
    }
    else if (isValidTemp(currentTemp) == 1)
    {
        throw DeviceException("Temperature above maximum. Switching to cooling.");
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
        throw DeviceException("This thermostat is off. Cannot set target temperature.");
    }
    decrementBattery();
    this -> targetTemp = targetTemp;

    if (isValidTemp(targetTemp) == 0)
    {
        setTempMode("Idle", targetTemp);
    }
    else if (isValidTemp(targetTemp) == -1)
    {
        throw DeviceException("Target temperature is below minimum.");
        setTempMode("Heating", this -> minTemp);
    }
    else if (isValidTemp(targetTemp) == 1)
    {
        throw DeviceException("Target temperature is above maximum.");
        setTempMode("Cooling", this -> maxTemp);
    }
    cout << "The target temp of this thermostat has been altered" << endl;

}
int ThermostatDevice::getTargetTemp()
{
    return this -> targetTemp;
}

void ThermostatDevice::setTempMode(string tempMode, int target)
{
    if (getPower() == false)
    {
        throw DeviceException("This thermostat is off. Cannot change temperature mode.");
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
    cout << "The mode of the thermostat has been altered" << endl;
}

void ThermostatDevice::setTempMode(string tempMode)
{
    if (getPower() == false)
    {
        throw DeviceException("This thermostat is off. Cannot change temperature mode.");
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
    cout << "The mode of the thermostat has been altered" << endl;
}

string ThermostatDevice::getTempMode()
{
    return this -> tempMode;
}

void ThermostatDevice::setBattery(int battery)
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

void ThermostatDevice::decrementBattery()
{
    this -> battery -= 5;
}

int ThermostatDevice::getBattery() const
{
    if (battery <= 0)
    {
        throw DeviceException("Your battery for this device has been depleted. Please charge this device to continue its use.");
    }
    return this->battery;
}

void ThermostatDevice::displayDeviceInfo()
{
    cout << "~~~Thermostat Device Information~~~" << endl;
    cout << "The name of the thermostat is " << this->getName() << endl;
    cout << "The thermostat is " << (this->getPower() ? "on" : "off") << endl;
    cout << "The max temp of the thermostat is set to " << this->getMaxTemp() << endl;
    cout << "The min temp of the thermostat is set to " << this->getMinTemp() << endl;
    cout << "The current temp of the thermostat is " << this->getCurrentTemp() << endl;
    cout << "The mode of the thermostat is " << this->getTempMode() << endl;
    cout << "The battery percentage is " << this->getBattery() << "%" << endl;
    cout << endl;
}
