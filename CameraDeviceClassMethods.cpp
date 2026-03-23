#include "CameraDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"

CameraDevice::CameraDevice()
{

}

CameraDevice::CameraDevice(string name)
{
    setName(name);
}

CameraDevice::~CameraDevice()
{

}

int CameraDevice::getNumOfMotion()
{
    if (getPower() == false)
    {
        throw DeviceException("This camera is off.");
    }
    srand(time(NULL));
    this -> numOfMotion = rand() % 11;

    decrementBattery();
    return this -> numOfMotion;
}

bool CameraDevice::isMotionDetected()
{
    if (getPower() == false)
    {
        throw DeviceException("This camera is off.");
        /*cout << "This device is off" << endl;
        return false;*/
    }
    //srand(time(NULL));
    decrementBattery();
    bool temp = rand() % 2;
    this -> motionDetected = temp;
    return this -> motionDetected;
}

void CameraDevice::startRecording()
{
    if (getPower() == false)
    {
        throw DeviceException("This camera is off.");
    }
    decrementBattery();
    this -> recording = true;
    cout << "This device has begun recording" << endl;
}

void CameraDevice::stopRecording()
{
    if (getPower() == false)
    {
        throw DeviceException("This camera is off.");
    }
    decrementBattery();
    this -> recording = false;
    cout << "This device has stopped recording" << endl;
}

bool CameraDevice::isRecording() const
{
    if (getPower() == false)
    {
        throw DeviceException("This camera is off.");
    }
    return this -> recording;
}