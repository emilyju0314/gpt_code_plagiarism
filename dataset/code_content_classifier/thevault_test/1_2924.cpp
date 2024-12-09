void ShiftRegister::DiagnosticLedSweep() {
    m_altOutput = 0;
    m_useAltOutput = true;
    // Illuminate bank 2
    for (uint8_t i = 0; i < LED_BANK_2_LEN; i++) {
        m_altOutput |= LED_BANK_2[i];
        Delay_ms(DELAY_TIME);
    }

    // Illuminate bank 0 and 1 simultaneously
    uint8_t largerBankLen = (LED_BANK_1_LEN > LED_BANK_0_LEN) ? LED_BANK_1_LEN
                            : LED_BANK_0_LEN;
    for (uint8_t i = 0; i < largerBankLen; i++) {
        if (i < LED_BANK_0_LEN) {
            m_altOutput |= LED_BANK_0[i];
        }
        if (i < LED_BANK_1_LEN) {
            m_altOutput |= LED_BANK_1[i];
        }

        Delay_ms(DELAY_TIME);
    }

    Delay_ms(50);

    // Turn them off the same way they were turned on
    for (uint8_t i = 0; i < LED_BANK_2_LEN; i++) {
        m_altOutput &= ~LED_BANK_2[i];
        Delay_ms(DELAY_TIME);
    }

    ShifterStateSet(SR_UNDERGLOW_MASK);

    for (uint8_t i = 0; i < largerBankLen; i++) {
        if (i < LED_BANK_0_LEN) {
            m_altOutput &= ~LED_BANK_0[i];
        }
        if (i < LED_BANK_1_LEN) {
            m_altOutput &= ~LED_BANK_1[i];
        }

        Delay_ms(DELAY_TIME);
    }
    m_useAltOutput = false;
}