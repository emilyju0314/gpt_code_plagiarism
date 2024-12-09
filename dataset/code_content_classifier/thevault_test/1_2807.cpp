unsigned long CPU::SUBr(const byte& opCode)
{
    byte* r = GetByteRegister(opCode);
    byte A = GetHighByte(m_AF);
    byte result = A - (*r);
    SetHighByte(&m_AF, result);

    (result == 0x00) ? SetFlag(ZeroFlag) : ClearFlag(ZeroFlag);
    SetFlag(SubtractFlag);
    ((A & 0x0F) < ((*r) & 0x0F)) ? SetFlag(HalfCarryFlag) : ClearFlag(HalfCarryFlag);
    ((A & 0xFF) < ((*r) & 0xFF)) ? SetFlag(CarryFlag) : ClearFlag(CarryFlag);

    return 4;
}