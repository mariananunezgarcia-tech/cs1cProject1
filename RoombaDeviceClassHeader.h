#ifndef ROOMBADEVICECLASSHEADER_H
#define ROOMBADEVICECLASSHEADER_H

#include "BaseDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"
#include "DevicePowerInterface.h"
#include "BatteryInterface.h"
#include "DeviceIntensityInterface.h"

class RoombaDevice : public BaseDevice,
                     public DevicePowerInterface,
                     public BatteryInterface,
					           public DeviceIntensityInterface
{
public:
    RoombaDevice();
    RoombaDevice(string name, int suctionLevel);
    ~RoombaDevice();

    // virtual interface methods
    virtual bool getPower() const;
    virtual int getBattery() const;

    virtual void turnOn();
    virtual void turnOff();
    virtual void setBattery(int battery);
    virtual void decrementBattery();

    virtual void displayDeviceInfo();

    // roomba specific methods
    void startCleaning();
    void stopCleaning();
    bool isCleaning() const;

    void returnToDock();
    bool isDocked() const;

	  virtual void setIntensity(int suctionLevel);
	  virtual void increaseIntensity();
  	virtual void increaseIntensity(int amount);
	  virtual void decreaseIntensity();
	  virtual void decreaseIntensity(int amount);
	  virtual int  getIntensity();

    void setDustBinLevel(int dustBinLevel);
    int getDustBinLevel() const;
    void emptyDustBin();

private:
    string name = "";
    bool cleaning = false;
    bool docked = true;
    int suctionLevel = 1;
    int dustBinLevel = 0;

    bool power = false;
    int battery = 100;
};

#endif //ROOMBADEVICECLASSHEADER_H
