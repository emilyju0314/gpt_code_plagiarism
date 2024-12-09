void DigitalInOutAnalogOut::DacEnable() {
    // Make sure that a valid command has been written to the DAC
    DacRegisterWrite(m_dacZero);

    // Set up the INPUT pin as DAC output
    PMUX_ENABLE(m_inputPort, m_inputDataBit);   // (-) DAC output
    PMUX_ENABLE(m_analogPort, m_analogDataBit); // (+) DAC output

    SYNCBUSY_WAIT(DAC, DAC_SYNCBUSY_ENABLE);
    if (!DAC->CTRLA.bit.ENABLE) {
        DAC->CTRLA.bit.ENABLE = 1;
        SYNCBUSY_WAIT(DAC, DAC_SYNCBUSY_ENABLE);
    }

    while (!DAC->STATUS.vec.READY) {
        continue;
    }

    // Update the LED pattern
    ShiftReg.LedPwmValue(m_clearCorePin, 0);
    ShiftReg.LedInPwm(m_ledMask, true, m_clearCorePin);

    // Set the Cfg00_CFG00_AOUT_BIT to HIGH for use as an Analog Output
    ShiftReg.ShifterStateSet(ShiftRegister::SR_CFG00_AOUT_MASK);
}