MBC2_MBC::MBC2_MBC(byte* pROM) :
    MBC(pROM, new byte[0x1FF + 1]),
    m_ROMBank(0x01)
{
}