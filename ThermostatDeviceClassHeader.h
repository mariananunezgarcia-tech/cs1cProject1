#ifndef THERMOSTATDEVICECLASSHEADER_H
#define THERMOSTATDEVICECLASSHEADER_H
#include "BaseDeviceClassHeader.h"

class ThermostatDevice: public BaseDevice
{
    public:
    ThermostatDevice();
    ThermostatDevice(string name, int maxTemp, int minTemp);
    ~ThermostatDevice();

    void setMaxTemp(int maxTemp);
    int getMaxTemp();

    void setMinTemp(int minTemp);
    int getMinTemp();

    int isValidTemp(int validTemp);

    void setCurrentTemp(int currentTemp);
    int getCurrentTemp();

    void setTargetTemp(int targetTemp);
    int getTargetTemp();

    void setTempMode(string tempMode, int target);
    void setTempMode(string tempMode);
    string getTempMode();

    private:
    int maxTemp = 100;
    int minTemp = 0;
    int currentTemp;
    int targetTemp;
    int validTemp;
    string tempMode = "Idle";
};
#endif