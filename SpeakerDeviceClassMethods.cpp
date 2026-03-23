#include "SpeakerDeviceClassHeader.h"

SpeakerDevice::SpeakerDevice()
{

}
SpeakerDevice::SpeakerDevice(string name, int volume)
{
    setName(name);
    this -> volume = volume;
}
SpeakerDevice::~SpeakerDevice()
{

}

void SpeakerDevice::setVolume(int volume)
{
    if (getPower() == false)
    {
        throw DeviceException("This speaker is off. Cannot change volume.");
    }
    if (volume > 10 || volume < 0)
    {
        throw DeviceException("Volume must be between 0 and 10.");
    }
    decrementBattery();
    this -> volume = volume;
}

int SpeakerDevice::getVolume() const
{
    return this->volume;
}

void SpeakerDevice::incrementVolume()
{
    if (getPower() == false)
    {
        throw DeviceException("This speaker is off. Cannot change volume.");
    }
    if (this->volume == 10)
    {
        throw DeviceException("Speaker is already at maximum volume.");
    }
    decrementBattery();
    this -> volume = this->volume + 1;
}
void SpeakerDevice::decrementVolume()
{
    if (getPower() == false)
    {
        throw DeviceException("This speaker is off. Cannot change volume.");
    }
    if (this->volume == 0)
    {
        throw DeviceException("Speaker is already at minimum volume.");
    }
    decrementBattery();
    this -> volume = this->volume - 1;
}

void SpeakerDevice::setCurrentSong(string currentSong)
{
    if (getPower() == false)
    {
        throw DeviceException("This speaker is off. Cannot set current song.");
    }
    decrementBattery();
    this -> currentSong = currentSong;
}

string SpeakerDevice::getCurrentSong()
{
    if (getPower() == false)
    {
        throw DeviceException("This speaker is off. Cannot get current song.");
    }
    decrementBattery();
    return this->currentSong;
}

void SpeakerDevice::startSong()
{
    if (getPower() == false)
    {
        throw DeviceException("This speaker is off. Cannot start song.");
    }
    decrementBattery();
    this -> isPlaying = true;
}

void SpeakerDevice::stopSong()
{
    if (getPower() == false)
    {
        throw DeviceException("This speaker is off. No song is playing.");
    }
    decrementBattery();
    this -> isPlaying = false;
}

bool SpeakerDevice::isSongPlaying() const
{
    return this->isPlaying;
}