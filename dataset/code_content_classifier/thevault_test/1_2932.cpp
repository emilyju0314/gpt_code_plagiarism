void DigitalInOut::Initialize(ClearCorePins clearCorePin) {
    // Clean up any state that Reinitialize may require
    m_outState = false;
    m_isInFault = false;
    m_pulseActive = false;
    m_pulseStopPending = false;

    // Set up to multiplex with TC for periodic user output functions
    PMUX_SELECTION(m_outputPort, m_outputDataBit, PER_TIMER);

    // Perform any input initializing
    DigitalIn::Initialize(clearCorePin);
    // Mode is now set to INPUT_DIGITAL

    // Set up output pin as output now that the connector is initialized
    DATA_DIRECTION_OUTPUT(m_outputPort, m_outputDataMask);
}