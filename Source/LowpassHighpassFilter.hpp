//
//  LowpassHighpassFilter.hpp
//  LowpassHighPassFilter - VST3
//
//  Created by Aditya Jeganath K on 23/09/22.
//

#ifndef LowpassHighpassFilter_hpp
#define LowpassHighpassFilter_hpp
#pragma once
#include <stdio.h>
#include <vector>
#include "JuceHeader.h"

class LowpassHighpassFilter {
public:
  void setHighpass(bool highpass);
  void setCutoffFrequency(float cutofffrequency);
  void setSamplingRate(float samplingrate);

  void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&);

private:
  bool highpass;
  float cutofffrequency;
  float samplingrate;

  std::vector<float> dnBuffer;
};
#endif 
