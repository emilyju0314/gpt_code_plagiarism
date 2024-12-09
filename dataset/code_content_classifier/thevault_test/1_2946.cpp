void DigitalInOutAnalogOut::OutputCurrent(uint16_t currentuA) {
    uint16_t dacValue =
        static_cast<uint32_t>(currentuA) * DAC_MAX_VALUE / DAC_MAX_OUTPUT_UA;
    AnalogWrite(dacValue);
}