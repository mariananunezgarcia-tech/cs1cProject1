#ifndef LIGHTSDEVICECLASSHEADER_H
#define LIGHTSDEVICECLASSHEADER_H
#include "BaseDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"
#include "DevicePowerInterface.h"
#include "DeviceIntensityInterface.h"

class LightsDevice: public BaseDevice,
                    public DevicePowerInterface,
					          public DeviceIntensityInterface
{
    public:
    LightsDevice();
    LightsDevice(string name, string color, int brightness);
    ~LightsDevice();

    //virtual interface methods
    virtual bool getPower()   const;

    virtual void turnOn();
    virtual void turnOff();

		virtual int  getIntensity();
		virtual void setIntensity(int brightness);
		virtual void increaseIntensity();
		virtual void increaseIntensity(int amount);
		virtual void decreaseIntensity();
		virtual void decreaseIntensity(int amount);

    virtual void displayDeviceInfo();

    //device specific methods
    void setColor(string color);
    string getColor() const;

    private:
    string color = "no color set";
    int brightness = 0;
    bool power = false;
};
#endif
