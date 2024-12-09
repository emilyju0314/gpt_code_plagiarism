unsigned long CPU::RLr(const byte& opCode)
{
    byte* r = GetByteRegister(opCode);

    // Grab the current CarryFlag val
    bool carry = IsFlagSet(CarryFlag);

    // Grab bit 7 and store it in the carryflag
    ISBITSET(*r, 7) ? SetFlag(CarryFlag) : ClearFlag(CarryFlag);

    // Shift r left
    (*r) = *r << 1;

    // Set bit 0 of r to the old CarryFlag
    (*r) = carry ? SETBIT((*r), 0) : CLEARBIT((*r), 0);

    // Affects Z, clears N, clears H, affects C
    (*r == 0x00) ? SetFlag(ZeroFlag) : ClearFlag(ZeroFlag);
    ClearFlag(SubtractFlag);
    ClearFlag(HalfCarryFlag);

    return 8;
}