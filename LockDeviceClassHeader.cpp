#include "LockDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"


// Default constructor
LockDevice::LockDevice()
{
    setName("UNNAMED LOCK"); // assigns default name
}

// Overloaded constructor
LockDevice::LockDevice(string name, string pin)
{
    setName(name); // sets device name

    // Ensures pin is exactly 4 characters
    if (pin.length() != 4)
    {
        throw InvalidInputException("PIN must be exactly 4 characters.");
    }

    this->pin = pin;     // stores the pin
    this->locked = true; // lock starts locked
}

// Destructor
LockDevice::~LockDevice()
{
}

// Turns device on
void LockDevice::turnOn()
{
    cout << "This device has been turned on" << endl << endl;
    this->power = true;
}

// Turns device off
void LockDevice::turnOff()
{
    cout << "This device has been turned off" << endl << endl;
    this->power = false;
}

// Returns power state
bool LockDevice::getPower() const
{
    return this->power;
}

// Sets battery value
void LockDevice::setBattery(int battery)
{
    // Validates battery range
    if (battery < 0 || battery > 100)
    {
        throw InvalidInputException("Battery must be between 0 and 100.");
    }

    this->battery = battery;
}

// Decreases battery by 5
void LockDevice::decrementBattery()
{
    this->battery -= 5;
}

// Returns battery level
int LockDevice::getBattery() const
{
    // Throws if battery is dead
    if (battery <= 0)
    {
        throw DeviceException("Battery depleted.");
    }

    return this->battery;
}

// Locks the device
void LockDevice::lock()
{
    // Cannot lock if power is off
    if (!getPower())
    {
        throw PowerException(getName());
    }

    decrementBattery();   // reduce battery
    this->locked = true;  // set locked
    cout << "The lock has been engaged" << endl;
}

// Unlocks device with pin
void LockDevice::unlock(string enteredPin)
{
    if (!getPower())
    {
        throw PowerException(getName());
    }

    // If alarm is active, block unlocking
    if (alarmTriggered)
    {
        throw DeviceException("Alarm triggered. Reset required.");
    }

    decrementBattery();

    // If correct pin
    if (enteredPin == this->pin)
    {
        this->locked = false;     // unlock
        this->failedAttempts = 0; // reset attempts
        cout << "The lock has been disengaged" << endl;
    }
    else
    {
        this->failedAttempts++; // increase failed attempts

        // If too many failures
        if (failedAttempts >= 3)
        {
            this->alarmTriggered = true;
            throw DeviceException("Too many failed attempts. Alarm triggered.");
        }

        throw InvalidInputException("Incorrect PIN.");
    }
}

// Returns lock state
bool LockDevice::isLocked() const
{
    return this->locked;
}

// Changes the pin
void LockDevice::setPin(string oldPin, string newPin)
{
    if (!getPower())
    {
        throw PowerException(getName());
    }

    // Check old pin
    if (oldPin != this->pin)
    {
        throw InvalidInputException("Old PIN incorrect.");
    }

    // Validate new pin length
    if (newPin.length() != 4)
    {
        throw InvalidInputException("New PIN must be 4 digits.");
    }

    decrementBattery();
    this->pin = newPin;
    cout << "The PIN has been updated" << endl;
}

// Returns alarm state
bool LockDevice::isAlarmTriggered() const
{
    return this->alarmTriggered;
}

// Resets alarm system
void LockDevice::resetAlarm()
{
    if (!getPower())
    {
        throw PowerException(getName());
    }

    decrementBattery();
    this->alarmTriggered = false;
    this->failedAttempts = 0;
    cout << "Alarm reset" << endl;
}

// Displays device info
void LockDevice::displayDeviceInfo()
{
    cout << "~~~Lock Device Information~~~" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Power: " << (getPower() ? "On" : "Off") << endl;
    cout << "Status: " << (isLocked() ? "Locked" : "Unlocked") << endl;
    cout << "Alarm: " << (isAlarmTriggered() ? "Triggered" : "Normal") << endl;
    cout << "Battery: " << getBattery() << "%" << endl;
    cout << endl;
}
