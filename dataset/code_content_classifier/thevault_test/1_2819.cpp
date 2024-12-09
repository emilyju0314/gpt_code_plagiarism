unsigned long CPU::SBCAn(const byte& opCode)
{
    byte n = ReadBytePC();
    SBC(n);
    return 8;
}