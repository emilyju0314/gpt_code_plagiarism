void SysManager::Initialize() {
    // Clear and enable the cycle counter
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CYCCNT = 0;
    DWT->CTRL = DWT_CTRL_CYCCNTENA_Msk;

    InitClocks();

    // Enable brownout detection on the 3.3V rail. The default fuse value is 1.7
    // Set brownout detection to ~2.5V. Default from factory is 1.7V,
    // It appears that NVM can work to as low as 1.7V
    SUPC->BOD33.bit.ENABLE = 0;
    SUPC->BOD33.bit.LEVEL = 167;  // Brown out voltage = 1.5V + LEVEL * 6mV.
    // Reset
    // If desired, an interrupt can be triggered instead of reset. Useful if
    // sensitive actions need to be completed at the last moment.
    SUPC->BOD33.bit.ACTION = SUPC_BOD33_ACTION_RESET_Val;//SUPC_BOD33_ACTION_NONE_Val;
    // Hysteresis voltage (4 bits). HYST*6mV
    SUPC->BOD33.bit.HYST = 0x7;
    SUPC->BOD33.bit.ENABLE = 1; // enable brown-out detection

    // Reset and initialize the HBridge
    StatusMgr.HBridgeState(true);
    Delay_ms(1);
    StatusMgr.HBridgeState(false);

    // Set the output direction for the OutFault_04or05
    DATA_DIRECTION_INPUT(OutFault_04or05.gpioPort,
                         1UL << OutFault_04or05.gpioPin);

    PIN_CONFIGURATION(OutFault_04or05.gpioPort, OutFault_04or05.gpioPin,
                      PORT_PINCFG_INEN);

    InputMgr.Initialize();

    for (int32_t i = 0; i < CLEARCORE_PIN_MAX; i++) {
        Connectors[i]->Initialize(static_cast<ClearCorePins>(i));
    }

    DmaMgr.Initialize();
    MotorMgr.Initialize();
    ShiftReg.Initialize();
    AdcMgr.Initialize();
    CcioMgr.Initialize();
    UsbMgr.Initialize();
    EncoderIn.Initialize();

    // Configure external interrupt controller
    SET_CLOCK_SOURCE(EIC_GCLK_ID, 0);

    ShiftReg.LedPattern(ShiftRegister::SR_UNDERGLOW_MASK,
                        ShiftRegister::LED_BLINK_BREATHING, true);

    // Enable clock EIC for I/O interrupts
    CLOCK_ENABLE(APBAMASK, EIC_);

    // Enable External Interrupt Controllers 0-15
    // EIC_0_IRQn = 12, ..., EIC_15_IRQn = 27
    for (IRQn_Type irq = EIC_0_IRQn; irq <= EIC_15_IRQn;
            irq = static_cast<IRQn_Type>(static_cast<uint8_t>(irq) + 1)) {
        NVIC_EnableIRQ(irq);
        NVIC_SetPriority(irq, EIC_INTERRUPT_PRIORITY);
    }

    NVIC_EnableIRQ(TCC0_0_IRQn); // Enable sample rate interrupt
    NVIC_SetPriority(TCC0_0_IRQn, MAIN_INTERRUPT_PRIORITY); // Set priority

    NVIC_EnableIRQ(GMAC_IRQn);
    NVIC_SetPriority(GMAC_IRQn, MAIN_INTERRUPT_PRIORITY);

    NVIC_EnableIRQ(TCC4_0_IRQn); // Enable IO4 tone interrupt
    NVIC_EnableIRQ(TCC3_0_IRQn); // Enable IO5 tone interrupt
    NVIC_SetPriority(TCC4_0_IRQn, TONE_INTERRUPT_PRIORITY); // Set priority
    NVIC_SetPriority(TCC3_0_IRQn, TONE_INTERRUPT_PRIORITY); // Set priority

    // Set SysTick to 1ms interval
    if (TimingMgr.SysTickPeriodMicroSec(1000)) {
        // Capture error
        while (1) {
            continue;
        }
    }
    // Set priority for SysTick interrupt (2nd lowest).
    NVIC_SetPriority(SysTick_IRQn, SYSTICK_INTERRUPT_PRIORITY);

    // Run power-on tests and detect faults if any.
    StatusMgr.Initialize(ShiftRegister::SR_UNDERGLOW_MASK);

    // Ethernet PHY requires 300us + 10ms minimum for a cold startup.
    while (Microseconds() < 10300) {
        continue;
    }

    EthernetMgr.Initialize();

    m_readyForOperations = true;
}