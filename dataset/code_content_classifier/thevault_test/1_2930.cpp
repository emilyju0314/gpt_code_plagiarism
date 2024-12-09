DigitalInOut::DigitalInOut(ShiftRegister::Masks ledMask,
                           const PeripheralRoute *inputInfo,
                           const PeripheralRoute *outputInfo,
                           bool logicInversion)
    : DigitalIn(ledMask, inputInfo),
      m_outputPort(outputInfo->gpioPort),
      m_outputDataBit(outputInfo->gpioPin),
      m_outputDataMask(1UL << outputInfo->gpioPin),
      m_logicInversion(logicInversion),
      m_isInFault(false),
      m_tcPadNum(outputInfo->tcPadNum),
      m_outState(false),
      m_pulseOnTicks(0),
      m_pulseOffTicks(0),
      m_pulseStart(0),
      m_pulseStopCount(0),
      m_pulseCounter(0),
      m_overloadTripCnt(OVERLOAD_TRIP_TICKS),
      m_pulseActive(false),
      m_pulseValue(false),
      m_pulseStopPending(false),
      m_overloadFoldbackCnt(0) {
    static Tc *const tc_modules[TC_INST_NUM] = TC_INSTS;
    m_tc = tc_modules[outputInfo->tcNum];
}