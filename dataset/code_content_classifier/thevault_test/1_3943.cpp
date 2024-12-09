ISR(TIMER1_OVF_vect) {
    OCR1A = timer1A;
    OCR1B = timer1B;
    TIMSK1 &= ~(1<<TOIE1); // Disable timer 1 overflow interrupt ( will be re-enabled by applysTimer1PWM() ).
}