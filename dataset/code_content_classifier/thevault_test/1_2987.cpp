MotorDriver::MotorDriver(ShiftRegister::Masks enableMask,
                         const PeripheralRoute *aInfo,
                         const PeripheralRoute *bInfo,
                         const PeripheralRoute *hlfbInfo,
                         uint16_t hlfbTc,
                         uint16_t hlfbEvt)
    : DigitalIn(ShiftRegister::Masks::SR_NO_FEEDBACK_MASK, hlfbInfo),
      m_enableMask(enableMask),
      m_aInfo(aInfo),
      m_bInfo(bInfo),
      m_hlfbInfo(hlfbInfo),
      m_aDataMask(1UL << aInfo->gpioPin),
      m_bDataMask(1UL << bInfo->gpioPin),
      m_enableConnector(CLEARCORE_PIN_INVALID),
      m_inputAConnector(CLEARCORE_PIN_INVALID),
      m_inputBConnector(CLEARCORE_PIN_INVALID),
      m_hlfbTcNum(hlfbTc),
      m_hlfbEvt(hlfbEvt),
      m_hlfbMode(HLFB_MODE_STATIC),
      m_hlfbWidth{0, 0},
      m_hlfbPeriod{0, 0},
      m_hlfbNoPwmSampleCount(2),
      m_hlfbCarrierFrequency(HLFB_CARRIER_45_HZ),
      m_hlfbCarrierLossStateChange_ms(HLFB_CARRIER_LOSS_STATE_CHANGE_MS_45_HZ),
      m_hlfbLastCarrierDetectTime(UINT32_MAX),
      m_hlfbDuty(HLFB_DUTY_UNKNOWN),
      m_hlfbState(HLFB_UNKNOWN),
      m_lastHlfbInputValue(false),
      m_hlfbPwmReadingPending(false),
      m_hlfbStateChangeCounter(MS_TO_SAMPLES * HLFB_CARRIER_LOSS_STATE_CHANGE_MS_45_HZ),
      m_polarityInversions(0),
      m_enableRequestedState(false),
      m_enableTriggerActive(false),
      m_enableTriggerPulseStartMs(0),
      m_enableTriggerPulseCount(0),
      m_enableTriggerPulseLenMs(25),
      m_aDutyCnt(0),
      m_bDutyCnt(0),
      m_inFault(false),
      m_statusRegMotor(0),
      m_statusRegMotorRisen(0),
      m_statusRegMotorFallen(0),
      m_statusRegMotorLast(0),
      m_alertRegMotor(0),
      m_initialized(false),
      m_isEnabling(false),
      m_isEnabled(false),
      m_hlfbCarrierLost(false),
      m_enableCounter(0),
      m_brakeOutputPin(CLEARCORE_PIN_INVALID),
      m_limitSwitchNeg(CLEARCORE_PIN_INVALID),
      m_limitSwitchPos(CLEARCORE_PIN_INVALID),
      m_eStopConnector(CLEARCORE_PIN_INVALID),
      m_motionCancellingEStop(false),
      m_shiftRegEnableReq(false),
      m_clearFaultState(CLEAR_FAULT_IDLE),
      m_clearFaultHlfbTimer(0) {

    m_interruptAvail = true;

    Tcc *theTcc = (tcc_modules[m_aInfo->tccNum]);
    uint8_t ccIndex = m_aInfo->tccPadNum % TccCcNum(m_aInfo->tccNum);
    m_aTccBuffer = &theTcc->CCBUF[ccIndex].reg;
    m_aTccSyncMask = TCC_SYNCBUSY_CC(1UL << ccIndex);
    m_aTccSyncReg = &theTcc->SYNCBUSY.reg;

    theTcc = (tcc_modules[m_bInfo->tccNum]);
    ccIndex = m_bInfo->tccPadNum % TccCcNum(m_bInfo->tccNum);
    m_bTccBuffer = &theTcc->CCBUF[ccIndex].reg;
    m_bTccSyncMask = TCC_SYNCBUSY_CC(1UL << ccIndex);
    m_bTccSyncReg = &theTcc->SYNCBUSY.reg;
}