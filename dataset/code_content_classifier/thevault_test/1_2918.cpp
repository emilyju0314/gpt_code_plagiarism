void AdcManager::Initialize() {
    m_initialized = false;
    m_AdcTimeout = false;
    m_shiftRegSnapshot = UINT32_MAX;
    m_shiftRegPending = UINT32_MAX;
    m_AdcResolution = ADC_RESOLUTION_DEFAULT;
    m_AdcResPending = ADC_RESOLUTION_DEFAULT;
    m_AdcTimeoutLimit = ADC_TIMEOUT_DEFAULT;
    m_AdcBusyCount = 0;

    // Set default filter constants
    for (uint8_t i = 0; i < ADC_CHANNEL_COUNT; i++) {
        m_analogFilter[i].Tc_ms(ADC_IIR_FILTER_TC_MS);
    }

    // Configure internal analog inputs: Sdrvr2, Sdrvr3, VBus, 5V Ob monitor
    const uint8_t INTERNAL_ADC_INPUTS = 4;
    const PeripheralRoute *adcsToSetup[INTERNAL_ADC_INPUTS] = {
        &_5VOB_MON, &Vsupply_MON_IO_4and5_RST,
        &Sdrvr2_iMon, &Sdrvr3_iMon
    };

    for (uint8_t i = 0; i < INTERNAL_ADC_INPUTS; i++) {
        const PeripheralRoute *prPtr = adcsToSetup[i];

        ClearCorePorts adcGpioPort = prPtr->gpioPort;
        uint8_t adcGpioPin = prPtr->gpioPin;

        PMUX_SELECTION(adcGpioPort, adcGpioPin, PER_ANALOG);
        PMUX_ENABLE(adcGpioPort, adcGpioPin);
    }

    // Set up ADC

    // Set the clock source for ADC1 to GCLK4 (48 MHz) and enable
    // the peripheral channel
    SET_CLOCK_SOURCE(ADC1_GCLK_ID, 4);

    // Enables the peripheral clock to ADC1
    CLOCK_ENABLE(APBDMASK, ADC1_);

    // Reset the ADC1 module
    ADC1->CTRLA.bit.SWRST = 1;
    SYNCBUSY_WAIT(ADC1, ADC_SYNCBUSY_SWRST);

    // Configure the ADC read resolution
    AdcResChange();

    // Set clock pre-scaler to 4 to result in a clock signal of 48/4 = 12 MHz
    // Note: ADC can pre-scale the clock a minimum of 2.
    ADC1->CTRLA.bit.PRESCALER = ADC_CTRLA_PRESCALER_DIV4_Val;

    // Set input to channel AIN4 and pause the DMA input sequencing
    ADC1->INPUTCTRL.reg |= ADC_INPUTCTRL_MUXPOS_AIN4 | ADC_INPUTCTRL_DSEQSTOP;
    SYNCBUSY_WAIT(ADC1, ADC_SYNCBUSY_INPUTCTRL);

    // Setup the DMA input/result transfers
    DmaInit();

    // Update INPUTCTRL from the DMA engine
    ADC1->DSEQCTRL.bit.INPUTCTRL = 1;
    SYNCBUSY_WAIT(ADC1, ADC_SYNCBUSY_INPUTCTRL);
    ADC1->DSEQCTRL.bit.AUTOSTART = 1;

    // Enable reference buffer compensation and set the reference to VDDANA
    ADC1->REFCTRL.reg |= ADC_REFCTRL_REFCOMP | ADC_REFCTRL_REFSEL_INTVCC1;
    SYNCBUSY_WAIT(ADC1, ADC_SYNCBUSY_REFCTRL);

    // Enable sampling period offset compensation
    // Note: setting sample length fairly long since the ADC readings will be
    // performed in the background, which results in more reliable readings.
    // Setting the sample length to 31 uses approximately 20% of the available
    // time when doing 8 12-bit readings per 5 kHz interrupt slot.
    ADC1->SAMPCTRL.reg = ADC_SAMPCTRL_SAMPLEN(31);
    SYNCBUSY_WAIT(ADC1, ADC_SYNCBUSY_SAMPCTRL);

    ADC1->DBGCTRL.bit.DBGRUN = 1;

    // Kick off the first ADC conversion
    DmaUpdate();

    // Enable ADC
    ADC1->CTRLA.bit.ENABLE = 0x01;
    SYNCBUSY_WAIT(ADC1, ADC_SYNCBUSY_ENABLE);

    // Wait for the first conversion to complete
    while (DmaManager::Channel(DMA_ADC_RESULTS)->CHCTRLA.bit.ENABLE) {
        continue;
    }
    while (DmaManager::Channel(DMA_ADC_SEQUENCE)->CHCTRLA.bit.ENABLE) {
        continue;
    }

    WaitAdc();

    // Populate initial values
    for (uint32_t i = 0; i < ADC_CHANNEL_COUNT; i++) {
        uint16_t val = ADC_INITIAL_FILTER_VALUE_V[i] * (1 << 15) /
                       ADC_CHANNEL_MAX_FLOAT[i];
        m_AdcResultsConverted[i] = val;
        m_AdcResultsConvertedFiltered[i] = val;
        m_analogFilter[i].Reset(val);
    }

    m_initialized = true;
}