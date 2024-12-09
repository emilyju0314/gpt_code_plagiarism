void SerialBase::PortEnable(bool initializing) {
    // Enable port and wait for the sync.
    m_serPort->USART.CTRLA.bit.ENABLE = 1;
    SercomUsart *usart = &m_serPort->USART;
    SYNCBUSY_WAIT(usart, SERCOM_USART_SYNCBUSY_ENABLE);

    if (!initializing) {
        PMUX_ENABLE(m_txMosiInfo->gpioPort, m_txMosiInfo->gpioPin);
    }
}