QString CVarGlobalEnumList::GetItemName(uint index)
{
    if (!m_pEnum || index >= static_cast<uint>(m_pEnum->strings.size()))
    {
        return QString();
    }
    return m_pEnum->strings[index];
}