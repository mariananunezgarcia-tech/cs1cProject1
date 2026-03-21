
#ifndef CS1CPROJECT1_LIGHTSDEVICECLASS_H
#define CS1CPROJECT1_LIGHTSDEVICECLASS_H



#include "BaseDevice.h"

class LightsDevice: public BaseDevice
{
public:
    LightsDevice();
    LightsDevice(string name, string color, int brightness);
    ~LightsDevice();

    void setColor(string color);
    string getColor() const;

    void setBrightness(int brightness);
    int getBrightness() const;

    // Added function to print device info. without needing to
    // know which device we are accessing
    // override - tells compiler that this function is intended
    // to override the virtual function in base class
    void displayStatus() const override;

private:
    string color;
    int brightness;
};

#endif //CS1CPROJECT1_LIGHTSDEVICECLASS_H
