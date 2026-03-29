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

void SpeakerDevice::turnOn()
{
    cout << "This device has been turned on" << endl << endl;
    this->power = true;
}

void SpeakerDevice::turnOff()
{
    cout << "This device has been turned off" << endl << endl;
    this->power = false;
}

bool SpeakerDevice::getPower() const
{
    return this->power;
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
    cout << "The volume of the speaker has been altered" << endl;
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
    cout << "The volume of the speaker has been altered" << endl;
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
    cout << "The volume of the speaker has been altered" << endl;
}

void SpeakerDevice::setCurrentSong(string currentSong)
{
    if (getPower() == false)
    {
        throw DeviceException("This speaker is off. Cannot set current song.");
    }
    decrementBattery();
    this -> currentSong = currentSong;
    cout << "The current song of this speaker has been altered" << endl;
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
    cout << "The song has begun playing" << endl;
}

void SpeakerDevice::stopSong()
{
    if (getPower() == false)
    {
        throw DeviceException("This speaker is off. No song is playing.");
    }
    decrementBattery();
    this -> isPlaying = false;
    cout << "The song has stopped playing" << endl;
}

bool SpeakerDevice::isSongPlaying() const
{
    return this->isPlaying;
}

void SpeakerDevice::setBattery(int battery)
{
    if (battery < 0 || battery > 100)
    {
        throw DeviceException("Battery must be between 0 and 100.");
    }
    else
    {
        this->battery = battery;
    }
}

void SpeakerDevice::decrementBattery()
{
    this -> battery -= 5;
}

int SpeakerDevice::getBattery() const
{
    if (battery <= 0)
    {
        throw DeviceException("Your battery for this device has been depleted. Please charge this device to continue its use.");
    }
    return this->battery;
}

void SpeakerDevice::displayDeviceInfo()
{
    cout << "~~~Speaker Device Information~~~" << endl;
    cout << "The name of the speaker is " << this->getName() << endl;
    cout << "The speaker is " << (this->getPower() ? "on" : "off") << endl;
    cout << "The volume of the speaker is " << this->getVolume() << endl;
    cout << "There is " << (this->isSongPlaying() ? "a" : "no") << " song playing" << endl;
    if (this->isSongPlaying())
    {
        cout << "The current song playing is " << this->getCurrentSong() << endl;
    }
    cout << "The battery percentage is " << this->getBattery() << "%" << endl;

    cout << endl;
}
