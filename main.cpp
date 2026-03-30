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

    cout << "~~~Interacting with Kitchen Lights~~~" << endl;
    cout << "Turning lights on..." << endl;

    manager.turnDeviceOn(kitchenLights.getName());

    kitchenLights.displayDeviceInfo();

    kitchenLights.setBrightness(10);
    cout << endl;

    cout << "Setting color to Green..." << endl;
    kitchenLights.setColor("Green");
    cout << endl;

    kitchenLights.displayDeviceInfo();

    manager.turnDeviceOff(kitchenLights.getName());

    cout << "~~~Interacting with Backyard Camera~~~" << endl;
    cout << "Turning camera on..." << endl;

    manager.turnDeviceOn(backyardCamera.getName());

    backyardCamera.displayDeviceInfo();

    backyardCamera.startRecording();
    cout << endl;

    backyardCamera.displayDeviceInfo();

    backyardCamera.stopRecording();
    cout << endl;

    backyardCamera.displayDeviceInfo();

    manager.turnDeviceOff(backyardCamera.getName());

    // test case for power exception
    try
    {
        cout << "Starting recording..." << endl;
        backyardCamera.startRecording();
    }
    catch(const PowerException& power)
    {
        cout << power.what() << endl;
    }

    cout << endl;

    cout << "~~~Interacting with Bedroom Thermostat~~~" << endl;
    cout << "Turning thermostat on..." << endl;

    manager.turnDeviceOn(bedroomThermostat.getName());

    bedroomThermostat.displayDeviceInfo();

    bedroomThermostat.setTempMode("Cooling");
    cout << endl;

    bedroomThermostat.displayDeviceInfo();


    // test case for invalid input exception
    try
    {
        cout << "Setting temperature to 200..." << endl;
        bedroomThermostat.setTargetTemp(200);
    }
    catch(const InvalidInputException& temp)
    {
        cout << temp.what() << endl;
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

    manager.turnDeviceOff(bedroomThermostat.getName());

    cout << "~~~Interacting with Living Room Speaker~~~" << endl;
    cout << "Turning speaker on..." << endl;

    manager.turnDeviceOn(livingRoomSpeaker.getName());

    livingRoomSpeaker.displayDeviceInfo();

    livingRoomSpeaker.setCurrentSong("Upbeat Song");
    cout << endl;

    livingRoomSpeaker.incrementVolume();
    cout << endl;

    livingRoomSpeaker.startSong();
    cout << endl;

    livingRoomSpeaker.displayDeviceInfo();

    manager.turnDeviceOff(livingRoomSpeaker.getName());

    cout << "~~~Turning all devices on~~~" << endl;
    manager.turnDeviceOn(kitchenLights.getName());
    manager.turnDeviceOn(backyardCamera.getName());
    manager.turnDeviceOn(bedroomThermostat.getName());
    manager.turnDeviceOn(livingRoomSpeaker.getName());

    manager.showAllDevices();

    cout << "~~~Turning all devices off~~~" << endl;
    manager.turnDeviceOff(kitchenLights.getName());
    manager.turnDeviceOff(backyardCamera.getName());
    manager.turnDeviceOff(bedroomThermostat.getName());
    manager.turnDeviceOff(livingRoomSpeaker.getName());
    return 0;
}