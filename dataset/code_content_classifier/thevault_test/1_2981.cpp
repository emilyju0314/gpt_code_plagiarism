void SerialBase::IrqHandlerTx() {
    switch (m_portMode) {
        case SPI:
            break;
        case UART:
        default:
            TxPump();
            break;
    }
}