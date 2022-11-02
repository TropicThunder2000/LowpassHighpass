/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LowpassHighPassFilterAudioProcessorEditor::LowpassHighPassFilterAudioProcessorEditor (LowpassHighPassFilterAudioProcessor& p, juce::AudioProcessorValueTreeState& apvts)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible(cutofffrequencySlider);
      cutofffrequencySlider.setSliderStyle(
          juce::Slider::SliderStyle::LinearVertical);
      cutoffFrequencyAttachment.reset(
          new juce::AudioProcessorValueTreeState::SliderAttachment(
              apvts, "cutoff_frequency", cutofffrequencySlider));

      addAndMakeVisible(cutofffrequencyLabel);
    cutofffrequencyLabel.setText("Cutoff Frequency",
                                   juce::dontSendNotification);

      addAndMakeVisible(highpassButton);
      highpassAttachment.reset(
          new juce::AudioProcessorValueTreeState::
            ButtonAttachment(apvts, "highpass", highpassButton));

      addAndMakeVisible(highpassButtonLabel);
      highpassButtonLabel.setText("Highpass", juce::dontSendNotification);

      setSize(300, 600);
}

LowpassHighPassFilterAudioProcessorEditor::~LowpassHighPassFilterAudioProcessorEditor()
{
}

//==============================================================================
void LowpassHighPassFilterAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void LowpassHighPassFilterAudioProcessorEditor::resized()
{
    cutofffrequencySlider.setBounds({25, 45, 200, 300});
    cutofffrequencyLabel.setBounds({cutofffrequencySlider.getX() + 30,
                                    cutofffrequencySlider.getY() - 30,
                                    300, 50});
    highpassButton.setBounds(
        {cutofffrequencySlider.getX(),
         cutofffrequencySlider.getY() +
          cutofffrequencySlider.getHeight() + 15,
         30, 50});
    highpassButtonLabel.setBounds(
        {cutofffrequencySlider.getX() + highpassButton.getWidth() + 15,
         highpassButton.getY(),
         cutofffrequencySlider.getWidth() - highpassButton.getWidth(),
         highpassButton.getHeight()});
}
