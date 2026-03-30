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

    cout << "Turning lights on..." << endl;

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

    cout << endl;

    cout << "Turning camera on..." << endl;

    backyardCamera.turnOn();

    backyardCamera.displayDeviceInfo();

    backyardCamera.startRecording();
    cout << endl;

    backyardCamera.displayDeviceInfo();

    backyardCamera.stopRecording();
    cout << endl;

    backyardCamera.displayDeviceInfo();

    backyardCamera.turnOff();

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

    cout << "Turning thermostat on..." << endl;

    bedroomThermostat.turnOn();

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

    bedroomThermostat.turnOff();

    cout << "Turning speaker on..." << endl;

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

    return 0;
}
