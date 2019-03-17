#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioThumbnailComponent.h"
#include "AudioThumbnailComponent.h"
class GridComponent  : public Component
{
public:
  
    GridComponent ();
    ~GridComponent();


    void paint (Graphics& g) override;
    void resized() override;



private:

	Viewport gridview;
	std::unique_ptr<AudioThumbnailComponent> audioThumbnailComponent;
	//AudioThumbnailComponent audiothumbnailcomponent; //need to creat deafult constracor
	


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GridComponent)
};
