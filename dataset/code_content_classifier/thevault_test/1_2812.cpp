unsigned long CPU::ADCA_HL_(const byte& opCode)
{
    byte HL = m_MMU->Read(m_HL);
    ADC(HL);
    return 8;
}