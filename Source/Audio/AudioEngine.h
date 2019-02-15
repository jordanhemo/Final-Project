#pragma once

#include "JuceHeader.h"
#include "../modules/juce_blocks_basics/juce_blocks_basics.h"

using namespace tracktion_engine;
namespace te = tracktion_engine;

class AudioEngine
{
public :

    AudioEngine();
    ~AudioEngine();

    void addChannel();
    void addChannel(File file);
    void removeChannel();
    void removeTrack(te::AudioTrack& track);
    void play();
    void stop();
    void pause();

    bool isPlaying();

    bool isDirty() { return dirty; }

    void setDirty(bool inDirty) { dirty = inDirty; }

    TrackList& getTrackList() { return edit->getTrackList(); }

	void changeVolumeFromSlider(float sliderValue, int trackId);

private:

    te::WaveAudioClip::Ptr loadAudioFileAsClip(const File& file, int trackNumber);

    void addNewClipFromFile(const File& editFile, int trackNum);

    void removeAllClips(te::AudioTrack& track);

    void adjustClipProperties(tracktion_engine::WaveAudioClip& clip) const;

    te::Engine engine{ProjectInfo::projectName};

    AudioFormatManager formatManager;
    std::unique_ptr<AudioFormatReaderSource> playSource;

    std::unique_ptr<te::Edit> edit;
	std::unique_ptr < te::VolumeAndPanPlugin> volumeAndPanPlugin;

    bool dirty = true;
    int trackNum = 0;
    void removeAllTracks();

    TransportControl& getTransport() const;
};