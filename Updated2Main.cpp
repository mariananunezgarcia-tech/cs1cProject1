#include <iostream>
#include "BaseDeviceClassHeader.h"
#include "LightsDeviceClassHeader.h"
#include "CameraDeviceClassHeader.h"
#include "ThermostatDeviceClassHeader.h"
#include "SpeakerDeviceClassHeader.h"
#include "DeviceManagerClassHeader.h"
#include "DevicePowerInterface.h"
#include "BatteryInterface.h"
#include "LockDeviceClassHeader.h"
#include "RoombaDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"

using namespace std;

int main()
{
    // manager section
    DeviceManager manager;  // Create an instance of DeviceManager

    LightsDevice kitchenLights("Kitchen Lights", "White", 7);
    CameraDevice backyardCamera("Backyard Camera");
    ThermostatDevice bedroomThermostat("Bedroom Thermostat", 80, 65);
    SpeakerDevice livingRoomSpeaker("Living Room Speaker", 5);
    LockDevice frontDoorLock("Front Door Lock", "1234");
    RoombaDevice downstairsRoomba("Downstairs Roomba", 2);

    // Add devices to the manager using pointers to the existing device objects
    manager.addDevice(&kitchenLights);
    manager.addDevice(&backyardCamera);
    manager.addDevice(&bedroomThermostat);
    manager.addDevice(&livingRoomSpeaker);
    manager.addDevice(&frontDoorLock);
    manager.addDevice(&downstairsRoomba);

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

    try
    {
        cout << "Starting recording..." << endl;
        backyardCamera.startRecording();
    }
    catch (const PowerException& power)
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

    try
    {
        cout << "Setting temperature to 200..." << endl;
        bedroomThermostat.setTargetTemp(200);
    }
    catch (const InvalidInputException& temp)
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
    cout << endl;

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
    cout << endl;

    // Added Lock and Roomba devices //

    cout << "Turning lock on..." << endl;
    frontDoorLock.turnOn();
    frontDoorLock.displayDeviceInfo();

    cout << "Unlocking with correct PIN..." << endl;
    frontDoorLock.unlock("1234");
    cout << endl;

    frontDoorLock.displayDeviceInfo();

    cout << "Locking again..." << endl;
    frontDoorLock.lock();
    cout << endl;

    try
    {
        cout << "Trying wrong PIN..." << endl;
        frontDoorLock.unlock("9999");
    }
    catch (const DeviceException& e)
    {
        cout << e.what() << endl;
    }

    cout << endl;
    frontDoorLock.displayDeviceInfo();
    frontDoorLock.turnOff();
    cout << endl;

    cout << "Turning Roomba on..." << endl;
    downstairsRoomba.turnOn();
    downstairsRoomba.displayDeviceInfo();

    cout << "Starting cleaning..." << endl;
    downstairsRoomba.startCleaning();
    cout << endl;

    downstairsRoomba.displayDeviceInfo();

    cout << "Changing suction level to 3..." << endl;
    downstairsRoomba.setSuctionLevel(3);
    cout << endl;

    cout << "Returning Roomba to dock..." << endl;
    downstairsRoomba.returnToDock();
    cout << endl;

    downstairsRoomba.displayDeviceInfo();

    cout << "Emptying dust bin..." << endl;
    downstairsRoomba.emptyDustBin();
    cout << endl;

    downstairsRoomba.displayDeviceInfo();
    downstairsRoomba.turnOff();
    cout << endl;

    cout << "Showing all devices from manager..." << endl << endl;
    manager.showAllDevices();

    return 0;
}
