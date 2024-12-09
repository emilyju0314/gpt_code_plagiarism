unsigned long CPU::ADDA_HL_(const byte& opCode)
{
    byte A = GetHighByte(m_AF);
    byte HL = m_MMU->Read(m_HL);
    SetHighByte(&m_AF, AddByte(A, HL));

    return 8;
}