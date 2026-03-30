#ifndef CAMERADEVICECLASSHEADER_H
#define CAMERADEVICECLASSHEADER_H
#include "BaseDeviceClassHeader.h"
#include "DevicePowerInterface.h"
#include "BatteryInterface.h"
#include <stdlib.h>
#include <time.h>

/***************************************************************************
 * CameraDevice
 * -------------------------------------------------------------------------
 * Inherited Classes:
 *   BaseDevice           - The parent for every smart device
 *   DevicePowerInterface - Controls the power state of the device
 *   BatteryInterface     - Control the battery percentage of the device
 **************************************************************************/

class CameraDevice: public BaseDevice,
                    public DevicePowerInterface,
                    public BatteryInterface
{
    public:
    CameraDevice();            //Default Contructor
    CameraDevice(string name); //Overloaded Constructor
    ~CameraDevice();           //Default Destructor

    //virtual interface methods
    virtual bool getPower()   const;
    virtual int  getBattery() const;

    virtual void turnOn();
    virtual void turnOff();
    virtual void setBattery(int battery);
    virtual void decrementBattery();

    virtual void displayDeviceInfo();

    //device specific methods
    int getNumOfMotion();
    bool isMotionDetected();

    void startRecording();
    void stopRecording();
    bool isRecording() const;

    private:
    int numOfMotion = 0;
    bool motionDetected = false;
    bool recording = false;

    bool power = false;
    int  battery = 100;
};
#endif
