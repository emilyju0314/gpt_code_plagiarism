ShiftRegister::ShiftRegister() :
    m_fastCounter(FAST_COUNTER_PERIOD, FAST_COUNTER_CC),
    m_breathingCounter(),
    m_fadeCounter(),
    m_patternMasks{UINT32_MAX},
    m_patternOutputs{SR_UNDERGLOW_MASK},
    m_altOutput(0),
    m_initialized(false),
    m_blinkCodeActive(false),
    m_blinkCodeState(false),
    m_useAltOutput(false),
    m_pendingOutput(0),
    m_lastOutput(0) {
    m_shiftInversions.reg = 0xffffffff;
    m_shiftInversions.bit.LED_USB = 0;
    m_shiftInversions.bit.LED_IO_4 = 0;
    m_shiftInversions.bit.LED_IO_5 = 0;
    m_shiftInversions.bit.LED_COM_0 = 0;
    m_shiftInversions.bit.LED_COM_1 = 0;
    m_shiftInversions.bit.UNDERGLOW = 0;
    m_shiftInversions.bit.EN_OUT_0 = 0;
    m_shiftInversions.bit.EN_OUT_1 = 0;
    m_shiftInversions.bit.EN_OUT_2 = 0;
    m_shiftInversions.bit.EN_OUT_3 = 0;
    m_shiftInversions.bit.UART_TTL_0 = 0;
    m_shiftInversions.bit.UART_TTL_1 = 0;
}