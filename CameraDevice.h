#ifndef CAMERADEVICE_H_
#define CAMERADEVICE_H_

#include "BaseDevice.h"
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
		virtual bool getPower()   const;
	    virtual int  getBattery() const;
		int  getNumOfMotion();
		bool isMotionDetected();
		bool isRecording() const;

		//Mutators
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
};

#endif /* CAMERADEVICE_H_ */
