#ifndef DEVICEMANAGERCLASSHEADER_H
#define DEVICEMANAGERCLASSHEADER_H

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include "BaseDeviceClassHeader.h"
#include "DevicePowerInterface.h"
#include "BatteryInterface.h"

using namespace std;

/***************************************************************************
* DeviceManager Class
*   This class allows the user to manage multiple devices 
*   in their smart home. It can add devices, find devices by name, 
*   turn devices on and off, and display all devices with their status. 
*   The class uses a vector to store pointers to BaseDevice objects, 
*   allowing for dynamic management of various types of devices that
*   inherit from BaseDevice.
****************************************************************************/

class DeviceManager
{
public:
	DeviceManager();   
	~DeviceManager(); 

	void addDevice(BaseDevice* device);   // adds a new device to the manager
    BaseDevice* findDevice(const string& name); // searches for a device by name

	void turnDeviceOn(const string& name);  // turns on a device by name
	void turnDeviceOff(const string& name); // turns off a device by name

	void showAllDevices() const;  // displays all devices and their status
	int getDeviceCount() const;   // returns the current number of devices in the manager

private:
	vector<BaseDevice*> devices; // stores all device pointers
};

#endif /*DEVICEMANAGERCLASSHEADER_H*/
