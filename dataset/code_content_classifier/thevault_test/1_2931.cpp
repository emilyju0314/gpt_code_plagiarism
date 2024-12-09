void DigitalInOut::Refresh() {
    DigitalIn::Refresh();

    switch (m_mode) {
        case OUTPUT_DIGITAL:
            if (m_overloadFoldbackCnt) {
                if (!(--m_overloadFoldbackCnt)) {
                    // Coming out of foldback, reset the overload
                    // delay timer and restore the pin state
                    OutputPin(m_outState);
                    m_overloadTripCnt = OVERLOAD_TRIP_TICKS;
                }
            }
            // If output is true and input is false, the pin is overloaded
            else if (m_outState && !StateRT()) {
                // When the overload counter hits zero, signal the overload
                if (m_overloadTripCnt && !--m_overloadTripCnt) {
                    IsInHwFault(true);
                    OutputPin(false);
                    m_overloadFoldbackCnt = OVERLOAD_FOLDBACK_TICKS;
                }
            }
            else {
                // Not overloaded, reset the overload delay timer
                m_overloadTripCnt = OVERLOAD_TRIP_TICKS;
                IsInHwFault(false);
            }
            if (!m_pulseActive) {
                break;
            }

            if (m_pulseStopCount == 0 || m_pulseCounter < m_pulseStopCount) {
                if (m_pulseValue) {
                    if (tickCnt - m_pulseStart >= m_pulseOnTicks) {
                        // Turn off the pulse
                        m_pulseValue = false;
                        m_pulseStart = tickCnt;
                        // Reset the filter when the output changes (to
                        // prevent an overload condition being falsely reported)
                        m_overloadTripCnt = OVERLOAD_TRIP_TICKS;
                        OutputPin(false);
                        m_outState = false;
                        // Increment the counter after a complete cycle
                        ++m_pulseCounter;
                        // If a stop is pending, handle it now that the cycle
                        // has completed
                        if (m_pulseStopPending) {
                            m_pulseActive = false;
                            m_pulseStopPending = false;
                        }
                    }
                }
                else {
                    // If a stop is pending, handle it right away while the
                    // pulseValue is low
                    if (m_pulseStopPending) {
                        m_pulseActive = false;
                        m_pulseStopPending = false;
                    }
                    else if (tickCnt - m_pulseStart >= m_pulseOffTicks) {
                        // Turn on the pulse
                        m_pulseValue = true;
                        m_pulseStart = tickCnt;
                        // Reset the filter when the output changes (to
                        // prevent an overload condition being falsely reported)
                        m_overloadTripCnt = OVERLOAD_TRIP_TICKS;
                        // Assert the output pin if we are not in overload
                        // foldback
                        OutputPin(!m_overloadFoldbackCnt);
                        m_outState = true;
                    }
                }
            }
            else if (m_pulseCounter == m_pulseStopCount) {
                m_pulseActive = false;
                m_pulseStopPending = false;
            }
            break;
        case OUTPUT_PWM:
        case INPUT_DIGITAL:
        default:
            break;
    }
}