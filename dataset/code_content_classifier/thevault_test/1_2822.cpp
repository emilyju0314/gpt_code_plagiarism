unsigned long CPU::CPn(const byte& opCode)
{
    byte n = ReadBytePC();
    byte A = GetHighByte(m_AF);
    byte result = A - n;

    (result == 0x00) ? SetFlag(ZeroFlag) : ClearFlag(ZeroFlag);
    ((A & 0xFF) < (n & 0xFF)) ? SetFlag(CarryFlag) : ClearFlag(CarryFlag);
    ((A & 0x0F) < (n & 0x0F)) ? SetFlag(HalfCarryFlag) : ClearFlag(HalfCarryFlag);
    SetFlag(SubtractFlag);

    return 8;
}