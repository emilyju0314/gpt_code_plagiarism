unsigned long CPU::BITbr(const byte& opCode)
{
    byte bit = (opCode >> 3) & 0x07;
    byte* r = GetByteRegister(opCode);

    // Test bit b in r
    (!ISBITSET(*r, bit)) ? SetFlag(ZeroFlag) : ClearFlag(ZeroFlag);

    SetFlag(HalfCarryFlag); // H is set
    ClearFlag(SubtractFlag); // N is reset

    return 8;
}