unsigned long CPU::ANDr(const byte& opCode)
{
    byte* r = GetByteRegister(opCode);
    byte result = (*r) & GetHighByte(m_AF);
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

    return 4;
}