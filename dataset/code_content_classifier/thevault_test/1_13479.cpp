const InputInfoList InThreadContainer::getInfo() const
{
    Locker lock(&m_lock);
    InputInfoList result;

    for (InThreadList::const_iterator i = m_list.begin();
         i != m_list.end(); i++)
    {
        result.push_back((*i)->getInfo());
    }

    return result;
}