void SerialBase::DataOrder(DataOrders newOrder) {
    bool sercomEnabled = m_serPort->USART.CTRLA.bit.ENABLE;
    PortDisable();
    // SPI/USART use the same bit.
    m_serPort->USART.CTRLA.bit.DORD = newOrder;
    if (sercomEnabled) {
        PortEnable();
    }
}