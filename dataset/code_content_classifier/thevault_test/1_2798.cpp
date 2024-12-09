unsigned long CPU::CPr(const byte& opCode)
{
    byte* r = GetByteRegister(opCode);
    byte A = GetHighByte(m_AF);
    byte result = A - (*r);

    (result == 0x00) ? SetFlag(ZeroFlag) : ClearFlag(ZeroFlag);
    SetFlag(SubtractFlag);
    ((A & 0xFF) < ((*r) & 0xFF)) ? SetFlag(CarryFlag) : ClearFlag(CarryFlag);
    ((A & 0x0F) < ((*r) & 0x0F)) ? SetFlag(HalfCarryFlag) : ClearFlag(HalfCarryFlag);

    return 4;
}