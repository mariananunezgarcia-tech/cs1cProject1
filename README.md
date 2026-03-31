# cs1cProject1
Design and implement a Smart Home Automation System in C++ using object-oriented programming principles. Your program should model a home containing different kinds of smart devices and allow the system to control and monitor them.


# Project's Requirements: 
- 

# Technologies Used
- C++ - Backend program logic

# Technical Work: 
Main Focus: 




# Team Member Contributions: 
Gabe
- Created three abstract interface classes
- One for the power state of the device which includes virtual functions for
	- Turning the device on
	- Turning the device off
	- Checking the current power state of the device
- Another for the battery percentage of the device which includes virtual functions for
	- Setting the battery percentage
	- Decrementing the battery percentage
	- And getting the current battery percentage
- A final interface for the intensity of devices which include virtual functions for
  	- Setting the intensity of brightness, volume, or suction
  	- Getting the current intensity
  	- Overloaded methods for increasing the intensity
  	- Overloaded methods for decreasing the intensity
- All devices utilize the Device Power Interface, only the camera, thermostat, roomba, and lock
	utilize the Battery Percentage Interface, and the lights, speaker, and roomba utilize the Device
	intensity interface
- Updated the manager class to dynamic cast to type devicePowerInterface in order to access methods for
  	turning devices on and off, as well as returning the current power state.

Hana
- Created three custom exception classes:
	- General case, power, and invalid input
- Added general exceptions within class implementation files
- Added cout statements to make it clear which device is turned on after an exception
- Replaced all if statement bodies with categorized exceptions
- added exception in thermostat class for if max temperature is less than min temperature and vice versa
- added three try-catch blocks in main to test exceptions with the thermostat, lights, and camera

Lila
- Created the base class structure
- Made the lights class
- Put together a test program for the devices
- Made the camera class
- Made the thermostat class
- Made the speaker class
- Move some of the console messages into the methods of the devices
- Combining the interface code with the rest of the code
- Display device info methods for each device
- Display device info is now an abstract virtual function in base class making it an abstract class
- fixed how the manager displays to console

Mariana
- Completed manager function based on Lila’s code; furthermore utilizing polymorphism to call functions from other related classes.
- Completed the Smart Lock Device class that utilized polymosphism and functions that allowed the lock to:
  		- turn on/off
		- getName()
  		- getPower()
  		- lock()/unlock()
  		- setPin()
- Completed the Roomba Device class that utilized polymosphism and functions that allowed the lock to:
  		- stopCleaning()
  		- returnToDock()
  		- emptyDustBinLevel()
- Slightly edited the main function to include testing of the Lock and Roomba class. 

Michelle
- Created the manager class (DeviceManager) that stores all the devices in a vector of BaseDevice pointers and acts as the central controller for all smart home devices
- Stores devices polymorphically using a vector to support multiple device types
- Implemented core functions including:
  - Adding devices to the system
  - Searching for devices by name
  - turning devices on and off
  - Displaying all device information
  - Returning the total number of managed devices
