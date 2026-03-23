#ifndef LIGHTSDEVICE_H_
#define LIGHTSDEVICE_H_

#include "BaseDevice.h"
#include "DevicePowerInterface.h"

class LightsDevice: public BaseDevice,
					public DevicePowerInterface
{
    public:
		LightsDevice();
		LightsDevice(string name, string color, int brightness);
		~LightsDevice();

		//Accessors
		virtual bool getPower()   const;
		string  getColor()        const;
		int     getBrightness()   const;

		//mutators
		virtual void turnOn();
		virtual void turnOff();
		void setColor(string color);
		void setBrightness(int brightness);


    private:
		string color;
		int    brightness;
		bool   power;
};

#endif /* LIGHTSDEVICE_H_ */
