#ifndef CAMERADEVICECLASSHEADER_H
#define CAMERADEVICECLASSHEADER_H
#include "BaseDeviceClassHeader.h"
#include <stdlib.h>
#include <time.h>

class CameraDevice: public BaseDevice
{
    public:
    CameraDevice();
    CameraDevice(string name);
    ~CameraDevice();

    int getNumOfMotion();
    bool isMotionDetected();

    void startRecording();
    void stopRecording();
    bool isRecording() const;

    private:
    int numOfMotion = 0;
    bool motionDetected = false;
    bool recording = false;
};
#endif