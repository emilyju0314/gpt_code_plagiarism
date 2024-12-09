unsigned long CPU::LD_DE_A(const byte& opCode)
{
    m_MMU->Write(m_DE, GetHighByte(m_AF));
    return 8;
}