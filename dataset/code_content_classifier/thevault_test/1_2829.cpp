MBC3_MBC::MBC3_MBC(byte* pROM, byte* pRAM) :
    MBC(pROM, pRAM),
    m_ROMBank(0x01),
    m_RAMBank(0x00)
{
    memset(m_RTCRegisters, 0x00, ARRAYSIZE(m_RTCRegisters));
}