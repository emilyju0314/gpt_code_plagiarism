SdCardDriver::SdCardDriver(const PeripheralRoute *misoInfo,
                           const PeripheralRoute *ssInfo,
                           const PeripheralRoute *sckInfo,
                           const PeripheralRoute *mosiInfo,
                           uint8_t peripheral)
    : SerialBase(misoInfo, ssInfo, sckInfo, mosiInfo, peripheral),
      m_errorCode(0) {
    PortMode(SerialBase::SPI);
    SpiClock(SCK_LOW, LEAD_SAMPLE);
    PortOpen();
}