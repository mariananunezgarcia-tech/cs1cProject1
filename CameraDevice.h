
#ifndef CS1CPROJECT1_CAMERADEVICE_H
#define CS1CPROJECT1_CAMERADEVICE_H

#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "BaseDevice.h"

using namespace std;


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

    void displayStatus() const override;

private:
    int numOfMotion = 0;
    bool motionDetected = false;
    bool recording = false;
};

#endif //CS1CPROJECT1_CAMERADEVICE_H
