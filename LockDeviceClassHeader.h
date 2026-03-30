#ifndef CS1CPROJECT1_LOCKDEVICECLASSHEADER_H
#define CS1CPROJECT1_LOCKDEVICECLASSHEADER_H


#include "BaseDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"
#include "DevicePowerInterface.h"
#include "BatteryInterface.h"

// LockDevice inherits from:
// - BaseDevice (name functionality)
// - DevicePowerInterface (on/off control)
// - BatteryInterface (battery control)
class LockDevice : public BaseDevice,
                   public DevicePowerInterface,
                   public BatteryInterface
{
public:
    // Default constructor
    LockDevice();

    // Overloaded constructor (sets name and pin)
    LockDevice(string name, string pin);

    // Destructor
    ~LockDevice();

    // ----------- Interface Methods ----------- :D

    // Returns whether device is on or off
    virtual bool getPower() const;

    // Returns battery level
    virtual int getBattery() const;

    // Turns device on
    virtual void turnOn();

    // Turns device off
    virtual void turnOff();

    // Sets battery level manually
    virtual void setBattery(int battery);

    // Decreases battery level
    virtual void decrementBattery();

    // Displays all device info
    virtual void displayDeviceInfo();

    // ----------- Lock Specific Methods ----------- :D

    // Locks the device
    void lock();

    // Unlocks using a pin
    void unlock(string enteredPin);

    // Returns whether lock is locked
    bool isLocked() const;

    // Changes the pin
    void setPin(string oldPin, string newPin);

    // Checks if alarm triggered
    bool isAlarmTriggered() const;

    // Resets alarm after failed attempts
    void resetAlarm();

private:
    bool locked = true;              // true = locked, false = unlocked
    bool alarmTriggered = false;     // tracks alarm state
    int failedAttempts = 0;          // counts wrong pin attempts
    string pin = "0000";             // default pin

    bool power = false;              // device power state
    int battery = 100;               // battery percentage
};

#endif //CS1CPROJECT1_LOCKDEVICECLASSHEADER_H
