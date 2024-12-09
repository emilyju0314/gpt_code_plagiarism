void EthernetManager::Enable(bool enable) {
    bool enabled = (GMAC->NCR.bit.TXEN && GMAC->NCR.bit.RXEN);

    if (enable == enabled) {
        // Nothing to do.
        return;
    }

    GMAC->NCR.bit.TXEN = enable ? 1 : 0;
    GMAC->NCR.bit.RXEN = enable ? 1 : 0;

    if (!enable) {
        // Writing TXEN to 0 on the GMAC resets the GMAC's transmit queue
        // pointer to the address of m_txBuffer[0].
        // Reset the TX descriptors to init state
        for (uint8_t i = 0; i < TX_BUFF_CNT; i++) {
            m_txDesc[i].bit.OWN = 1;
            m_txDesc[i].bit.LB = 1;
        }
        m_txBuffIndex = 0;
    }
}