void AdcManager::DmaInit() {
    // DMAC channel 0 is used to retrieve results from the ADC.
    // Channel 0 is triggered by the ADC result ready flag.
    // When triggered, the DMAC CH 0 should move the ADC result
    // to the program-created AdcResultsRaw array. The DMAC needs to
    // move 16-bits(one HWORD) of data(max output from the ADC).

    /***************************************************************
     * DMA_ADC_RESULTS Channel
     * Read each ADC result and store it into the AdcResult array.
     ***************************************************************/
    DmacChannel *channel;
    DmacDescriptor *baseDesc;
    channel = DmaManager::Channel(DMA_ADC_RESULTS);
    baseDesc = DmaManager::BaseDescriptor(DMA_ADC_RESULTS);
    // Configure DMA channel 0 to stream results from the ADC
    // Disable the channel so it can be written to
    channel->CHCTRLA.reg &= ~DMAC_CHCTRLA_ENABLE;

    channel->CHCTRLA.reg = DMAC_CHCTRLA_SWRST;
    // Wait for the reset to finish
    while (channel->CHCTRLA.reg == DMAC_CHCTRLA_SWRST) {
        continue;
    }

    channel->CHCTRLA.reg = DMAC_CHCTRLA_TRIGSRC(ADC1_DMAC_ID_RESRDY) |
                           DMAC_CHCTRLA_TRIGACT_BURST |
                           DMAC_CHCTRLA_BURSTLEN_SINGLE;

#ifdef DEBUG_ADC_RESULT_TIMING
    // Enable channel completion interrupts
    channel->CHINTENSET.reg = DMAC_CHINTENSET_TCMPL;
    NVIC_EnableIRQ(static_cast<IRQn_Type>(DMAC_0_IRQn + DMA_ADC_RESULTS));
#endif

    // Descriptors can work like linked lists. Since this is the only
    // transfer descriptor for the channel, point to 0 to stop transactions
    baseDesc->DESCADDR.reg = static_cast<uint32_t>(0);
    baseDesc->SRCADDR.reg = (uint32_t)&ADC1->RESULT.reg;
    baseDesc->BTCNT.reg = ADC_CHANNEL_COUNT;

    // End address
    baseDesc->DSTADDR.reg = (uint32_t)(AdcResultsRaw + ADC_CHANNEL_COUNT);
    baseDesc->BTCTRL.reg =
        DMAC_BTCTRL_BEATSIZE_HWORD | DMAC_BTCTRL_DSTINC | DMAC_BTCTRL_VALID;

    /***************************************************************
     * DMA_ADC_SEQUENCE Channel
     * This tells the ADC what channel to read
     ***************************************************************/
    channel = DmaManager::Channel(DMA_ADC_SEQUENCE);
    // Disable and reset the channel so it is clean to setup
    channel->CHCTRLA.reg &= ~DMAC_CHCTRLA_ENABLE;
    channel->CHCTRLA.reg = DMAC_CHCTRLA_SWRST;
    // Wait for the reset to finish
    while (channel->CHCTRLA.reg == DMAC_CHCTRLA_SWRST) {
        continue;
    }

    // Configure the channel to be triggered from the ADC1 DMAC sequence start
    // Trigger will cause a single burst(one transfer)
    channel->CHCTRLA.reg = DMAC_CHCTRLA_TRIGSRC(ADC1_DMAC_ID_SEQ) |
                           DMAC_CHCTRLA_TRIGACT_BURST |
                           DMAC_CHCTRLA_BURSTLEN_SINGLE;

    baseDesc = DmaManager::BaseDescriptor(DMA_ADC_SEQUENCE);
    // Descriptors can work like linked lists. Since this is the only
    // transfer descriptor for the channel, point to 0 to stop transactions
    baseDesc->DESCADDR.reg = static_cast<uint32_t>(0);
    // Point the src to the end of the adcSequence. The transfer will copy the
    // data before the src addr.
    baseDesc->SRCADDR.reg =
        (reinterpret_cast<uint32_t>(&adcSequence)) + sizeof(adcSequence);
    baseDesc->BTCNT.reg = ADC_CHANNEL_COUNT;
    // The Destination is the ADC register for sequence data.
    // The sequence data is what will be moved into the ADC.
    baseDesc->DSTADDR.reg =
        reinterpret_cast<uint32_t>(&REG_ADC1_DSEQDATA); // end address
    baseDesc->BTCTRL.reg = DMAC_BTCTRL_BEATSIZE_WORD | DMAC_BTCTRL_STEPSEL_SRC |
                           DMAC_BTCTRL_VALID | DMAC_BTCTRL_SRCINC;
}