bool SerialBase::SpiTransferDataAsync(
    uint8_t const *writeBuf, uint8_t *readBuf, int32_t len) {
    if (!m_portOpen || m_portMode != SPI) {
        return false;
    }
    // Setup the DMA descriptors to perform asynchronous transfers
    if (m_dmaRxChannel == DMA_INVALID_CHANNEL ||
            m_dmaTxChannel == DMA_INVALID_CHANNEL) {
        return false;
    }
    DmacDescriptor *baseDesc;

    // Set up the Rx dest descriptor
    baseDesc = DmaManager::BaseDescriptor(m_dmaRxChannel);
    if (readBuf) {
        baseDesc->DSTADDR.reg = (uint32_t)(readBuf + len);
        baseDesc->BTCTRL.reg =
            DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_DSTINC | DMAC_BTCTRL_VALID;
    }
    else {
        baseDesc->DSTADDR.reg = (uint32_t)&spiDummy;
        baseDesc->BTCTRL.reg = DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_VALID;
    }
    baseDesc->BTCNT.reg = len;
    DmaManager::Channel(m_dmaRxChannel)->CHCTRLA.reg |= DMAC_CHCTRLA_ENABLE;

    // Set up the Tx source descriptor
    baseDesc = DmaManager::BaseDescriptor(m_dmaTxChannel);
    if (writeBuf) {
        baseDesc->SRCADDR.reg = (uint32_t)(writeBuf + len);
        baseDesc->BTCTRL.reg =
            DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_SRCINC | DMAC_BTCTRL_VALID;
    }
    else {
        baseDesc->SRCADDR.reg = (uint32_t)&spiDummy;
        baseDesc->BTCTRL.reg = DMAC_BTCTRL_BEATSIZE_BYTE | DMAC_BTCTRL_VALID;
    }
    baseDesc->BTCNT.reg = len;
    DmaManager::Channel(m_dmaTxChannel)->CHCTRLA.reg |= DMAC_CHCTRLA_ENABLE;

    return true;
}