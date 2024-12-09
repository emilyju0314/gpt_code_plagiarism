uint8_t SerialBase::SpiTransferData(uint8_t data) {
    if (!m_portOpen || m_portMode != PortModes::SPI) {
        return 0;
    }
    // Write data into Data register
    m_serPort->SPI.DATA.bit.DATA = data;

    while (!m_serPort->SPI.INTFLAG.bit.RXC ||
            !m_serPort->SPI.INTFLAG.bit.TXC) {
        // If the port is not open, bail out
        if (!m_portOpen) {
            return 0;
        }
        // Wait for it to complete
        continue;
    }
    return m_serPort->SPI.DATA.bit.DATA;
}