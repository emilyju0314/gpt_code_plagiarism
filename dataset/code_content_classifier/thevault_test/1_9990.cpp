cDuplicationManager::cDuplicationManager() : m_DeskDupl(nullptr),
m_AcquiredDesktopImage(nullptr),
m_MetaDataBuffer(nullptr),
m_MetaDataSize(0),
m_OutputNumber(0),
m_Device(nullptr)
{
	RtlZeroMemory(&m_OutputDesc, sizeof(m_OutputDesc));
}