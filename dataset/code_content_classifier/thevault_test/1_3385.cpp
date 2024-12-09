std::int32_t FreqModCallback(std::uint32_t t, std::uint32_t p) {
    static std::int32_t fb = 0;                                 // Static variable to store feeback
    
    using AWSynth = Audio::AWSynthSource;
    
    // Operator 3
    constexpr const std::int32_t R3 = 1;                        // Pitch ratio 1
    constexpr const std::int32_t A3_Q10 = fmGain(25);           // Output level 25%
    std::int32_t o3 = AWSynth::sin(p*R3)*A3_Q10/(1<<10);        // Generate osc 3 output
    
    // Operator 2
    constexpr const std::int32_t R2 = 3;                        // Pitch ratio 3
    constexpr const std::int32_t A2_Q10 = fmGain(45);           // Output level 45%
    std::int32_t o2 = AWSynth::sin(p*R2 + fb)*A2_Q10/(1<<10);   // Use feedback to modulate osc 2
    std::int32_t env2 = AWSynth::ramp<1600>(1600-t);            // Decay envelope for osc 2
    o2 = o2 * ((env2*env2)>>14) / (1<<14);                      // Squared envelope gives nicer result
    
    // Operator 1
    constexpr const std::int32_t R1 = 1;                        // Pitch ratio 1
    std::int32_t o1 = AWSynth::sin(p*R1 + o2+o3);               // Use osc 2 and osc 3 to modulate osc 1
    
    // Feedback
    constexpr const std::int32_t AFB_Q10 = fmGain(25);          // Feedback level 25 %
    fb = o1*AFB_Q10/(1<<10);                                    // Store output of osc 1 to feedback
    
    return o1;
}