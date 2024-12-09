void SerialBase::SpiClock(
    SpiClockPolarities polarity, SpiClockPhases phase) {
    m_polarity = polarity;
    m_phase = phase;

    // If we are not currently in SPI mode, don't apply the change yet.
    if (m_portMode != PortModes::SPI) {
        return;
    }
    bool sercomEnabled = m_serPort->USART.CTRLA.bit.ENABLE;
    PortDisable();
    m_serPort->SPI.CTRLA.bit.CPOL = m_polarity;
    m_serPort->SPI.CTRLA.bit.CPHA = m_phase;
    if (sercomEnabled) {
        PortEnable();
    }
}