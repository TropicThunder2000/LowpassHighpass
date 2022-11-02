/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class LowpassHighPassFilterAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    LowpassHighPassFilterAudioProcessorEditor (LowpassHighPassFilterAudioProcessor&, juce::AudioProcessorValueTreeState&vts);
    ~LowpassHighPassFilterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    LowpassHighPassFilterAudioProcessor& audioProcessor;
        juce::Slider cutofffrequencySlider;
        std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>
            cutoffFrequencyAttachment;
        juce::Label cutofffrequencyLabel;

        juce::ToggleButton highpassButton;
        std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment>
            highpassAttachment;
        juce::Label highpassButtonLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LowpassHighPassFilterAudioProcessorEditor)
};
