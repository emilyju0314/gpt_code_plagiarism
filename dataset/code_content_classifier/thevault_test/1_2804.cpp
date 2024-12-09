unsigned long CPU::ANDn(const byte& opCode)
{
    byte n = ReadBytePC();

    byte result = GetHighByte(m_AF) & n;
    SetHighByte(&m_AF, result);

    (result == 0x00) ? SetFlag(ZeroFlag) : ClearFlag(ZeroFlag);
    ClearFlag(SubtractFlag);
    SetFlag(HalfCarryFlag);
    ClearFlag(CarryFlag);

    return 8;
}