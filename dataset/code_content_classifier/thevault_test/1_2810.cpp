unsigned long CPU::RRCA(const byte& opCode)
{
    byte A = GetHighByte(m_AF);
    bool carry = ISBITSET(A, 0);

    A = A >> 1;

    if (carry)
    {
        SetFlag(CarryFlag);
        A = SETBIT(A, 7);
    }
    else
    {
        ClearFlag(CarryFlag);
        A = CLEARBIT(A, 7);
    }

    SetHighByte(&m_AF, A);

    ClearFlag(ZeroFlag);
    ClearFlag(SubtractFlag);
    ClearFlag(HalfCarryFlag);

    return 4;
}