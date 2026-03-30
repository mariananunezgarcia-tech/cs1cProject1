#ifndef DEVICEINTENSITYINTERFACE_H_
#define DEVICEINTENSITYINTERFACE_H_

/***************************************************************************
 * DeviceIntensityInterface
 * -------------------------------------------------------------------------
 *		This is an abstract class used to define virtual functions to
 *		control the intensity level of different devices. It contains
 *		methods for getting and setting the device intensity, as well as
 *		increasing or decreasing the intensity
 **************************************************************************/


class DeviceIntensityInterface
{
	public:
		DeviceIntensityInterface() {};
		virtual ~DeviceIntensityInterface() {};

		virtual int  getIntensity() = 0;
		virtual void setIntensity(int level) = 0;
		virtual void increaseIntensity() = 0;
		virtual void decreaseIntensity() = 0;


	private:
		int level = 0;
};

#endif /* DEVICEINTENSITYINTERFACE_H_ */
