/************************************************************************
 *              Name : Mariana Nunez Garcia
 *         Professor :  Homi
 *        Assignment : Project 1 - CS1C
 *          Due Date : Unknown
 *  *********************************************************************/



#ifndef CS1CPROJECT1_SMARTHOMEMANAGER_H
#define CS1CPROJECT1_SMARTHOMEMANAGER_H

#include <vector>
#include <string>
#include <stdexcept>
#include "BaseDevice.h"

using namespace std;

/*************************************************************
 * Class Name: DeviceNotFoundException
 *
 * Description:
 *  This exception is thrown when a device with a specified
 *  name cannot be found in the SmartHomeManager.
 *
 * Parameters:
 *  None
 *
 * Returns:
 *  Error message string through what()
*************************************************************/
class DeviceNotFoundException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Device not found.";
    }
};



/*************************************************************
 * Class Name: DuplicateDeviceException
 *
 * Description:
 *  This exception is thrown when attempting to add a device
 *  that already exists in the SmartHomeManager.
 *
 * Parameters:
 *  None
 *
 * Returns:
 *  Error message string through what()
 **************************************************************/
class DuplicateDeviceException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "A device with that name already exists.";
    }
};




class SmartHomeManager
{
public:

    /***************************************************************************
    *  Function Name: ~SmartHomeManager
    * -------------------------------------------------------------------------
    *  Description:
    *  Destructor that cleans up all dynamically allocated
    *  device objects stored in the manager to prevent memory leaks..
    **************************************************************************/
    ~SmartHomeManager();

    /************************************************************************
     * Function Name: addDevice
     * Description:
     *  Adds a new device to the smart home system. Checks for
     *  duplicate device names before adding.
     * ----------------------------------------------------------------------
     * Parameters:
     *  device - pointer to a BaseDevice object to be added
     *
     *  Throws:
     *      DuplicateDeviceException if a device with the same name exists
     * *********************************************************************/
    void addDevice(BaseDevice* device);



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
    BaseDevice* findDeviceByName(const string& name) const;

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
     *      DeviceNotFoundException if the device is not found
     * *********************************************************************/
    void turnOnDevice(const string& name);

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
    void turnOffDevice(const string& name);


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
    void showAllDevices() const;

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
    void removeDevice(const string& name);

private:
    vector<BaseDevice*> devices;
};

#endif //CS1CPROJECT1_SMARTHOMEMANAGER_H
