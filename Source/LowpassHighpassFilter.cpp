//
//  LowpassHighpassFilter.cpp
//  LowpassHighPassFilter - VST3
//
//  Created by Aditya Jeganath K on 23/09/22.
//

#include "LowpassHighpassFilter.hpp"
void LowpassHighpassFilter::setHighpass(bool highpass) {
  this->highpass = highpass;
}

void LowpassHighpassFilter::setCutoffFrequency(float cutofffrequency) {
  this->cutofffrequency = cutofffrequency;
}

void LowpassHighpassFilter::setSamplingRate(float samplingrate) {
  this->samplingrate = samplingrate;
}

void LowpassHighpassFilter::processBlock(juce::AudioBuffer<float>& buffer,
                                         juce::MidiBuffer&) {
  
  constexpr auto Pi = 3.14159265359f;

  dnBuffer.resize(buffer.getNumChannels(), 0.f);

  const auto sign = highpass ? -1.f : 1.f;

  const auto tan = std::tan(Pi * cutofffrequency / samplingrate);
  
  const auto all = (tan - 1.f) / (tan + 1.f);

  for (auto channel = 0; channel < buffer.getNumChannels(); ++channel) {
    
    auto channelSamples = buffer.getWritePointer(channel);

    for (auto i = 0; i < buffer.getNumSamples(); ++i) {
        
      const auto inputSamples = channelSamples[i];
        
        const auto allpassFilteredSamples = all * inputSamples + dnBuffer[channel];
                                    
      dnBuffer[channel] = inputSamples - all * allpassFilteredSamples;

      const auto filterOutput = 0.5f * (inputSamples + sign * allpassFilteredSamples);
      channelSamples[i] = filterOutput;
    }
  }
}

