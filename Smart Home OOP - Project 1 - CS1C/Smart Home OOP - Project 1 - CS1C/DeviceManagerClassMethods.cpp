#include "DeviceManagerClassHeader.h"

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
	cout << "Device not found." << endl;
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
        device->turnOn();
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
        device->turnOff();
    }
}

// Displays all devices and their status
void DeviceManager::showAllDevices() const
{
    cout << "****** Smart Home Devices  ******" << endl;

    for (int i = 0; i < devices.size(); i++)
    {
        cout << "Device Name: " << devices[i]->getName() << endl;
        cout << "Power Status: " << (devices[i]->getPower() ? "On" : "Off") << endl;
        cout << "Battery: " << devices[i]->getBattery() << "%" << endl;
        cout << endl;
    }
}

// Returns the current number of devices in the manager
int DeviceManager::getDeviceCount() const
{
    return static_cast<int>(devices.size());
}