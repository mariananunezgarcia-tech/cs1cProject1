#ifndef THERMOSTATDEVICECLASSHEADER_H_
#define THERMOSTATDEVICECLASSHEADER_H_

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
    ThermostatDevice();			   //Default Constructor
    ThermostatDevice(string name,
    				 int maxTemp,
					 int minTemp); //Overloaded Constructor
    ~ThermostatDevice();		   //Default Destructor


    //Accessors
	virtual string getName();
    virtual bool getPower() const;	 //Returns the current power state
    virtual int  getBattery() const; //Returns the current battery percentage
    int getMaxTemp();			     //Returns the max temperature
    int getMinTemp();				 //Returns the min temperature
    int isValidTemp(int validTemp);  //Checks if inputed temperature is valid
    int getCurrentTemp();			 //Returns the current temperature
    int getTargetTemp();			 //Returns the target temperature
    string getTempMode();			 //Returns the current temperature mode

    //Mutators
    virtual void setName(string name);
    virtual void turnOn();				  //Turns the device on
    virtual void turnOff();			      //Turns the device off
    virtual void setBattery(int battery); //Sets the battery's percentage
    virtual void decrementBattery();	  //Decreases the battery's percentage
    void setMaxTemp(int maxTemp);		  //Sets a new max temperature
    void setMinTemp(int minTemp);		  //Sets a new min temperature
    void setCurrentTemp(int currentTemp); //Sets a new current temperature
    void setTargetTemp(int targetTemp);	  //Sets a new target temperature
    void setTempMode(string tempMode,	  //Overloaded, sets a new temperature
    				 int target); 		  //	mode and target temperature
    void setTempMode(string tempMode);	  //Sets a new temperature mode


    private:
    bool power;
    int  battery;
    int  maxTemp;
    int  minTemp;
    int  currentTemp;
    int  targetTemp;
    string tempMode;
    string name;
};

#endif /* THERMOSTATDEVICECLASSHEADER_H_ */
