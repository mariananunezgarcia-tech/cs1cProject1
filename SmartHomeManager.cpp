/************************************************************************
*              Name : Mariana Nunez Garcia
 *         Professor :  Homi
 *        Assignment : Project 1 - CS1C
 *          Due Date : Unknown
 *  *********************************************************************/


#include "SmartHomeManager.h"
#include <iostream>



/***************************************************************************
 *  Function Name: ~SmartHomeManager
 * -------------------------------------------------------------------------
 *  Description:
 *  Deletes all dynamically allocated devices to prevent memory leaks.
 **************************************************************************/
SmartHomeManager::~SmartHomeManager()
{
    for (BaseDevice* device : devices)
    {
        delete device;
    }
}



/************************************************************************
 * Function Name: addDevice
 * Description:
 *  Adds a new device to the smart home system. Checks for
 *  duplicate device names before adding.
 *  ----------------------------------------------------------------------
 *  Parameters:
 *      device - pointer to a BaseDevice object to be added
 *
 *  Throws:
 *      DuplicateDeviceException if a device with the same name exists
 *  *********************************************************************/
void SmartHomeManager::addDevice(BaseDevice* device)
{
    for (BaseDevice* existing : devices)
    {
        if (existing->getName() == device->getName())
        {
            throw DuplicateDeviceException(); // runs catch in try function - from main :)
        }
    }

    devices.push_back(device);
}


/************************************************************************
* Function Name: findDeviceByName
* Description:
*  Searches for a device in the system by its name.
* ----------------------------------------------------------------------
* Parameters:
*  name - string representing the device name to search for
*
*  Returns:
*      Pointer to the matching BaseDevice
*
*  Throws:
*      DeviceNotFoundException if no matching device is found
* *********************************************************************/
BaseDevice* SmartHomeManager::findDeviceByName(const string& name) const
{
    for (BaseDevice* device : devices)
    {
        if (device->getName() == name)
        {
            return device;
        }
    }

    throw DeviceNotFoundException();
}


/************************************************************************
* Function Name: turnOnDevice
* Description:
*  Turns on a specific device using its name.
* ----------------------------------------------------------------------
* Parameters:
*  name - string representing the device name
*
*  Returns:
*      None
*
*  Throws:
* DeviceNotFoundException if the device is not found
* *********************************************************************/
void SmartHomeManager::turnOnDevice(const string& name)
{
    BaseDevice* device = findDeviceByName(name);
    device->turnOn();
}



/************************************************************************
* Function Name: turnOffDevice
* Description:
*  Turns off a specific device using its name.
* ----------------------------------------------------------------------
* Parameters:
*  name - string representing the device name
*
*  Returns:
*      None
*
*  Throws:
*      DeviceNotFoundException if the device is not found
* *********************************************************************/
void SmartHomeManager::turnOffDevice(const string& name)
{
    BaseDevice* device = findDeviceByName(name);
    device->turnOff();
}



/************************************************************************
* Function Name: showAllDevices
* Description:
* Displays the status of all devices in the system by
* calling their displayStatus() function polymorphically.
* ----------------------------------------------------------------------
* Parameters:
*  name - string representing the device name
*
*  Returns:
*      None
* *********************************************************************/
void SmartHomeManager::showAllDevices() const
{
    cout << "----------------- Smart Home Devices ----------------- " << endl;
    for (BaseDevice* device : devices)
    {
        device->displayStatus();
        cout << "------------------------------------------- " << endl;
    }
}





/************************************************************************
* Function Name: removeDevice
* Description:
* Removes a device from the system by name and frees
* its allocated memory.
* ----------------------------------------------------------------------
* Parameters:
*  name - string representing the device name
*
*  Returns:
*      None
*
*  Throws:
*      DeviceNotFoundException if the device is not found
* *********************************************************************/
void SmartHomeManager::removeDevice(const string& name)
{
    for (int i = 0; i < devices.size(); i++)
    {
        if (devices[i]->getName() == name)
        {
            delete devices[i];
            devices.erase(devices.begin() + i);
            return;
        }
    }

    throw DeviceNotFoundException();
}
