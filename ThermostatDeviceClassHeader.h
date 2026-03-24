#ifndef THERMOSTATDEVICECLASSHEADER_H
#define THERMOSTATDEVICECLASSHEADER_H
#include "BaseDeviceClassHeader.h"
#include "DevicePowerInterface.h"
#include "BatteryInterface.h"

/***************************************************************************
 * ThermostatDevice
 * -------------------------------------------------------------------------
 * Derived class of:
 *		BaseDevice : Parent class defining basic features of smart home
 *					 devices
 *
 * Utilizing the Interface(s):
 *  	DevicePowerInterface : Controls the power state of the device
 *  	BatteryInterface	 : Controls the battery percentage of the device
 * -------------------------------------------------------------------------
 * 		This class is a smart home device that is designed to control the
 * 		thermostat in a house. It uses virtual functions from the
 * 		interface(s) to control the power and battery percentage of the
 * 		device. It also has setters and getters for the min/max
 * 		temperatures, the target temperature, the current temperature, and
 * 		the current mode the device is in
 **************************************************************************/

class ThermostatDevice: public BaseDevice,
                        public DevicePowerInterface,
                        public BatteryInterface
{
    public:
    ThermostatDevice();
    ThermostatDevice(string name, int maxTemp, int minTemp);
    ~ThermostatDevice();

    //virtual interface methods
    virtual bool getPower() const;	 //Returns the current power state
    virtual int  getBattery() const; //Returns the current battery percentage

    virtual void turnOn();				  //Turns the device on
    virtual void turnOff();			      //Turns the device off
    virtual void setBattery(int battery); //Sets the battery's percentage
    virtual void decrementBattery();	  //Decreases the battery's percentage

    virtual void displayDeviceInfo();

    //device specific methods
    void setMaxTemp(int maxTemp);
    int getMaxTemp();

    void setMinTemp(int minTemp);
    int getMinTemp();

    int isValidTemp(int validTemp);

    void setCurrentTemp(int currentTemp);
    int getCurrentTemp();

    void setTargetTemp(int targetTemp);
    int getTargetTemp();

    void setTempMode(string tempMode, int target);
    void setTempMode(string tempMode);
    string getTempMode();

    private:
    int maxTemp = 100;
    int minTemp = 0;
    int currentTemp;
    int targetTemp;
    int validTemp;
    string tempMode = "Idle";

    bool power = false;
    int  battery = 100;
};
#endif