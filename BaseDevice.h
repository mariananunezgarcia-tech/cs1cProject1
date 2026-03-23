#ifndef BASEDEVICE_H_
#define BASEDEVICE_H_

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
		~BaseDevice();			 //Destructor

    public:
		string getName() const;	   //Returns the name of the device
		void setName(string name); //Sets a new name for the device

	private:
		string name; //Holds the name of the device

};


#endif /* BASEDEVICE_H_ */
