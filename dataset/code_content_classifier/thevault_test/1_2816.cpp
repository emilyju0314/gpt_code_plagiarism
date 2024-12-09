unsigned long CPU::CP_HL_(const byte& opCode)
{
    byte HL = m_MMU->Read(m_HL);
    byte A = GetHighByte(m_AF);
    byte result = A - HL;

    (result == 0x00) ? SetFlag(ZeroFlag) : ClearFlag(ZeroFlag);
    SetFlag(SubtractFlag);
    ((A & 0x0F) < (HL & 0x0F)) ? SetFlag(HalfCarryFlag) : ClearFlag(HalfCarryFlag);
    ((A & 0xFF) < (HL & 0xFF)) ? SetFlag(CarryFlag) : ClearFlag(CarryFlag);

    return 8;
}