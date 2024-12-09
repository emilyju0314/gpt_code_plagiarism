unsigned long CPU::ADCAr(const byte& opCode)
{
    byte* r = GetByteRegister(opCode);
    ADC(*r);
    return 4;
}