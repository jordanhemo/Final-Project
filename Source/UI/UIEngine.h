#pragma once

#include "JuceHeader.h"
#include "Audio/AudioEngine.h"
#include "ToolbarComponent.h"
#include "ChannelWindow.h"
#include "AudioSettings.h"
#include "GridComponent.h"
#include "PlayHeadComponent.h"

class UIEngine : public Component
{
public:
	UIEngine(AudioEngine& inEngine);
	
	void resized() override;

private:
	ToolbarComponent toolbar;
	ChannelWindow channelWindow;
	GridComponent gridWindow;
	Viewport viewport;
	PlayHeadComponent playhead;
	AudioEngine& engine;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UIEngine)
};
