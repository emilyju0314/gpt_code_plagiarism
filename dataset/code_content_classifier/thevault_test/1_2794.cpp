unsigned long CPU::LD_BC_A(const byte& opCode)
{
    m_MMU->Write(m_BC, GetHighByte(m_AF));
    return 8;
}