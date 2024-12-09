unsigned long CPU::AND_HL_(const byte& opCode)
{
    byte HL = m_MMU->Read(m_HL);
    byte result = HL & GetHighByte(m_AF);
    SetHighByte(&m_AF, result);

    if (result == 0x00)
    {
        SetFlag(ZeroFlag);
    }
    else
    {
        ClearFlag(ZeroFlag);
    }

    ClearFlag(SubtractFlag);
    SetFlag(HalfCarryFlag);
    ClearFlag(CarryFlag);

    return 8;
}