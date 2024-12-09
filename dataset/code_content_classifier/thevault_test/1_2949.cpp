void DigitalInOutAnalogOut::AnalogWriteUncalibrated(uint16_t value) {
    if (m_mode != OUTPUT_ANALOG) {
        return;
    }

    value = min(value, DAC_MAX_VALUE);

    // Set the LED blink value
    ShiftReg.LedPwmValue(m_clearCorePin, value * UINT8_MAX / DAC_MAX_VALUE);

    DacRegisterWrite(value);
}