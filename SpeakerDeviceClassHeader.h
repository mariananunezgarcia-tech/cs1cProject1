#ifndef SPEAKERDEVICECLASSHEADER_H_
#define SPEAKERDEVICECLASSHEADER_H_
#include "BaseDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"
#include "DevicePowerInterface.h"
#include "BatteryInterface.h"

class SpeakerDevice: public BaseDevice,
                    public DevicePowerInterface,
                    public BatteryInterface
{
    public:
    SpeakerDevice();
    SpeakerDevice(string name, int volume);
    ~SpeakerDevice();

    //virtual interface methods
    virtual void setName(string name);
	virtual string getName();

    virtual bool getPower() const;	 //Returns the current power state
    virtual int  getBattery() const; //Returns the current battery percentage

    virtual void turnOn();				  //Turns the device on
    virtual void turnOff();			      //Turns the device off
    virtual void setBattery(int battery); //Sets the battery's percentage
    virtual void decrementBattery();	  //Decreases the battery's percentage

    //device specific methods
    void setVolume(int volume);
    int getVolume() const;
    void incrementVolume();
    void decrementVolume();

    void setCurrentSong(string currentSong);
    string getCurrentSong();

    void startSong();
    void stopSong();
    bool isSongPlaying() const;

    private:
    int volume = 0;
    bool isPlaying = false;
    string currentSong = "";
    string name;

    bool power = false;
    int  battery = 100;
};




#endif /* SPEAKERDEVICECLASSHEADER_H_ */
