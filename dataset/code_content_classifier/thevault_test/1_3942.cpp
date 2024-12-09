ISR(TIMER2_OVF_vect) {
    register uint8_t reg;

    timer2A_state.lag += timer2A_state.duty4;   // Accumulate
    reg = timer2A_state.duty12;     // Keep duty cycle in register
    if(timer2A_state.lag & 0x10) {  // Add phase accumulator bit 4 overflow
        reg++;
    }
    timer2A_state.lag &= 0x0F;

    if(reg == 0) {
        TCCR2A &= ~(3<<COM2A0);  // PWM output off
    }
    else {
        OCR2A = reg;          // Apply duty cycle
        TCCR2A |= 3<<COM2A0;  // PWM output on
    }

    // Same for B channel
    timer2B_state.lag += timer2B_state.duty4;
    reg = timer2B_state.duty12;
    if(timer2B_state.lag & 0x10) {
        reg++;
    }
    timer2B_state.lag &= 0x0F;

    if(reg == 0) {
        TCCR2A &= ~(3<<COM2B0);
    }
    else {
        OCR2B = reg;
        TCCR2A |= 3<<COM2B0;
    }
}