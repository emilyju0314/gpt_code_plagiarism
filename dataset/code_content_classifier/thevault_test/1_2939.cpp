DigitalIn::DigitalIn(
    ShiftRegister::Masks ledMask,
    const PeripheralRoute *inputInfo)
    : Connector(),
      m_ledMask(ledMask),
      m_inputPort(inputInfo->gpioPort),
      m_inputDataBit(inputInfo->gpioPin),
      m_inputDataMask(1UL << inputInfo->gpioPin),
      m_extInt(inputInfo->extInt),
      m_interruptAvail(inputInfo->extIntAvail),
      m_changeRegPtr(nullptr),
      m_inRegPtr(nullptr),
      m_inputRegRTPtr(nullptr),
      m_stateFiltered(false),
      m_filterLength(3),
      m_filterTicksLeft(1) {}