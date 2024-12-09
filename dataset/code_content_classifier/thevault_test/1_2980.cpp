void SerialBase::TxPump() {
    while (m_outHead != m_outTail) {
        if (!m_serPort->USART.INTFLAG.bit.DRE) {
            // Data register is full; can't send anything more right now
            return;
        }
        int32_t nextIndex = NextIndex(m_outHead);
        m_serPort->USART.DATA.bit.DATA = m_bufferOut[m_outHead];
        m_outHead = nextIndex;
    }

    DisableDreInterruptUart();
}