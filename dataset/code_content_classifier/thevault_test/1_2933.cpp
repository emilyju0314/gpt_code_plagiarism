void SetBrightness(uint8_t level) {
    SpiPort.SpiSsMode(SerialDriver::LINE_ON);
    SpiPort.SpiTransferData(0xfe);
    SpiPort.SpiTransferData(0x53);
    SpiPort.SpiTransferData(level);
    SpiPort.SpiSsMode(SerialDriver::LINE_OFF);
}