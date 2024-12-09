bool SerialBase::CharSize(uint8_t size) {
    // Note: Supports 5,6,7,8,9 bits.
    if (size < 5 || size > 9) {
        return false;
    }
    else if (m_portMode == SPI && (size < 8 || size > 9)) {
        // Note: SPI only supports 8 or 9 bit characters
        return false;
    }
    m_charSize = size;
    bool sercomEnabled = m_serPort->USART.CTRLA.bit.ENABLE;
    PortDisable();


    switch (m_portMode) {
        case SPI:
            // Register size clips 8 and 9 to 0 and 1 to match register
            // definition.
            m_serPort->SPI.CTRLB.bit.CHSIZE = size &
                                              SERCOM_SPI_CTRLB_CHSIZE_Msk;
            break;
        case UART:
        default:
            // Register size clips 8 and 9 to 0 and 1 to match register
            // definition.
            m_serPort->USART.CTRLB.bit.CHSIZE = size &
                                                SERCOM_USART_CTRLB_CHSIZE_Msk;
            break;
    }
    if (sercomEnabled) {
        PortEnable();
    }
    return true;
}