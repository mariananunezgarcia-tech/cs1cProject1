#ifndef LIGHTSDEVICECLASSHEADER_H
#define LIGHTSDEVICECLASSHEADER_H
#include "BaseDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"
#include "DevicePowerInterface.h"

class LightsDevice: public BaseDevice,
                    public DevicePowerInterface
{
    public:
    LightsDevice();
    LightsDevice(string name, string color, int brightness);
    ~LightsDevice();

    //virtual interface methods
    virtual bool getPower()   const;

    virtual void turnOn();
    virtual void turnOff();

    virtual void displayDeviceInfo();

    //device specific methods
    void setColor(string color);
    string getColor() const;

    void setBrightness(int brightness);
    int getBrightness() const;

    private:
    string color = "no color set";
    int brightness = 0;
    bool power = false;
};
#endif
