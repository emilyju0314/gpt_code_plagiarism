unsigned long CPU::RLCA(const byte& opCode)
{
    byte r = GetHighByte(m_AF);

    // Grab bit 7 and store it in the carryflag
    ISBITSET(r, 7) ? SetFlag(CarryFlag) : ClearFlag(CarryFlag);

    // Shift r left
    r = r << 1;

    // Set bit 0 of r to the old CarryFlag
    r = IsFlagSet(CarryFlag) ? SETBIT(r, 0) : CLEARBIT(r, 0);

    SetHighByte(&m_AF, r);

    // Clear sZ, clears N, clears H, affects C
    ClearFlag(ZeroFlag);
    ClearFlag(SubtractFlag);
    ClearFlag(HalfCarryFlag);

    return 4;
}