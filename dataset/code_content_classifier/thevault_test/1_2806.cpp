unsigned long CPU::LD_HL_n(const byte& opCode)
{
    byte n = ReadBytePC();
    m_MMU->Write(m_HL, n); // Load n into the address pointed at by HL.

    return 12;
}