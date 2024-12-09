unsigned long CPU::SUB_HL_(const byte& opCode)
{
    byte A = GetHighByte(m_AF);
    byte HL = m_MMU->Read(m_HL);
    byte result = A - HL;
    SetHighByte(&m_AF, result);

    (result == 0x00) ? SetFlag(ZeroFlag) : ClearFlag(ZeroFlag);
    SetFlag(SubtractFlag);
    ((A & 0x0F) < (result & 0x0F)) ? SetFlag(HalfCarryFlag) : ClearFlag(HalfCarryFlag);
    ((A & 0xFF) < (result & 0xFF)) ? SetFlag(CarryFlag) : ClearFlag(CarryFlag);

    return 8;
}