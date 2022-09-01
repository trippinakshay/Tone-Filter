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
class Tone_FinalAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Slider::Listener
{
public:
    Tone_FinalAudioProcessorEditor (Tone_FinalAudioProcessor&);
    ~Tone_FinalAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Tone_FinalAudioProcessor& audioProcessor;

    juce::LookAndFeel_V4 filterLookAndFeel;

    juce::Slider ToneSlider;
    juce::Label ToneLabel;

    juce::Label filterLabel{ {}, "Tone Filter" };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Tone_FinalAudioProcessorEditor)
};
