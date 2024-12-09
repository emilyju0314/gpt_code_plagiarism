OneWireThermometer::OneWireThermometer(bool crcOn, bool useAddr, bool parasitic, PinName pin, int device_id) :
    useCRC(crcOn), useAddress(useAddr), useParasiticPower(parasitic), 
    oneWire(pin, STANDARD), deviceId(device_id), resolution(twelveBit)
{
    // NOTE: the power-up resolution of a DS18B20 is 12 bits. The DS18S20's resolution is always
    // 9 bits + enhancement, but we treat the DS18S20 as fixed to 12 bits for calculating the
    // conversion time Tconv.
}