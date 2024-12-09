bool MotorManager::MotorInputClocking(MotorClockRates newRate) {
    if (m_clockRate == newRate && m_initialized) {
        // Same rate as before, nothing to change
        return false;
    }

    uint32_t clkReq;
    bool modeValid = true;

    switch (newRate) {
        case CLOCK_RATE_LOW:
            clkReq = CPM_CLOCK_RATE_LOW_HZ;
            break;
        case CLOCK_RATE_NORMAL:
            clkReq = CPM_CLOCK_RATE_NORMAL_HZ;
            break;
        case CLOCK_RATE_HIGH:
            clkReq = CPM_CLOCK_RATE_HIGH_HZ;
            break;
        default:
            modeValid = false;
            break;
    }

    if (!modeValid) {
        return false;
    }

    // Mode change successful; update the step rate.
    m_clockRate = newRate;

    // Configure TCC0 for the step step carrier signal
    TCC0->CTRLA.bit.ENABLE = 0; // Disable TCC0
    TCC1->CTRLA.bit.ENABLE = 0; // Disable TCC1

    SYNCBUSY_WAIT(TCC0, TCC_SYNCBUSY_ENABLE);
    SYNCBUSY_WAIT(TCC1, TCC_SYNCBUSY_ENABLE);

    GClkFreqUpdate(m_gclkIndex, clkReq);
    int32_t newPeriod = clkReq / _CLEARCORE_SAMPLE_RATE_HZ;

    TCC0->COUNT.reg = 0;
    TCC1->COUNT.reg = 0;

    // Clear out any pending command
    for (int8_t iChannel = 0; iChannel < TCC0_CC_NUM; iChannel++) {
        TCC0->CC[iChannel].reg = 0;
        TCC0->CCBUF[iChannel].reg = 0;
    }

    for (int8_t iChannel = 0; iChannel < TCC1_CC_NUM; iChannel++) {
        TCC1->CC[iChannel].reg = 0;
        TCC1->CCBUF[iChannel].reg = 0;
    }

    TCC0->PER.reg = newPeriod - 1;
    TCC1->PER.reg = newPeriod - 1;

    // Notify the StepGenerators of the new maximum rate
    for (uint8_t iMotor = 0; iMotor < MOTOR_CON_CNT; iMotor++) {
        MotorConnectors[iMotor]->StepsPerSampleMaxSet(newPeriod);
    }

    TCC0->CTRLA.bit.ENABLE = 1; // Enable TCC0
    TCC1->CTRLA.bit.ENABLE = 1; // Enable TCC1

    SYNCBUSY_WAIT(TCC0, TCC_SYNCBUSY_ENABLE);
    SYNCBUSY_WAIT(TCC1, TCC_SYNCBUSY_ENABLE);

    return true;
}