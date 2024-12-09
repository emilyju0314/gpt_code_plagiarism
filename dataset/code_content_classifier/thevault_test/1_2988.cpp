MotorManager::MotorManager()
    : m_gclkIndex(MAIN_INTERRUPT_GCLK_ID),
      m_clockRate(CLOCK_RATE_NORMAL),
      m_initialized(false) {
    m_stepPorts[MOTOR_M0M1] =  Mtr_CLK_01.gpioPort;
    m_stepPorts[MOTOR_M2M3] = Mtr_CLK_23.gpioPort;
    m_stepDataBits[MOTOR_M0M1] = Mtr_CLK_01.gpioPin;
    m_stepDataBits[MOTOR_M2M3] = Mtr_CLK_23.gpioPin;
    m_motorModes[MOTOR_M0M1] = Connector::CPM_MODE_A_DIRECT_B_DIRECT;
    m_motorModes[MOTOR_M2M3] = Connector::CPM_MODE_A_DIRECT_B_DIRECT;
}