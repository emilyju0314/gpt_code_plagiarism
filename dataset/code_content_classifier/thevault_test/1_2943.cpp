void DigitalInOutAnalogOut::Refresh() {
    switch (m_mode) {
        case INPUT_DIGITAL:
        case OUTPUT_DIGITAL:
        case OUTPUT_PWM:
            // Leave the work to the base class
            DigitalInOut::Refresh();
            break;
        case OUTPUT_ANALOG:
        // Do nothing here
        default:
            break;
    }
}