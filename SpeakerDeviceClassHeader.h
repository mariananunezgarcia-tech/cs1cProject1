#ifndef SPEAKERDEVICECLASSHEADER_H
#define SPEAKERDEVICECLASSHEADER_H
#include "BaseDeviceClassHeader.h"
#include "ExceptionsClassHeader.h"

class SpeakerDevice: public BaseDevice
{
    public:
    SpeakerDevice();
    SpeakerDevice(string name, int volume);
    ~SpeakerDevice();

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
};
#endif