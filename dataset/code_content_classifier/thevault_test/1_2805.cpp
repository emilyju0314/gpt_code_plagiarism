unsigned long CPU::POPrr(const byte& opCode)
{
    ushort* rr = GetUShortRegister(opCode >> 4, true);
    (*rr) = PopUShort();

    if (((opCode >> 4) & 0x03) == 0x03)
    {
        (*rr) &= 0xFFF0;
    }

    return 12;
}