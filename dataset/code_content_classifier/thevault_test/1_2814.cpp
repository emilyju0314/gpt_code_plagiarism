unsigned long CPU::SBCA_HL_(const byte& opCode)
{
    byte HL = m_MMU->Read(m_HL);
    SBC(HL);
    return 8;
}