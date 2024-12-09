bool Base::isLocal(const std::string& id) const
{
    // FIXME!!! used mainly in utests
    if (m_local)
        return true;

    StringList::const_iterator find =
        std::find(m_local_load_list.begin(), m_local_load_list.end(), id);
    return (find != m_local_load_list.end());
}