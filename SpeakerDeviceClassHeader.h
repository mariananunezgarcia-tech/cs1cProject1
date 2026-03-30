#ifndef SPEAKERDEVICECLASSHEADER_H
#define SPEAKERDEVICECLASSHEADER_H
#include "BaseDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"
#include "DevicePowerInterface.h"
#include "BatteryInterface.h"
#include "DeviceIntensityInterface.h"

class SpeakerDevice: public BaseDevice,
                     public DevicePowerInterface,
                     public BatteryInterface,
					           public DeviceIntensityInterface
{
    public:
    SpeakerDevice();
    SpeakerDevice(string name, int volume);
    ~SpeakerDevice();

    //virtual interface methods
    virtual bool getPower() const;	 //Returns the current power state
    virtual int  getBattery() const; //Returns the current battery percentage

    virtual void turnOn();				  //Turns the device on
    virtual void turnOff();			      //Turns the device off
    virtual void setBattery(int battery); //Sets the battery's percentage
    virtual void decrementBattery();	  //Decreases the battery's percentage

    virtual int  getIntensity();
	  virtual void setIntensity(int volume);
	  virtual void increaseIntensity();
	  virtual void increaseIntensity(int amount);
	  virtual void decreaseIntensity();
	  virtual void decreaseIntensity(int amount);

    virtual void displayDeviceInfo();

    //device specific methods
    void setCurrentSong(string currentSong);
    string getCurrentSong();

    void startSong();
    void stopSong();
    bool isSongPlaying() const;

    private:
    int volume = 0;
    bool isPlaying = false;
    string currentSong = "";

    bool power = false;
    int  battery = 100;
};
#endif
