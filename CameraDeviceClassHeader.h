#ifndef CAMERADEVICECLASSHEADER_H_
#define CAMERADEVICECLASSHEADER_H_

#include "BaseDeviceClassHeader.h"
#include "DevicePowerInterface.h"
#include "BatteryInterface.h"
#include <stdlib.h>
#include <time.h>

class CameraDevice: public BaseDevice,
					public DevicePowerInterface,
					public BatteryInterface
{
    public:
		CameraDevice();
		CameraDevice(string name);
		~CameraDevice();

		//Accessors
		virtual string getName();
		virtual bool getPower()   const;
	    virtual int  getBattery() const;
		int  getNumOfMotion();
		bool isMotionDetected();
		bool isRecording() const;

		//Mutators
		virtual void setName(string name); //Sets a new name for the device
		virtual void turnOn();
		virtual void turnOff();
	    virtual void setBattery(int battery);
	    virtual void decrementBattery();
		void startRecording();
		void stopRecording();


    private:
		int  numOfMotion;
		bool motionDetected;
		bool recording;
		bool power;
		int  battery;
		string name;
};

#endif /* CAMERADEVICECLASSHEADER_H_ */
