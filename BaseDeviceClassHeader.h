#ifndef BASEDEVICECLASSHEADER_H
#define BASEDEVICECLASSHEADER_H
#include <string>
#include <iostream>
using namespace std;

class BaseDevice
{
    protected:
    BaseDevice();
    BaseDevice(string name);
    ~BaseDevice();

    public:
    string getName() const;
    void setName(string name);
    void turnOn();
    void turnOff();
    bool getPower() const;
    void setBattery(int battery);
    int getBattery();

private:
    string name = "";
    int battery = 100;
    bool power = false;

};
#endif