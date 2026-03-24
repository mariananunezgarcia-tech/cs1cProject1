#include "CameraDeviceClassHeader.h"

CameraDevice::CameraDevice()
{
	setName("UNNAMED DEVICE");
	this -> numOfMotion = 0;
	this -> motionDetected = false;
	this -> recording = false;
	this -> power = 0;
	this -> battery = 100;
}

CameraDevice::CameraDevice(string name)
{
    this -> name  = name;
	this -> numOfMotion = 0;
	this -> motionDetected = false;
	this -> recording = false;
	this -> power = 0;
	this -> battery = 100;
}

CameraDevice::~CameraDevice() {}

void CameraDevice::turnOn()
{
	this -> power = 1;
}

void CameraDevice::turnOff()
{
	this -> power = 0;
}

bool CameraDevice::getPower() const
{
	return this -> power;
}

int CameraDevice::getNumOfMotion()
{
    if (this -> power == false)
    {
        cout << "This device is off" << endl;
        return 0;
    }
    srand(time(NULL));
    this -> numOfMotion = rand() % 11;

    decrementBattery();
    return this -> numOfMotion;
}

bool CameraDevice::isMotionDetected()
{
    if (this -> power == false)
    {
        cout << "This device is off" << endl;
        return false;
    }
    //srand(time(NULL));
    decrementBattery();
    bool temp = rand() % 2;
    this -> motionDetected = temp;
    return this -> motionDetected;
}

void CameraDevice::startRecording()
{
    if (this -> power == false)
    {
        cout << "This device is off" << endl;
        return;
    }
    decrementBattery();
    this -> recording = true;
}

void CameraDevice::stopRecording()
{
    if (this -> power == false)
    {
        cout << "This device is off" << endl;
        return;
    }
    decrementBattery();
    this -> recording = false;
}

bool CameraDevice::isRecording() const
{
    if (this -> power == false)
    {
        cout << "This device is off" << endl;
        return 0;
    }
    return this -> recording;
}

void CameraDevice::setBattery(int battery)
{
    if (battery < 0 || battery > 100)
    {
        cout << "Not a valid battery percentage" << endl;
    }
    else
    {
        this -> battery = battery;
    }
}

void CameraDevice::decrementBattery()
{
    this -> battery -= 5;
}

int CameraDevice::getBattery() const
{
    if (battery == 0)
    {
        cout << "Your battery for this device has been depleted. Please charge this device to continue its use." << endl;
    }
    return this -> battery;
}

void CameraDevice::setName(string name)
{
    this->name = name;
}

string CameraDevice::getName()
{
    return this->name;
}
