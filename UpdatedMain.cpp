
#include <iostream>
#include "ThermostatDevice.h"
#include "LightsDeviceClass.h"
#include "CameraDevice.h"
#include "SmartHomeManager.h"

using namespace std;

int main()
{
    // Creates the boss/remote control/TV remote of the house
    SmartHomeManager manager;

    // cool function I just found --> GeeksforGeeks:D
    // basically says to the compiler: Try this code, if it fails don't crash.
    // Instead jump to the catch block:)
    try
    {
        // Adding devices to the smart home
        // New keyword cuz the manager stores pointers (BaseDevice*)
        manager.addDevice(new LightsDevice("Kitchen Lights", "White", 7));
        manager.addDevice(new CameraDevice("Backyard Camera"));
        manager.addDevice(new ThermostatDevice("Bedroom Thermostat", 80, 65));

        // Turning devices on
        // manager finds the device and turns it on!!!
        manager.turnOnDevice("Kitchen Lights");
        manager.turnOnDevice("Backyard Camera");
        manager.turnOnDevice("Bedroom Thermostat");

        // Display all devices to terminal
        // Uses polymorphism
        // Each device has its own version of the funtion displayStatus()
        manager.showAllDevices();
        cout << endl;

        // Turn off one specific device
        // It's like 3am lol I see colors lol
        cout << "Turning off Kitchen Lights..." << endl;
        manager.turnOffDevice("Kitchen Lights");

        //Show updated systems status
        manager.showAllDevices();
        cout << endl;

        // Erase when turning in - just to demonstrate the try function
        // making an error to test the try function
        cout << "Trying to find a device that does not exist..." << endl;
        manager.turnOnDevice("Garage Sensor");   // exception #1
    }
    catch (const DeviceNotFoundException& e)
    {
        // .what() is part of the try function
        // basically tells the programmer what is wrong with the try function
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}

