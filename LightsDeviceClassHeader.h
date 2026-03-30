#ifndef LIGHTSDEVICECLASSHEADER_H_
#define LIGHTSDEVICECLASSHEADER_H_

#include "BaseDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"
#include "DevicePowerInterface.h"
#include "DeviceIntensityInterface.h"

class LightsDevice: public BaseDevice,
					public DevicePowerInterface,
					public DeviceIntensityInterface
{
    public:
		LightsDevice();
		LightsDevice(string name, string color, int brightness);
		~LightsDevice();

		//Accessors
		virtual string getName();
		virtual bool getPower()    const;
		virtual void displayDeviceInfo();
		virtual int getIntensity();
		string  getColor()         const;

		//mutators
		virtual void setName(string name);
		virtual void turnOn();
		virtual void turnOff();
		virtual void setIntensity(int brightness);
		virtual void increaseIntensity();
		virtual void increaseIntensity(int amount);
		virtual void decreaseIntensity();
		virtual void decreaseIntensity(int amount);
		void setColor(string color);


    private:
		string color;
		int    brightness;
		bool   power;
		string name;
};

#endif /* LIGHTSDEVICECLASSHEADER_H_ */
