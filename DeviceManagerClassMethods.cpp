#include "DeviceManagerClassHeader.h"
#include "ExceptionsClassHeader.h"

// Constructor
DeviceManager::DeviceManager()
{

}

// Destructor
DeviceManager::~DeviceManager()
{

}

// Adds a new device to the manager
void DeviceManager::addDevice(BaseDevice* device)
{
	devices.push_back(device); // adds the new device pointer to the vector
}

// Searches for a device by name and returns it or nullptr if not found
BaseDevice* DeviceManager::findDevice(const string& name)
{
    for (int i = 0; i < devices.size(); i++)
    {
		// Compares the name of each device in the vector with the provided name
        if (devices[i]->getName() == name)
        {
			// If a match is found, the pointer to that device is returned
            return devices[i];
        }
     
    }

    // If no device with the given name is found, a message is printed and nullptr is returned
    throw DeviceException("Device not found.");
	return nullptr;
}

// Turns on a device by name
void DeviceManager::turnDeviceOn(const string& name)
{
	// Calls findDevice to get the pointer to the device with the specified name
    BaseDevice* device = findDevice(name);

	// If the device is found the turnOn method of that device is called
    if (device != nullptr)
    {	
        //Dynamically casts the found index to type DevicePowerInterface, which
    	//has access to the turn on/off functions for the derived classes
    	DevicePowerInterface* i = dynamic_cast<DevicePowerInterface*>(device);
        i->turnOn();
    }
}

// Turns off a device by name
void DeviceManager::turnDeviceOff(const string& name)
{
	// Calls findDevice to get the pointer to the device with the specified name
    BaseDevice* device = findDevice(name);

	// If the device is found the turnOff method of that device is called
    if (device != nullptr)
    {
    	//Dynamically casts the found index to type DevicePowerInterface, which
    	//has access to the turn on/off functions for the derived classes
    	DevicePowerInterface* i = dynamic_cast<DevicePowerInterface*>(device);
        i->turnOff();
    }
}

// Displays all devices and their status
void DeviceManager::showAllDevices() const
{
    cout << "****** Smart Home Devices  ******" << endl;
    cout << "~~~Showing information for all devices~~~" << endl;

    for (int i = 0; i < devices.size(); i++)
    {
        devices[i]->displayDeviceInfo();
    }
}

// Returns the current number of devices in the manager
int DeviceManager::getDeviceCount() const
{
    return static_cast<int>(devices.size());
}
