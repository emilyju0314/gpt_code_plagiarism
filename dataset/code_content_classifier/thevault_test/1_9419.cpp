AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
{
    AudioProcessorValueTreeState::ParameterLayout params (
        std::make_unique<AudioParameterFloat>(
            "MainGain",
            "Gain",
            NormalisableRange<float>(0.0, 1.0),
            0.8,
            String(),
            AudioProcessorParameter::genericParameter,
            [](float value, int /* maxLength */) {
                return String(Decibels::gainToDecibels(value), 1) + "dB";
            },
            nullptr
        ),
        std::make_unique<AudioParameterBool>(
            "MainMute",
            "Mute",
            false
       )
    );

    return params;
}