void EthernetManager::IrqHandlerGmac() {
    // Transmit status reg
    volatile uint32_t tsr;
    // Receive status reg
    volatile uint32_t rsr;

    tsr = GMAC->TSR.reg;    // Transmit status register
    rsr = GMAC->RSR.reg;    // Receive  status register
    // Need to clear the ISR (clear on read)
    GMAC->ISR.reg;

    // Frame transmitted
    if (tsr & GMAC_TSR_TXCOMP) {
        // Clear the TSR reg
        GMAC->TSR.reg = tsr;
    }

    // Frame received, add a packet to packet buffer.
    if (rsr & GMAC_RSR_REC) {
        m_recv = true;
    }
    // Clear the RSR reg
    GMAC->RSR.reg = rsr;
}