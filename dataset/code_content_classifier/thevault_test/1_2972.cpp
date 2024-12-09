bool SerialBase::SendChar(uint8_t charToSend) {
    // Guard against sending to a closed port or an incorrect mode.
    if (!m_portOpen || m_portMode == PortModes::SPI) {
        return false;
    }
    // Calculate next location with wrap
    uint32_t nextIndex = NextIndex(m_outTail);

    // If the buffer is full, elevate the priority of the interrupt to drain
    // the buffer and wait for some space to open up
    while (nextIndex == m_outHead) {
        if (!m_portOpen) {
            return false;
        }
    }

    // Queue this character on tail
    m_bufferOut[m_outTail] = charToSend;
    m_outTail = nextIndex;

    EnableDreInterruptUart();
    return true;
}