void ShiftRegister::Initialize() {
    SET_CLOCK_SOURCE(SERCOM6_GCLK_ID_CORE, 5);
    CLOCK_ENABLE(APBDMASK, SERCOM6_);

    // Set up pins for SERCOM6 in SPI master mode and enable it to control them
    PMUX_SELECTION(SR_CLK.gpioPort, SR_CLK.gpioPin, PER_SERCOM);
    PMUX_ENABLE(SR_CLK.gpioPort, SR_CLK.gpioPin);

    PMUX_SELECTION(SR_DATA.gpioPort, SR_DATA.gpioPin, PER_SERCOM);
    PMUX_ENABLE(SR_DATA.gpioPort, SR_DATA.gpioPin);

    PMUX_SELECTION(SR_DATA_RET.gpioPort, SR_DATA_RET.gpioPin, PER_SERCOM);
    PMUX_ENABLE(SR_DATA_RET.gpioPort, SR_DATA_RET.gpioPin);

    // Set up Load/Enable pins as outputs
    DATA_OUTPUT_STATE(SR_ENn.gpioPort, 1UL << SR_ENn.gpioPin, true);
    DATA_OUTPUT_STATE(SR_LOAD.gpioPort, 1UL << SR_LOAD.gpioPin, false);
    DATA_DIRECTION_OUTPUT(SR_ENn.gpioPort, (1UL << SR_ENn.gpioPin));
    DATA_DIRECTION_OUTPUT(SR_LOAD.gpioPort, (1UL << SR_LOAD.gpioPin));

    // A pointer to the SPI register to make things easier.
    SercomSpi *sercomSpi = &SERCOM6->SPI;

    // Disable SERCOM6 to switch its role
    sercomSpi->CTRLA.bit.ENABLE = 0;
    SYNCBUSY_WAIT(sercomSpi, SERCOM_SPI_SYNCBUSY_ENABLE);

    // Sets SERCOM6 to SPI Master mode
    sercomSpi->CTRLA.reg |= SERCOM_SPI_CTRLA_MODE(0x3);
    // Sets PAD[3] to DO, PAD[2] to DI, and sets LSB-first transmission
    sercomSpi->CTRLA.reg |= SERCOM_SPI_CTRLA_DOPO(0x2) |
                            SERCOM_SPI_CTRLA_DIPO(0x2) |
                            SERCOM_SPI_CTRLA_DORD;

    // Enables the data receiver
    sercomSpi->CTRLB.bit.RXEN = 1;

    // Enables 32-bit DATA register transactions
    sercomSpi->CTRLC.reg |= SERCOM_SPI_CTRLC_DATA32B;

    // Sets the baud rate to GCLK1 frequency
    sercomSpi->BAUD.reg = 0;

    // Enables SERCOM6 and wait for core sync
    sercomSpi->CTRLA.bit.ENABLE = 1;
    SYNCBUSY_WAIT(sercomSpi, SERCOM_SPI_SYNCBUSY_ENABLE);

    // Send the initial values to the chain
    sercomSpi->DATA.reg = atomic_load_n(&m_patternOutputs[LED_BLINK_IO_SET])
                          ^ m_shiftInversions.reg;

    // Generate strobe and update
    Send();

    // Enable the chain, clear and set SR_EN_N
    DATA_OUTPUT_STATE(SR_ENn.gpioPort, 1UL << SR_ENn.gpioPin, false);

    // Allow timer tick to update
    m_initialized = true;
}