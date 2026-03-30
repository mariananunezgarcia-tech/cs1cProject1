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

void CameraDevice::turnOn()
{
    cout << "This device has been turned on" << endl << endl;
    this->power = true;
}

void CameraDevice::turnOff()
{
    cout << "This device has been turned off" << endl << endl;
    this->power = false;
}

bool CameraDevice::getPower() const
{
    return this->power;
}

int CameraDevice::getNumOfMotion()
{
    if (getPower() == false)
    {
        throw PowerException(getName());
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
        throw PowerException(getName());        
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
        throw PowerException(getName());
    }
    decrementBattery();
    this -> recording = true;
    cout << "This device has begun recording" << endl;
}

void CameraDevice::stopRecording()
{
    if (getPower() == false)
    {
        throw PowerException(getName());
    }
    decrementBattery();
    this -> recording = false;
    cout << "This device has stopped recording" << endl;
}

bool CameraDevice::isRecording() const
{
    if (getPower() == false)
    {
        throw PowerException(getName());
    }
    return this -> recording;
}

void CameraDevice::setBattery(int battery)
{
    if (battery < 0 || battery > 100)
    {
        throw InvalidInputException("Battery must be between 0 and 100.");
    }
    else
    {
        this->battery = battery;
    }
}

void CameraDevice::decrementBattery()
{
    this -> battery -= 5;
}

int CameraDevice::getBattery() const
{
    if (battery <= 0)
    {
        throw DeviceException("Your battery for this device has been depleted. Please charge this device to continue its use.");
    }
    return this->battery;
}

void CameraDevice::displayDeviceInfo()
{
    cout << "~~~Camera Device Information~~~" << endl;
    cout << "The name of the camera is " << this->getName() << endl;
    cout << "The camera is " << (this->getPower() ? "on" : "off") << endl;
    cout << "There has been " << this->getNumOfMotion() << " times where motion has been detected since you last checked" << endl;
    cout << "There is " << (this->isMotionDetected() ? "" : "no ") << "motion detected right now" << endl;
    cout << "The camera is " << (this->isRecording() ? "" : "not ") << "recording right now" << endl;
    cout << "The battery percentage is " << this->getBattery() << "%" << endl;
    cout << endl;
}