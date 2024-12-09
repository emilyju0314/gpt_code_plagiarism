void SerialBase::IrqHandlerException() {
    switch (m_portMode) {
        case SPI:
            // This should not occur, but clear the interrupt flags to be safe.
            m_serPort->USART.INTFLAG.reg = SERCOM_USART_INTFLAG_ERROR;
            break;
        case UART:
        default:
            if (m_serPort->USART.INTFLAG.bit.ERROR) {
                // Clear the interrupt flag
                m_serPort->USART.INTFLAG.reg = SERCOM_USART_INTFLAG_ERROR;
                HandleFrameError();
                HandleParityError();
                HandleOverflow();
            }
            break;
    }
}