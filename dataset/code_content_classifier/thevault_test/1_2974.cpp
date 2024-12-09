int32_t SerialBase::SpiTransferData(
    uint8_t const *writeBuf, uint8_t *readBuf, int32_t len) {
    if (!m_portOpen || m_portMode != SPI) {
        return 0;
    }

    int32_t iChar;
    for (iChar = 0; iChar < len; iChar++) {
        // Write data into Data register
        m_serPort->SPI.DATA.bit.DATA = writeBuf ? *writeBuf++ : 0;

        while (!m_serPort->SPI.INTFLAG.bit.RXC ||
                !m_serPort->SPI.INTFLAG.bit.TXC) {
            // If the port is not open, bail out
            if (!m_portOpen) {
                return iChar;
            }
            // Wait for it to complete
            continue;
        }

        if (readBuf) {
            *readBuf++ = m_serPort->SPI.DATA.bit.DATA;
        }
        else {
            // Read from the register (value unused).
            (void)m_serPort->SPI.DATA.bit.DATA;
        }
    }

    return iChar;
}