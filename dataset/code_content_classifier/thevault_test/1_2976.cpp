void SerialBase::WaitForTransmitIdle() {
    if (m_portMode == UART) {
        // Wait until the out buffer has emptied
        while (m_outHead != m_outTail) {
            continue;
        }

        if (m_serPort->USART.INTFLAG.bit.DRE) {
            // Data register is already empty, no need to wait anymore
            return;
        }

        // Wait for transmission to complete
        while (!m_serPort->USART.INTFLAG.bit.TXC) {
            continue;
        }
    }
    else if (m_portMode == SPI) {
        SpiAsyncWaitComplete();
    }
}