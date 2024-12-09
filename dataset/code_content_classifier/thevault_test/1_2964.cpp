bool SerialBase::Speed(uint32_t bitsPerSecond) {
    bool success = true;
    m_baudRate = bitsPerSecond;
    bool sercomEnabled = m_serPort->USART.CTRLA.bit.ENABLE;
    PortDisable();

    uint32_t baudVal;

    switch (m_portMode) {
        case SPI:
            // Calculate the maximum baud rate that is <= the target rate
            baudVal = ((__SERCOM_SPI_CLOCK / 2 + (bitsPerSecond - 1)) /
                       bitsPerSecond) - 1;
            // Limit the value to UINT8_MAX, even if it gives a rate faster
            // than our target
            if (baudVal > UINT8_MAX) {
                baudVal = UINT8_MAX;
                // If baudVal is greater than 255, a lower input clock rate is
                // needed to achieve the requested baud rate
                // We'll clip to the highest rate possible and let the user
                // know that their setting didn't take
                success = false;
            }
            m_serPort->SPI.BAUD.bit.BAUD = static_cast<uint8_t>(baudVal);
            break;

        case UART:
        default:
            float baudFloat =
                65536 * (1 - (16.0 * bitsPerSecond / __SERCOM_USART_CLOCK));
            m_serPort->USART.BAUD.bit.BAUD = (uint16_t)(baudFloat + 0.5);
            break;
    }

    if (sercomEnabled) {
        PortEnable();
    }
    return success;
}