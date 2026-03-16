#include <iostream>
#include "BaseDeviceClassHeader.h"
#include "LightsDeviceClassHeader.h"
#include "CameraDeviceClassHeader.h"
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

    return 0;
}
