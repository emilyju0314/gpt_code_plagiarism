void DigitalInOutAnalogOut::DacRegisterWrite(uint16_t value) {
    if (DAC->DATA[0].reg != value) {
        SYNCBUSY_WAIT(DAC, DAC_SYNCBUSY_DATA0);
        DAC->DATA[0].reg = value;
    }
}