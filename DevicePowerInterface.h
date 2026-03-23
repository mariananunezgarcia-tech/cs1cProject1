/***************************************************************************
* AUTHOR     : Gabriel Shepardson
* STUDENT ID : A00220907
* ASSIGN 1   : Smart Home System
* CLASS      : CS 1C
* SECTION    : MW: 5:00pm
* DUE DATE   : 03/23/2026
****************************************************************************/

#ifndef DEVICEPOWERINTERFACE_H_
#define DEVICEPOWERINTERFACE_H_
#include <iostream>
using namespace std;

/***************************************************************************
 * DevicePowerInterface
 * -------------------------------------------------------------------------
 *		This is an abstract class used to define virtual functions to
 *		control the power state of a device, including turning it on,
 *		turning it off, and returning the current power state.
 **************************************************************************/

class DevicePowerInterface
{
	public:
		DevicePowerInterface() {};			//Default Constructor
		virtual ~DevicePowerInterface() {}; //Virtual Destructor

		virtual void turnOn() = 0;		   //Turns the device on
		virtual void turnOff() = 0;		   //Turns the device off
		virtual bool getPower() const = 0; //Returns the current power state

};

#endif /* DEVICEPOWERINTERFACE_H_ */
