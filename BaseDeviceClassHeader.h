#ifndef BASEDEVICECLASSHEADER_H
#define BASEDEVICECLASSHEADER_H

#include <string>
#include <iostream>
using namespace std;

/***************************************************************************
 * BaseDevice
 * -------------------------------------------------------------------------
 *		BaseDevice is a parent class for various smart home devices. All
 *		Devices derived from this class include a name, a function to set
 *		the name and a function to retrieve the name of the device.
 **************************************************************************/

class BaseDevice
{
    protected:
    BaseDevice();			 //Default Constructor
    BaseDevice(string name); //Overloaded Constructor
    ~BaseDevice();			 //Destructor

    public:
    string getName() const;     //Returns the name of the device
    void setName(string name);  //Sets a new name for the device

    virtual void displayDeviceInfo() = 0;

    /* moved to interfaces
    void turnOn();
    void turnOff();
    bool getPower() const;
    void setBattery(int battery);
    void decrementBattery();
    int getBattery() const;
    */
private:
    string name = "";   //Holds the name of the device
    /* moved to interfaces
    int battery = 100;
    bool power = false;
    */
};
#endif