void IRsend::sendPronto(const uint16_t *data, unsigned int length, uint_fast8_t aNumberOfRepeats) {
    unsigned int timebase = (microsecondsInSeconds * data[1] + referenceFrequency / 2) / referenceFrequency;
    unsigned int khz;
    switch (data[0]) {
    case learnedToken: // normal, "learned"
        khz = toFrequencyKHz(data[1]);
        break;
    case learnedNonModulatedToken: // non-demodulated, "learned"
        khz = 0U;
        break;
    default:
        return; // There are other types, but they are not handled yet.
    }
    unsigned int intros = 2 * data[2];
    unsigned int repeats = 2 * data[3];
    IR_DEBUG_PRINT(F("sendPronto intros="));
    IR_DEBUG_PRINT(intros);
    IR_DEBUG_PRINT(F(" repeats="));
    IR_DEBUG_PRINTLN(repeats);
    if (numbersInPreamble + intros + repeats != length) { // inconsistent sizes
        return;
    }

    /*
     * Generate a new microseconds timing array for sendRaw.
     * If recorded by IRremote, intro contains the whole IR data and repeat is empty
     */
    uint16_t durations[intros + repeats];
    for (unsigned int i = 0; i < intros + repeats; i++) {
        uint32_t duration = ((uint32_t) data[i + numbersInPreamble]) * timebase;
        durations[i] = (unsigned int) ((duration <= UINT16_MAX) ? duration : UINT16_MAX);
    }

    /*
     * Send the intro. intros is even.
     * Do not send the trailing space here, send it if repeats are requested
     */
    if (intros >= 2) {
        sendRaw(durations, intros - 1, khz);
    }

    if (repeats == 0 || aNumberOfRepeats == 0) {
        // only send intro once
        return;
    }

    /*
     * Now send the trailing space/gap of the intro and all the repeats
     */
    if (intros >= 2) {
        delay(durations[intros - 1] / MICROS_IN_ONE_MILLI); // equivalent to space(durations[intros - 1]); but allow bigger values for the gap
    }
    for (unsigned int i = 0; i < aNumberOfRepeats; i++) {
        sendRaw(durations + intros, repeats - 1, khz);
        if ((i + 1) < aNumberOfRepeats) { // skip last trailing space/gap, see above
            delay(durations[intros + repeats - 1] / MICROS_IN_ONE_MILLI);
        }
    }
}