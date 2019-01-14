#include "JuceHeader.h"
using namespace  tracktion_engine;
namespace te = tracktion_engine;
#pragma once

class AudioEngine : public Component {
public :

	AudioEngine();
	~AudioEngine();
	
	void addChannel(File file);
	void removeChannel();
	void removeTrack(te::AudioTrack & track);
	void initTransport();

private:

	te::WaveAudioClip::Ptr loadAudioFileAsClip(const File& file, int trackNumber);

	void addNewClipFromFile(const File& editFile, int trackNum);
	

	void removeAllClips(te::AudioTrack& track);

	void adjustClipProperties(tracktion_engine::WaveAudioClip& clip) const;

	te::Engine engine{ ProjectInfo::projectName };
	std::unique_ptr<te::Edit> edit;
	AudioFormatManager formatManager;
	std::unique_ptr<AudioFormatReaderSource> playSource;
	AudioTransportSource transport;

	int trackNum = 0;
	

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioEngine)
};