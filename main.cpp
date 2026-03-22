#include <iostream>
#include "BaseDeviceClassHeader.h"
#include "LightsDeviceClassHeader.h"
#include "CameraDeviceClassHeader.h"
#include "ThermostatDeviceClassHeader.h"
using namespace std;
int main() {

    LightsDevice kitchenLights("Kitchen Lights", "White", 7);
    cout << "The name of the lights is " << kitchenLights.getName() << endl;
    cout << "The lights are " << (kitchenLights.getPower() ? "on" : "off") << endl;
    cout << endl;

    kitchenLights.turnOn();
    cout << "This device has been turned on" << endl;
    cout << endl;

    cout << "The name of the lights is " << kitchenLights.getName() << endl;
    cout << "The lights are " << (kitchenLights.getPower() ? "on" : "off") << endl;
    cout << "The color of the lights is " << kitchenLights.getColor() << endl;
    cout << "The brightness of the light is " << kitchenLights.getBrightness() << endl;
    cout << "The battery percentage is " << kitchenLights.getBattery() << "%" << endl;

    cout << endl;

    kitchenLights.setBrightness(10);
    cout << "The brightness of this device has been altered" << endl;

    cout << "Setting color to Green..." << endl;
    kitchenLights.setColor("Green");
    cout << "The color of this device has been altered" << endl;
    cout << endl;

    cout << "The name of the lights is " << kitchenLights.getName() << endl;
    cout << "The lights are " << (kitchenLights.getPower() ? "on" : "off") << endl;
    cout << "The color of the lights is " << kitchenLights.getColor() << endl;
    cout << "The brightness of the light is " << kitchenLights.getBrightness() << endl;
    cout << "The battery percentage is " << kitchenLights.getBattery() << "%" << endl;

    cout << endl;
    kitchenLights.turnOff();
    cout << "This device has been turned off" << endl;

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
    cout << "This device has been turned on" << endl;
    cout << endl;

    cout << "The name of the camera is " << backyardCamera.getName() << endl;
    cout << "The camera is " << (backyardCamera.getPower() ? "on" : "off") << endl;
    cout << "There has been " << backyardCamera.getNumOfMotion() << " times where motion has been detected since you last checked" << endl;
    cout << "There is " << (backyardCamera.isMotionDetected() ? "" : "no ") << "motion detected right now" << endl;
    cout << "The camera is " << (backyardCamera.isRecording() ? "" : "not ") << "recording right now" << endl;
    cout << "The battery percentage is " << backyardCamera.getBattery() << "%" << endl;

    cout << endl;

    backyardCamera.startRecording();
    cout << "This device has begun recording" << endl;
    cout << endl;

    cout << "The name of the camera is " << backyardCamera.getName() << endl;
    cout << "The camera is " << (backyardCamera.getPower() ? "on" : "off") << endl;
    cout << "There has been " << backyardCamera.getNumOfMotion() << " times where motion has been detected since you last checked" << endl;
    cout << "There is" << (backyardCamera.isMotionDetected() ? " " : " no ") << "motion detected right now" << endl;
    cout << "The camera is" << (backyardCamera.isRecording() ? " " : " not ") << "recording right now" << endl;
    cout << "The battery percentage is " << backyardCamera.getBattery() << "%" << endl;

    cout << endl;

    backyardCamera.stopRecording();
    cout << "This device has stopped recording" << endl;
    cout << endl;

    cout << "The name of the camera is " << backyardCamera.getName() << endl;
    cout << "The camera is " << (backyardCamera.getPower() ? "on" : "off") << endl;
    cout << "There has been " << backyardCamera.getNumOfMotion() << " times where motion has been detected since you last checked" << endl;
    cout << "There is " << (backyardCamera.isMotionDetected() ? "" : "no ") << "motion detected right now" << endl;
    cout << "The camera is " << (backyardCamera.isRecording() ? "" : "not ") << "recording right now" << endl;
    cout << "The battery percentage is " << backyardCamera.getBattery() << "%" << endl;
    cout << endl;

    backyardCamera.turnOff();
    cout << "This device has been turned off" << endl;
    cout << endl;

    ThermostatDevice bedroomThermostat("Bedroom Thermostat", 80, 65);
    cout << "The name of the thermostat is " << bedroomThermostat.getName() << endl;
    cout << "The thermostat is " << (bedroomThermostat.getPower() ? "on" : "off") << endl;
    cout << endl;

    bedroomThermostat.turnOn();
    cout << "This device has been turned on" << endl;
    cout << endl;

    cout << "The name of the thermostat is " << bedroomThermostat.getName() << endl;
    cout << "The thermostat is " << (bedroomThermostat.getPower() ? "on" : "off") << endl;
    cout << "The max temp of the thermostat is set to " << bedroomThermostat.getMaxTemp() << endl;
    cout << "The min temp of the thermostat is set to " << bedroomThermostat.getMinTemp() << endl;
    cout << "The current temp of the thermostat is " << bedroomThermostat.getCurrentTemp() << endl;
    cout << "The mode of the thermostat is " << bedroomThermostat.getTempMode() << endl;
    cout << "The battery percentage is " << bedroomThermostat.getBattery() << "%" << endl;

    cout << endl;

    bedroomThermostat.setTempMode("Cooling");
    cout << "The mode of the thermostat has been altered" << endl;
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
    cout << "The target temp of this thermostat has been altered" << endl;
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
    cout << "The max temp of this thermostat has been altered" << endl;
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
    cout << "The mode of this thermostat has been altered" << endl;
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
    cout << "This device has been turned off" << endl;
    cout << endl;

    return 0;
}
