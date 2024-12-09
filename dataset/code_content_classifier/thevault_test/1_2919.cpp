void AdcManager::Update() {
    if (!m_initialized) {
        return;
    }

    // If the previous conversion isn't complete or there are more conversions
    // still to be performed, increment the timeout counter
    if (ADC1->STATUS.bit.ADCBUSY ||
            DmaManager::Channel(DMA_ADC_RESULTS)->CHCTRLA.bit.ENABLE) {
        // If the counter is greater than the timeout, throw an error
        if (++m_AdcBusyCount >= m_AdcTimeoutLimit) {
            m_AdcTimeout = true;
        }
    }
    else {
        // Clear the error and reset the counter
        m_AdcBusyCount = 0;
        m_AdcTimeout = false;

        // Copy the finished results into m_AdcResultsConverted and convert to
        // Q15
        for (uint8_t i = 0; i < ADC_CHANNEL_COUNT; i++) {
            // If HBridgeReset is set, do not update the VSupply value
            if (i == ADC_VSUPPLY_MON && StatusMgr.StatusRT().bit.HBridgeReset) {
                continue;
            }
            // Normalize the ADC results to a Q15 value
            m_AdcResultsConverted[i] =
                AdcResultsRaw[i] << (15 - m_AdcResolution);
        }

        // Kick off next conversion sequence
        if (m_AdcResolution != m_AdcResPending) {
            AdcResChange();
        }
        m_shiftRegSnapshot = m_shiftRegPending;
        m_shiftRegPending = ShiftReg.LastOutput();
        DmaUpdate();
    }

    // Apply IIR filtering even if the ADC values have not been updated
    for (uint8_t i = 0; i < ADC_CHANNEL_COUNT; i++) {
        m_analogFilter[i].Update(m_AdcResultsConverted[i]);
        m_AdcResultsConvertedFiltered[i] = m_analogFilter[i].LastOutput();
    }
}