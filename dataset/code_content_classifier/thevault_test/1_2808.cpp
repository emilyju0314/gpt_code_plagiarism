unsigned long CPU::SBCAr(const byte& opCode)
{
    byte* r = GetByteRegister(opCode);
    SBC(*r);
    return 4;
}