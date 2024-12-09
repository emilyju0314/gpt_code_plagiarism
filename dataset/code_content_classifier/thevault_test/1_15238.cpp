bool WisdomContainerEntry::getEntry(const std::string &name,
                                    IWisdomContainerEntry::EntryType type,
                                    WisdomContainerEntry *entry) const
{
    if ( ENTRY_TYPE_OBJECT != m_type )
    {
        return false;
    }
    return m_container->getEntry(m_path, name, type, entry);
}