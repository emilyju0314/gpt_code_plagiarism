MBC5_MBC::MBC5_MBC(byte* pROM, byte* pRAM) :
    MBC(pROM, pRAM),
    m_RAMG(0x00),
    m_ROMBank(0x0000),
    m_RAMBank(0x00)
{
}