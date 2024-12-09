unsigned long CPU::OR_HL_(const byte& opCode)
{
    byte r = m_MMU->Read(m_HL);
    SetHighByte(&m_AF, r | GetHighByte(m_AF));

    // Affects Z and clears NHC
    if (GetHighByte(m_AF) == 0x00)
    {
        SetFlag(ZeroFlag);
    }
    else
    {
        ClearFlag(ZeroFlag);
    }

    ClearFlag(SubtractFlag);
    ClearFlag(HalfCarryFlag);
    ClearFlag(CarryFlag);

    return 8;
}