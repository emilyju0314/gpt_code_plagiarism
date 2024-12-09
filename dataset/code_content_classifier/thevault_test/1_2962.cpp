void SerialBase::PortClose() {
    if (m_portOpen) {
        // Flush the transmit buffer before closing
        WaitForTransmitIdle();

        DATA_DIRECTION_INPUT(m_rtsSsInfo->gpioPort, 1L << m_rtsSsInfo->gpioPin);
        PortDisable();
        m_portOpen = false;
    }
}