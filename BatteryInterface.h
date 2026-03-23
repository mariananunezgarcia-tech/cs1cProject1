/***************************************************************************
* AUTHOR     : Gabriel Shepardson
* STUDENT ID : A00220907
* ASSIGN 1   : Smart Home System
* CLASS      : CS 1C
* SECTION    : MW: 5:00pm
* DUE DATE   : 03/23/2026
****************************************************************************/

#ifndef BATTERYINTERFACE_H_
#define BATTERYINTERFACE_H_
#include <iostream>
using namespace std;

/***************************************************************************
 * BatteryInterface
 * -------------------------------------------------------------------------
 *		This is an abstract class used to define virtual functions to
 *		control the battery percentage of a device. It includes functions
 *		to set the battery percentage, decrement the battery, and return
 *		the current battery percentage.
 **************************************************************************/

class BatteryInterface
{
	public:
		BatteryInterface() {};			//Default Constructor
		virtual ~BatteryInterface() {}; //Virtual Destructor

	    virtual void setBattery(int battery) = 0; //Sets battery percentage
	    virtual void decrementBattery() = 0;	  //Decreases battery
	    virtual int  getBattery() const = 0;	  //Returns the current
	    										  //battery percentage
};



#endif /* BATTERYINTERFACE_H_ */
