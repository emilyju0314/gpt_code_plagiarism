bool SerialBase::StopBits(uint8_t bits) {
    if (bits < 1 || bits > 2) {
        return false;
    }
    m_stopBits = bits;
    // Don't apply the change yet if we are not in UART mode
    if (m_portMode != PortModes::UART) {
        return true;
    }
    bool sercomEnabled = m_serPort->USART.CTRLA.bit.ENABLE;
    PortDisable();
    m_serPort->USART.CTRLB.bit.SBMODE = bits - 1;
    if (sercomEnabled) {
        PortEnable();
    }
    return true;
}