#ifndef BASEDEVICECLASSHEADER_H_
#define BASEDEVICECLASSHEADER_H_

#include <string>
#include <iostream>
using namespace std;

/***************************************************************************
 * BaseDevice
 * -------------------------------------------------------------------------
 *		BaseDevice is a parent class for various smart home devices. All
 *		Devices derived from this class include a name, a function to set
 *		the name and a function to retrieve the name of the device.
 **************************************************************************/

class BaseDevice
{
    protected:
		BaseDevice();			 //Default Constructor
		BaseDevice(string name); //Overloaded Constructor
		virtual ~BaseDevice();	 //Destructor

    public:
	/***************************************************************************
	 * Changed to pure virtual functions so that each device could implement
	 *	its own version of the function. The manager class will polymorphically
	 *	call these functions in order to access the names of each device
	 * -------------------------------------------------------------------------
	 * SEE ALSO:
	 * 		Each derived class now has a version of get/set name
	 **************************************************************************/
		virtual string getName() = 0;
		virtual void setName(string name) = 0;

	private:
		string name; //Holds the name of the device

};


#endif /* BASEDEVICECLASSHEADER_H_ */
