SPS30_ERR SPS30::read_data(uint8_t desired_bytes, uint8_t *buf, size_t buf_len, bool stop) {
    if (desired_bytes > buf_len || buf == NULL || (desired_bytes % 2) != 0) {
        return SPS30_BAD_ARGUMENTS;
    }

    // The SPS30 doesn't seem to handle separate 30-byte reads; instead of continuing where it left off (persistent pointer theory),
    // it just spits out junk bytes.

//    // Break read into 20-byte segments: every two bytes read has one byte of checksum and the read has to fit within the Arduino Wire 32-byte buffer
//    while (desired_bytes > 10) {
//        SPS30_ERR stat = read_data(10, buf, buf_len, false);
//        if (stat != SPS30_OK) {
//            return stat;
//        }
//        bytes_read += 10;
//        desired_bytes -= 10;
//        buf += 10;
//        buf_len -= 10;
//    }

    // prep CRC'd buffer
    uint8_t raw_buf[SPS30_I2C_MAX_RX_BUFFER_LEN];
    uint8_t bytes_read = 0;
    if (desired_bytes > sizeof(raw_buf) || desired_bytes > SPS30_I2C_MAX_DATA_SIZE) {
        return SPS30_I2C_TOO_LONG;
    }
    // prep bounds
    uint8_t raw_expected = desired_bytes + desired_bytes / 2; // one CRC byte for every two data bytes
    // run i2c transaction
    uint8_t raw_received = m_wirePort->requestFrom(m_i2c_addr, raw_expected, stop);
    // break if not all was received
    if (raw_received != raw_expected) {
#ifdef SERIAL_DEBUG
        Serial.printlnf("requested %d, got %d bytes", raw_expected, raw_received);
#endif
        return SPS30_READ_INCOMPLETE;
    }
    // fill CRC'd buffer
    for (int raw_buf_idx = 0; raw_buf_idx < raw_received; raw_buf_idx++) {
        raw_buf[raw_buf_idx] = m_wirePort->read();
    }
    // only triplets of bytes can pass CRC, but the checks earlier already guarantee triplets
    // convert CRC'd data into confirmed data
    for (int pair_idx = 0; pair_idx*3 < raw_received; pair_idx++) {
        int raw_idx = pair_idx * 3;
        uint8_t checksum = sensirion_CalcCrc(&raw_buf[raw_idx]);
        if (raw_buf[raw_idx+2] != checksum) {
#ifdef SERIAL_DEBUG
            Serial.printlnf("tuple %x %x %x (%x) failed checksum; breaking", raw_buf[raw_idx], raw_buf[raw_idx+1], raw_buf[raw_idx+2], checksum);
#endif
            return SPS30_CRC_FAIL;
        }
        buf[0] = raw_buf[raw_idx];
        buf[1] = raw_buf[raw_idx+1];
        buf += 2;
        buf_len -= 2;
        bytes_read += 2;
#ifdef SERIAL_DEBUG
        Serial.printlnf("read '%x' '%x' %x (%x)", raw_buf[raw_idx], raw_buf[raw_idx+1], raw_buf[raw_idx+2], checksum);
#endif
    }
    return SPS30_OK;
}