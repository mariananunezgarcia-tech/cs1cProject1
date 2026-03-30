
#include "RoombaDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"

// Default constructor
RoombaDevice::RoombaDevice()
{
    // Assigns a default name if none is provided
    setName("UNNAMED ROOMBA");
}

// Overloaded constructor
RoombaDevice::RoombaDevice(string name, int suctionLevel)
{
    // Sets the name of the device
    setName(name);

    // Validates suction level range (1–3 allowed)
    if (suctionLevel < 1 || suctionLevel > 3)
    {
        throw InvalidInputException("Suction level must be between 1 and 3.");
    }

    // Assigns suction level
    this->suctionLevel = suctionLevel;
}

// Destructor
RoombaDevice::~RoombaDevice()
{

}

// ---------------- POWER METHODS ---------------- :)

// Turns the device on
void RoombaDevice::turnOn()
{
    cout << "This device has been turned on" << endl << endl;

    // Set power state to true
    this->power = true;
}

// Turns the device off
void RoombaDevice::turnOff()
{
    cout << "This device has been turned off" << endl << endl;

    // Turn off power
    this->power = false;

    // Ensure cleaning stops when power is off
    this->cleaning = false;
}

// Returns current power state
bool RoombaDevice::getPower() const
{
    return this->power;
}

// ---------------- BATTERY METHODS ---------------- //

// Sets battery percentage manually
void RoombaDevice::setBattery(int battery)
{
    // Validate range (0–100)
    if (battery < 0 || battery > 100)
    {
        throw InvalidInputException("Battery must be between 0 and 100.");
    }

    this->battery = battery;
}

// Decreases battery level by 5 units
void RoombaDevice::decrementBattery()
{
    this->battery -= 5;
}

// Returns battery percentage
int RoombaDevice::getBattery() const
{
    // If battery is empty, throw exception
    if (battery <= 0)
    {
        throw DeviceException("Your battery for this device has been depleted. Please charge this device to continue its use.");
    }

    return this->battery;
}

// ---------------- CLEANING METHODS ---------------- //

// Starts cleaning process
void RoombaDevice::startCleaning()
{
    // Cannot clean if device is off
    if (getPower() == false)
    {
        throw PowerException(getName());
    }

    // Prevent cleaning if battery is too low
    if (getBattery() < 10)
    {
        throw DeviceException("Battery is too low to start cleaning.");
    }

    // Prevent cleaning if dust bin is full
    if (dustBinLevel >= 100)
    {
        throw DeviceException("Dust bin is full. Please empty it before cleaning.");
    }

    // Reduce battery due to usage
    decrementBattery();

    // Set cleaning state to true
    this->cleaning = true;

    // Roomba leaves docking station when cleaning
    this->docked = false;

    // Increase dust bin level as it collects debris
    this->dustBinLevel += 20;

    // Ensure dust bin does not exceed 100%
    if (this->dustBinLevel > 100)
    {
        this->dustBinLevel = 100;
    }

    cout << "The Roomba has started cleaning" << endl;
}

// Stops cleaning
void RoombaDevice::stopCleaning()
{
    // Cannot stop if device is off
    if (getPower() == false)
    {
        throw PowerException(getName());
    }

    // Reduce battery
    decrementBattery();

    // Stop cleaning
    this->cleaning = false;

    cout << "The Roomba has stopped cleaning" << endl;
}

// Returns whether Roomba is cleaning
bool RoombaDevice::isCleaning() const
{
    return this->cleaning;
}

// ---------------- DOCKING METHODS ----------------

// Sends Roomba back to docking station
void RoombaDevice::returnToDock()
{
    // Cannot dock if device is off
    if (getPower() == false)
    {
        throw PowerException(getName());
    }

    // Reduce battery
    decrementBattery();

    // Stop cleaning when docking
    this->cleaning = false;

    // Set docked state to true
    this->docked = true;

    cout << "The Roomba has returned to its dock" << endl;
}

// Returns whether Roomba is docked
bool RoombaDevice::isDocked() const
{
    return this->docked;
}

// ---------------- SUCTION METHODS ---------------- :)

// Sets suction level
void RoombaDevice::setSuctionLevel(int suctionLevel)
{
    // Cannot change suction if device is off
    if (getPower() == false)
    {
        throw PowerException(getName());
    }

    // Validate suction level range
    if (suctionLevel < 1 || suctionLevel > 3)
    {
        throw InvalidInputException("Suction level must be between 1 and 3.");
    }

    // Reduce battery
    decrementBattery();

    // Assign new suction level
    this->suctionLevel = suctionLevel;

    cout << "The suction level has been altered" << endl;
}

// Returns suction level
int RoombaDevice::getSuctionLevel() const
{
    return this->suctionLevel;
}

// ---------------- DUST BIN METHODS ----------------

// Sets dust bin level manually
void RoombaDevice::setDustBinLevel(int dustBinLevel)
{
    // Cannot set if device is off
    if (getPower() == false)
    {
        throw PowerException(getName());
    }

    // Validate range
    if (dustBinLevel < 0 || dustBinLevel > 100)
    {
        throw InvalidInputException("Dust bin level must be between 0 and 100.");
    }

    // Reduce battery
    decrementBattery();

    this->dustBinLevel = dustBinLevel;

    cout << "The dust bin level has been altered" << endl;
}

// Returns dust bin level
int RoombaDevice::getDustBinLevel() const
{
    return this->dustBinLevel;
}

// Empties dust bin
void RoombaDevice::emptyDustBin()
{
    // Cannot empty if device is off
    if (getPower() == false)
    {
        throw PowerException(getName());
    }

    // Reduce battery
    decrementBattery();

    // Reset dust bin to empty
    this->dustBinLevel = 0;

    cout << "The dust bin has been emptied" << endl;
}

// ---------------- DISPLAY ---------------- :D

// Displays all device information
void RoombaDevice::displayDeviceInfo()
{
    cout << "~~~Roomba Device Information~~~" << endl;

    // Display device name
    cout << "The name of the Roomba is " << this->getName() << endl;
    // Display power state
    cout << "The Roomba is " << (this->getPower() ? "on" : "off") << endl;
    // Display cleaning status
    cout << "The Roomba is currently " << (this->isCleaning() ? "cleaning" : "not cleaning") << endl;
    // Display docking status
    cout << "The Roomba is currently " << (this->isDocked() ? "docked" : "not docked") << endl;
    // Display suction level
    cout << "The suction level is " << this->getSuctionLevel() << endl;
    // Display dust bin level
    cout << "The dust bin level is " << this->getDustBinLevel() << "%" << endl;
    // Display battery percentage
    cout << "The battery percentage is " << this->getBattery() << "%" << endl;

    cout << endl;
}
