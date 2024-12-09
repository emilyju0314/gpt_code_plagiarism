static void compensateAndDumpSequence(Print *aSerial, const volatile unsigned int *data, size_t length, uint16_t timebase) {
    for (size_t i = 0; i < length; i++) {
        uint32_t tDuration = data[i] * MICROS_PER_TICK;
        if (i & 1) {
            // Mark
            tDuration -= getMarkExcessMicros();
        } else {
            tDuration += getMarkExcessMicros();
        }
        dumpDuration(aSerial, tDuration, timebase);
    }

    // append a gap
    dumpDuration(aSerial, PRONTO_DEFAULT_GAP, timebase);
}