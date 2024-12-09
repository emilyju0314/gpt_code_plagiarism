void AdcManager::DmaUpdate() {
    // Start channel
    DmaManager::Channel(DMA_ADC_RESULTS)->CHCTRLA.reg |= DMAC_CHCTRLA_ENABLE;
    DmaManager::Channel(DMA_ADC_SEQUENCE)->CHCTRLA.reg |= DMAC_CHCTRLA_ENABLE;

    // Restart the DMA sequence to the ADC
    ADC1->INPUTCTRL.reg &= ~ADC_INPUTCTRL_DSEQSTOP;
}