void DigitalInAnalogIn::Refresh() {
    switch (m_mode) {
        case INPUT_ANALOG:
            // If the ShiftRegister was not set up for the analog input
            // when this ADC reading was captured then it is not valid
            if (!(AdcMgr.ShiftRegSnapshot() & m_modeControlBitMask)) {
                // If this is the first valid reading, reset the IIR filter
                if (!m_analogValid) {
                    AdcMgr.FilterReset(m_adcChannel, *m_adcResultConvertedPtr);
                    m_analogValid = true;
                }

                // Set the LED PWM representation of this connector's value
                uint8_t value = (*m_adcResultConvertedPtr) >> 7;
                // Set a lower threshold of when to show any duty on the LED
                if (value < 0x03) {
                    value = 0;
                }
                ShiftReg.LedPwmValue(m_clearCorePin, value);
            }
            break;
        case INPUT_DIGITAL:
            DigitalIn::Refresh();
            break;
        default:
            break;
    }
}