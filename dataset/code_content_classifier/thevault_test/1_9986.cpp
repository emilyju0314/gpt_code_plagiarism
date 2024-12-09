int Sodaq_AT_Device::timedRead(uint32_t timeout) const
{
    int c;
    uint32_t _startMillis = millis();

    do {
        c = _modemStream->read();

        if (c >= 0) {
            return c;
        }
    } while (millis() - _startMillis < timeout);

    return -1; // -1 indicates timeout
}