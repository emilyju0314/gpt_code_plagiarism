bool SerialBase::Parity(Parities newParity) {
    m_parity = newParity;

    switch (m_portMode) {
        case SPI:
            return false;
        case UART:
        default: {
            bool sercomEnabled = m_serPort->USART.CTRLA.bit.ENABLE;
            PortDisable();
            if (m_parity != PARITY_N) {
                // 0x1 to set a USART frame with parity
                m_serPort->USART.CTRLA.bit.FORM = 1;
                // Set the parity
                m_serPort->USART.CTRLB.bit.PMODE = m_parity;
            }
            else {
                // 0x0 to set a USART frame without parity
                m_serPort->USART.CTRLA.bit.FORM = 0;
            }
            if (sercomEnabled) {
                PortEnable();
            }
            return true;
        }
    }
}