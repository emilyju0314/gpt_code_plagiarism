void SerialBase::IrqHandlerRx() {
    switch (m_portMode) {
        case SPI:
            break;
        case UART:
        default:
            RxProc();
            break;
    }
}