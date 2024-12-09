unsigned long CPU::RRr(const byte& opCode)
{
    byte* r = GetByteRegister(opCode);

    // Grab the current CarryFlag val
    bool carry = IsFlagSet(CarryFlag);

    // Grab bit 0 and store it in the carryflag
    ISBITSET(*r, 0) ? SetFlag(CarryFlag) : ClearFlag(CarryFlag);

    // Shift r right
    (*r) = *r >> 1;

    // Set bit 7 of r to the old CarryFlag
    (*r) = carry ? SETBIT((*r), 7) : CLEARBIT((*r), 7);

    // Affects Z, clears N, clears H, affects C
    (*r == 0x00) ? SetFlag(ZeroFlag) : ClearFlag(ZeroFlag);
    ClearFlag(SubtractFlag);
    ClearFlag(HalfCarryFlag);

    return 8;
}