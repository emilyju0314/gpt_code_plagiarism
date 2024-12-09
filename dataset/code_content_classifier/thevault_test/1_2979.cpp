void SerialBase::RxProc() {
    // Must reinitialize to clear ort problems
    if (m_serPort->USART.RXERRCNT.reg != 0) {
        // On break detected, flush inBuf and insert flag character
        m_inTail = 0;
        m_inHead = 0;
        m_bufferIn[m_inTail++] = SerialBase::BREAK_DETECTED;

        // Clear error to allow more interrupts
        m_serPort->USART.INTFLAG.bit.ERROR = 1;
    }

    // Generate wrapped next location
    uint32_t nextIndex = NextIndex(m_inTail);
    while (m_serPort->USART.INTFLAG.bit.RXC && nextIndex != m_inHead) {
        m_bufferIn[m_inTail] = m_serPort->USART.DATA.bit.DATA;
        m_inTail = nextIndex;
        nextIndex = NextIndex(m_inTail);
    }
    if (nextIndex == m_inHead) {
        DisableRxcInterruptUart();
    }
}