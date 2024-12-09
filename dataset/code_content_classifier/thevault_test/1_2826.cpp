unsigned long CPU::SRAr(const byte& opCode)
{
    byte* r = GetByteRegister(opCode);

    // Grab bit 0 and store it in the carryflag
    ISBITSET(*r, 0) ? SetFlag(CarryFlag) : ClearFlag(CarryFlag);

    // Shift r right
    (*r) = (*r >> 1) | (*r & 0x80);

    // Affects Z, clears N, clears H, affects C
    (*r == 0x00) ? SetFlag(ZeroFlag) : ClearFlag(ZeroFlag);
    ClearFlag(SubtractFlag);
    ClearFlag(HalfCarryFlag);

    return 8;
}