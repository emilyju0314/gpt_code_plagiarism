size_t Sodaq_AT_Device::readLn(char* buffer, size_t size, uint32_t timeout)
{
    // Use size-1 to leave room for a string terminator
    size_t len = readBytesUntil(SODAQ_AT_DEVICE_TERMINATOR[SODAQ_AT_DEVICE_TERMINATOR_LEN - 1], buffer, size - 1, timeout);

    // check if the terminator is more than 1 characters, then check if the first character of it exists
    // in the calculated position and terminate the string there
    if ((SODAQ_AT_DEVICE_TERMINATOR_LEN > 1) && (buffer[len - (SODAQ_AT_DEVICE_TERMINATOR_LEN - 1)] == SODAQ_AT_DEVICE_TERMINATOR[0])) {
        len -= SODAQ_AT_DEVICE_TERMINATOR_LEN - 1;
    }

    // terminate string, there should always be room for it (see size-1 above)
    buffer[len] = '\0';

    return len;
}