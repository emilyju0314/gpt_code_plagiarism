void OneWireThermometer::resetAndAddress()
{
    oneWire.reset();                // reset device 
    if (useAddress)
    {
        oneWire.matchROM(address);  // select which device to talk to
    }
    else
    {
        oneWire.skipROM();          // broadcast
    }
}