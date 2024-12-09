DigitalInOutAnalogOut::DigitalInOutAnalogOut(
    ShiftRegister::Masks ledMask,
    const PeripheralRoute *inputInfo,
    const PeripheralRoute *outputInfo,
    const PeripheralRoute *outputAnalogInfo,
    bool digitalLogicInversion)
    : DigitalInOut(ledMask, inputInfo, outputInfo, digitalLogicInversion),
      m_analogPort(outputAnalogInfo->gpioPort),
      m_analogDataBit(outputAnalogInfo->gpioPin),
      m_dacZero(0),
      m_dacSpan(DAC_DEFAULT_SPAN) {}