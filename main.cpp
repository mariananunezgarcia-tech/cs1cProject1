#include <iostream>
#include "BaseDeviceClassHeader.h"
#include "LightsDeviceClassHeader.h"
#include "CameraDeviceClassHeader.h"
#include "ThermostatDeviceClassHeader.h"
#include "SpeakerDeviceClassHeader.h"
#include "DeviceManagerClassHeader.h"
#include "DevicePowerInterface.h"
#include "BatteryInterface.h"

using namespace std;
int main() {

    // manager section
    DeviceManager manager; // Create an instance of DeviceManager

    LightsDevice kitchenLights("Kitchen Lights", "White", 7);

    CameraDevice backyardCamera("Backyard Camera");

    ThermostatDevice bedroomThermostat("Bedroom Thermostat", 80, 65);

    SpeakerDevice livingRoomSpeaker("Living Room Speaker", 5);

    // Add devices to the manager using pointers to the existing device objects
    manager.addDevice(&kitchenLights);
    manager.addDevice(&backyardCamera);
    manager.addDevice(&bedroomThermostat);
    manager.addDevice(&livingRoomSpeaker);


    kitchenLights.turnOn();

    kitchenLights.displayDeviceInfo();

    cout << endl;

    kitchenLights.setBrightness(10);
    cout << endl;

    cout << "Setting color to Green..." << endl;
    kitchenLights.setColor("Green");
    cout << endl;

    kitchenLights.displayDeviceInfo();

    kitchenLights.turnOff();

    try 
    {
        cout << "Setting color to Blue..." << endl;
        kitchenLights.setColor("Blue");
    }
    catch (const DeviceException& color)
    {
        cout << "Erorr: " << color.what() << endl;
    }

    cout << endl;


    backyardCamera.turnOn();

    backyardCamera.displayDeviceInfo();

    backyardCamera.startRecording();
    cout << endl;

    backyardCamera.displayDeviceInfo();

    backyardCamera.stopRecording();
    cout << endl;

    backyardCamera.displayDeviceInfo();

    backyardCamera.turnOff();


    bedroomThermostat.turnOn();

    bedroomThermostat.displayDeviceInfo();

    bedroomThermostat.setTempMode("Cooling");
    cout << endl;

    bedroomThermostat.displayDeviceInfo();

    try 
    {
        cout << "Setting temperature to 200..." << endl;
        bedroomThermostat.setTargetTemp(200);
    }
    catch(const DeviceException& temp)
    {
        cout << "Error: " << temp.what() << endl;
    }

    cout << endl;
    cout << "Setting temperature to 73..." << endl;
    bedroomThermostat.setTargetTemp(73);
    cout << endl;

    bedroomThermostat.displayDeviceInfo();

    bedroomThermostat.setMaxTemp(75);
    cout << endl;

    bedroomThermostat.displayDeviceInfo();

    bedroomThermostat.setTempMode("Heating");
    cout << endl;

    bedroomThermostat.displayDeviceInfo();

    bedroomThermostat.turnOff();


    livingRoomSpeaker.turnOn();

    livingRoomSpeaker.displayDeviceInfo();

    livingRoomSpeaker.setCurrentSong("Upbeat Song");
    cout << endl;

    livingRoomSpeaker.incrementVolume();
    cout << endl;

    livingRoomSpeaker.startSong();
    cout << endl;

    livingRoomSpeaker.displayDeviceInfo();

    livingRoomSpeaker.turnOff();


    /* does not work as of now
    // Use the manager to turn on devices by name
    manager.turnDeviceOn("Kitchen Lights");
    manager.turnDeviceOn("Backyard Camera");
    manager.turnDeviceOn("Bedroom Thermostat");
    manager.turnDeviceOn("Living Room Speaker");

    would work if the turn on capabilities were working
    // Display all devices and their status using the manager
    manager.showAllDevices();
    */

    return 0;
}
