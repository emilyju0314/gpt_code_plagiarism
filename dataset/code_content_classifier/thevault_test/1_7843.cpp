void ICACHE_RAM_ATTR PinA() {
    cli(); // stop interrupts happening before we read pin values
    _reading_a = digitalRead(_pin_a);
    _reading_b = digitalRead(_pin_b);
    if (_reading_a && _reading_b && _a_flag) { // check that we have both pins at detent (HIGH) and that we are
                                               // expecting detent on this pin's rising edge
        _position++;
        _a_flag = 0;
        _b_flag = 0;
    } else if (_reading_a && !_reading_b) {
        _b_flag = 1; // signal that we're expecting pin B to signal the transition to detent from free rotation
    }
    sei(); // restart interrupts
}