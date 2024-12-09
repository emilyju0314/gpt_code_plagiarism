void DigitalInOutAnalogOut::AnalogWrite(uint16_t value) {
    if (m_mode != OUTPUT_ANALOG) {
        return;
    }

    value = min(value, DAC_MAX_VALUE);

    // Set the LED blink value
    ShiftReg.LedPwmValue(m_clearCorePin, value * UINT8_MAX / DAC_MAX_VALUE);

    // Factor in calibration
    uint16_t command = ((static_cast<uint32_t>(value) * m_dacSpan)
                        / DAC_MAX_VALUE) + m_dacZero;

    command = min(command, DAC_MAX_VALUE);

    DacRegisterWrite(command);
}