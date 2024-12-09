void DigitalInOutAnalogOut::Initialize(ClearCorePins clearCorePin) {
    // Perform any digital input/output initializing
    DacInitialize();
    DigitalInOut::Initialize(clearCorePin);
    // Mode is now set to INPUT_DIGITAL

    // Initialize the PMUX for analog output, but don't enable the MUX
    PMUX_SELECTION(m_inputPort, m_inputDataBit, PER_ANALOG);   // (-) DAC output
    PMUX_SELECTION(m_analogPort, m_analogDataBit, PER_ANALOG); // (+) DAC output
}