/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Tone_FinalAudioProcessorEditor::Tone_FinalAudioProcessorEditor (Tone_FinalAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    setSize (400, 150);

    addAndMakeVisible(filterLabel);

    addAndMakeVisible(ToneSlider);
    ToneSlider.setRange(100.0, 10000.0, 1.0);
    ToneSlider.setTextValueSuffix(" Hz");
    ToneSlider.addListener(this);
    ToneSlider.setValue(4000.0);
    ToneSlider.setSkewFactorFromMidPoint(1000.0);

    addAndMakeVisible(ToneLabel);
    ToneLabel.setText("Cutoff Frequency", juce::dontSendNotification);
    ToneLabel.attachToComponent(&ToneSlider, true);
}

Tone_FinalAudioProcessorEditor::~Tone_FinalAudioProcessorEditor()
{
}

//==============================================================================
void Tone_FinalAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void Tone_FinalAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    auto sliderLeft = 80;

    filterLabel.setBounds(120, 20, getWidth() - sliderLeft - 50, 20);
    ToneSlider.setBounds(sliderLeft, 50, getWidth()- sliderLeft - 50, 50);

}

void Tone_FinalAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    //==============================================================================

    if (slider == &ToneSlider)
    {
        audioProcessor.currentSliderVal = slider->getValue();
    }
}