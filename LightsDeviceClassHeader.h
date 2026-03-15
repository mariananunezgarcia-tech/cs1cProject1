#ifndef LIGHTSDEVICECLASSHEADER_H
#define LIGHTSDEVICECLASSHEADER_H
#include "BaseDeviceClassHeader.h"

class LightsDevice: public BaseDevice
{
    public:
    LightsDevice();
    LightsDevice(string name, string color, int brightness);
    ~LightsDevice();

    void setColor(string color);
    string getColor() const;

    void setBrightness(int brightness);
    string getBrightness() const;

    private:
    string color;
    string brightness;
};
#endif
