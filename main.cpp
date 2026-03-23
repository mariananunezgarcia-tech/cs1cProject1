#include <iostream>
#include "BaseDeviceClassHeader.h"
#include "LightsDeviceClassHeader.h"
#include "CameraDeviceClassHeader.h"
#include "ThermostatDeviceClassHeader.h"
#include "SpeakerDeviceClassHeader.h"
#include "DeviceManagerClassHeader.h"
using namespace std;
int main() {

    LightsDevice kitchenLights("Kitchen Lights", "White", 7);
    cout << "The name of the lights is " << kitchenLights.getName() << endl;
    cout << "The lights are " << (kitchenLights.getPower() ? "on" : "off") << endl;
    cout << endl;

    kitchenLights.turnOn();

    cout << "The name of the lights is " << kitchenLights.getName() << endl;
    cout << "The lights are " << (kitchenLights.getPower() ? "on" : "off") << endl;
    cout << "The color of the lights is " << kitchenLights.getColor() << endl;
    cout << "The brightness of the light is " << kitchenLights.getBrightness() << endl;
    cout << "The battery percentage is " << kitchenLights.getBattery() << "%" << endl;

    cout << endl;

    kitchenLights.setBrightness(10);

    cout << "Setting color to Green..." << endl;
    kitchenLights.setColor("Green");
    cout << endl;

    cout << "The name of the lights is " << kitchenLights.getName() << endl;
    cout << "The lights are " << (kitchenLights.getPower() ? "on" : "off") << endl;
    cout << "The color of the lights is " << kitchenLights.getColor() << endl;
    cout << "The brightness of the light is " << kitchenLights.getBrightness() << endl;
    cout << "The battery percentage is " << kitchenLights.getBattery() << "%" << endl;

    cout << endl;
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

    CameraDevice backyardCamera("Backyard Camera");
    cout << "The name of the camera is " << backyardCamera.getName() << endl;
    cout << "The camera is " << (backyardCamera.getPower() ? "on" : "off") << endl;
    cout << "The battery percentage is " << backyardCamera.getBattery() << "%" << endl;

    cout << endl;

    backyardCamera.turnOn();

    cout << "The name of the camera is " << backyardCamera.getName() << endl;
    cout << "The camera is " << (backyardCamera.getPower() ? "on" : "off") << endl;
    cout << "There has been " << backyardCamera.getNumOfMotion() << " times where motion has been detected since you last checked" << endl;
    cout << "There is " << (backyardCamera.isMotionDetected() ? "" : "no ") << "motion detected right now" << endl;
    cout << "The camera is " << (backyardCamera.isRecording() ? "" : "not ") << "recording right now" << endl;
    cout << "The battery percentage is " << backyardCamera.getBattery() << "%" << endl;

    cout << endl;

    backyardCamera.startRecording();
    cout << endl;

    cout << "The name of the camera is " << backyardCamera.getName() << endl;
    cout << "The camera is " << (backyardCamera.getPower() ? "on" : "off") << endl;
    cout << "There has been " << backyardCamera.getNumOfMotion() << " times where motion has been detected since you last checked" << endl;
    cout << "There is" << (backyardCamera.isMotionDetected() ? " " : " no ") << "motion detected right now" << endl;
    cout << "The camera is" << (backyardCamera.isRecording() ? " " : " not ") << "recording right now" << endl;
    cout << "The battery percentage is " << backyardCamera.getBattery() << "%" << endl;

    cout << endl;

    backyardCamera.stopRecording();

    cout << endl;

    cout << "The name of the camera is " << backyardCamera.getName() << endl;
    cout << "The camera is " << (backyardCamera.getPower() ? "on" : "off") << endl;
    cout << "There has been " << backyardCamera.getNumOfMotion() << " times where motion has been detected since you last checked" << endl;
    cout << "There is " << (backyardCamera.isMotionDetected() ? "" : "no ") << "motion detected right now" << endl;
    cout << "The camera is " << (backyardCamera.isRecording() ? "" : "not ") << "recording right now" << endl;
    cout << "The battery percentage is " << backyardCamera.getBattery() << "%" << endl;
    cout << endl;

    backyardCamera.turnOff();

    ThermostatDevice bedroomThermostat("Bedroom Thermostat", 80, 65);
    cout << "The name of the thermostat is " << bedroomThermostat.getName() << endl;
    cout << "The thermostat is " << (bedroomThermostat.getPower() ? "on" : "off") << endl;
    cout << endl;

    bedroomThermostat.turnOn();

    cout << "The name of the thermostat is " << bedroomThermostat.getName() << endl;
    cout << "The thermostat is " << (bedroomThermostat.getPower() ? "on" : "off") << endl;
    cout << "The max temp of the thermostat is set to " << bedroomThermostat.getMaxTemp() << endl;
    cout << "The min temp of the thermostat is set to " << bedroomThermostat.getMinTemp() << endl;
    cout << "The current temp of the thermostat is " << bedroomThermostat.getCurrentTemp() << endl;
    cout << "The mode of the thermostat is " << bedroomThermostat.getTempMode() << endl;
    cout << "The battery percentage is " << bedroomThermostat.getBattery() << "%" << endl;

    cout << endl;

    bedroomThermostat.setTempMode("Cooling");
    cout << endl;

    cout << "The name of the thermostat is " << bedroomThermostat.getName() << endl;
    cout << "The thermostat is " << (bedroomThermostat.getPower() ? "on" : "off") << endl;
    cout << "The max temp of the thermostat is set to " << bedroomThermostat.getMaxTemp() << endl;
    cout << "The min temp of the thermostat is set to " << bedroomThermostat.getMinTemp() << endl;
    cout << "The current temp of the thermostat is " << bedroomThermostat.getCurrentTemp() << endl;
    cout << "The mode of the thermostat is " << bedroomThermostat.getTempMode() << endl;
    cout << "The battery percentage is " << bedroomThermostat.getBattery() << "%" << endl;
    cout << endl;

    try 
    {
        cout << "Setting temperature to 200..." << endl;
        bedroomThermostat.setTargetTemp(200);
    }
    catch(const DeviceException& temp)
    {
        cout << "Error: " << temp.what() << endl;
    }

    cout << "Setting temperature to 73..." << endl;
    bedroomThermostat.setTargetTemp(73);
    cout << endl;

    cout << "The name of the thermostat is " << bedroomThermostat.getName() << endl;
    cout << "The thermostat is " << (bedroomThermostat.getPower() ? "on" : "off") << endl;
    cout << "The max temp of the thermostat is set to " << bedroomThermostat.getMaxTemp() << endl;
    cout << "The min temp of the thermostat is set to " << bedroomThermostat.getMinTemp() << endl;
    cout << "The current temp of the thermostat is " << bedroomThermostat.getCurrentTemp() << endl;
    cout << "The mode of the thermostat is " << bedroomThermostat.getTempMode() << endl;
    cout << "The battery percentage is " << bedroomThermostat.getBattery() << "%" << endl;

    cout << endl;

    bedroomThermostat.setMaxTemp(75);
    cout << endl;

    cout << "The name of the thermostat is " << bedroomThermostat.getName() << endl;
    cout << "The thermostat is " << (bedroomThermostat.getPower() ? "on" : "off") << endl;
    cout << "The max temp of the thermostat is set to " << bedroomThermostat.getMaxTemp() << endl;
    cout << "The min temp of the thermostat is set to " << bedroomThermostat.getMinTemp() << endl;
    cout << "The current temp of the thermostat is " << bedroomThermostat.getCurrentTemp() << endl;
    cout << "The mode of the thermostat is " << bedroomThermostat.getTempMode() << endl;
    cout << "The battery percentage is " << bedroomThermostat.getBattery() << "%" << endl;
    cout << endl;

    bedroomThermostat.setTempMode("Heating");
    cout << endl;

    cout << "The name of the thermostat is " << bedroomThermostat.getName() << endl;
    cout << "The thermostat is " << (bedroomThermostat.getPower() ? "on" : "off") << endl;
    cout << "The max temp of the thermostat is set to " << bedroomThermostat.getMaxTemp() << endl;
    cout << "The min temp of the thermostat is set to " << bedroomThermostat.getMinTemp() << endl;
    cout << "The current temp of the thermostat is " << bedroomThermostat.getCurrentTemp() << endl;
    cout << "The mode of the thermostat is " << bedroomThermostat.getTempMode() << endl;
    cout << "The battery percentage is " << bedroomThermostat.getBattery() << "%" << endl;
    cout << endl;

    bedroomThermostat.turnOff();

    SpeakerDevice livingRoomSpeaker("Living Room Speaker", 5);
    cout << "The name of the speaker is " << livingRoomSpeaker.getName() << endl;
    cout << "The speaker is " << (livingRoomSpeaker.getPower() ? "on" : "off") << endl;
    cout << endl;

    livingRoomSpeaker.turnOn();

    cout << "The name of the speaker is " << livingRoomSpeaker.getName() << endl;
    cout << "The speaker is " << (livingRoomSpeaker.getPower() ? "on" : "off") << endl;
    cout << "The volume of the speaker is " << livingRoomSpeaker.getVolume() << endl;
    cout << "There is " << (livingRoomSpeaker.isSongPlaying() ? "a" : "no") << " song playing" << endl;
    cout << "The battery percentage is " << livingRoomSpeaker.getBattery() << "%" << endl;

    cout << endl;

    livingRoomSpeaker.setCurrentSong("Upbeat Song");

    livingRoomSpeaker.incrementVolume();

    livingRoomSpeaker.startSong();

    cout << endl;

    cout << "The name of the speaker is " << livingRoomSpeaker.getName() << endl;
    cout << "The speaker is " << (livingRoomSpeaker.getPower() ? "on" : "off") << endl;
    cout << "The volume of the speaker is " << livingRoomSpeaker.getVolume() << endl;
    cout << "There is " << (livingRoomSpeaker.isSongPlaying() ? "a" : "no") << " song playing" << endl;
    if (livingRoomSpeaker.isSongPlaying())
    {
        cout << "The current song playing is " << livingRoomSpeaker.getCurrentSong() << endl;
    }
    cout << "The battery percentage is " << livingRoomSpeaker.getBattery() << "%" << endl;

    cout << endl;

    livingRoomSpeaker.turnOff();

    // manager section
    DeviceManager manager; // Create an instance of DeviceManager

    // Add devices to the manager using pointers to the existing device objects
    manager.addDevice(&kitchenLights);
    manager.addDevice(&backyardCamera);
    manager.addDevice(&bedroomThermostat);
    manager.addDevice(&livingRoomSpeaker);

    // Use the manager to turn on devices by name
    manager.turnDeviceOn("Kitchen Lights");
    manager.turnDeviceOn("Backyard Camera");
    manager.turnDeviceOn("Bedroom Thermostat");
    manager.turnDeviceOn("Living Room Speaker");

    // Display all devices and their status using the manager
    manager.showAllDevices();

    return 0;
}
