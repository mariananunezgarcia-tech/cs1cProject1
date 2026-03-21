//
// Created by Mariana on 3/20/26.
//

#ifndef CS1CPROJECT1_BASEDEVICE_H
#define CS1CPROJECT1_BASEDEVICE_H

#include <string>
#include <iostream>
using namespace std;

class BaseDevice
{
protected:
    BaseDevice();
    BaseDevice(string name);

public:
    // changed destructor from protected to public
    // virtual keyword allows for runtime polymorphism :D
    virtual ~BaseDevice();

    string getName() const;
    void setName(string name);

    void turnOn();
    void turnOff();
    bool getPower() const;

    void setBattery(int battery);
    void decrementBattery();
    int getBattery() const;

    // Virtual keyword allows for runtime polymosphism
    virtual void displayStatus() const = 0;

private:
    string name = "";
    int battery = 100;
    bool power = false;
};

#endif //CS1CPROJECT1_BASEDEVICE_H
