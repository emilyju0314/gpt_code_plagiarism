unsigned long CPU::ADCAn(const byte& opCode)
{
    ADC(ReadBytePC());
    return 8;
}