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
- Created two abstract interface classes
- One for the power state of the device which includes virtual functions for
	- Turning the device on
	- Turning the device off
	- Checking the current power state of the device
- Another for the battery percentage of the device which includes virtual functions for
	- Setting the battery percentage
	- Decrementing the battery percentage
	- And getting the current battery percentage
- All devices utilize the Device Power Interface, and only the camera, thermostat, roomba, and lock
	utilize the Battery Percentage Interface.
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

Michelle
- I created a manager class that stores all the devices in a vector of BaseDevice pointers. So far it handles things like adding devices, turning them on/off, and calling their functions using polymorphism. I also connected the manager class to main by adding the light, camera, and thermostat objects to the manager. 
Implemented functions to add devices, search for a device by name, turn devices on and off, display all devices, and return the total number of devices being managed. 




