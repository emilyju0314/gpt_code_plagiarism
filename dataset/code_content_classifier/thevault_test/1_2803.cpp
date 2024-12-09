unsigned long CPU::PUSHrr(const byte& opCode)
{
    ushort* rr = GetUShortRegister(opCode >> 4, true);
    PushUShortToSP(*rr);

    return 16;
}