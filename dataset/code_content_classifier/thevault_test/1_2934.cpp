void SetCursor(uint8_t row, uint8_t column) {
    // Bounds-check the passed-in row and column
    if (row >= NUM_ROWS) {
        row = 0;
    }
    if (column >= NUM_COLUMNS) {
        column = 0;
    }

    uint8_t position = row * NUM_COLUMNS + column;
    SpiPort.SpiSsMode(SerialDriver::LINE_ON);
    SpiPort.SpiTransferData(0xfe);
    SpiPort.SpiTransferData(0x45);
    SpiPort.SpiTransferData(position);
    SpiPort.SpiSsMode(SerialDriver::LINE_OFF);
}