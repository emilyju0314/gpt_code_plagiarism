const double
ConnectThreadContainer::getConnectionRate(const std::string& path) const
{
    BOOST_ASSERT(path.empty() == false);
    double res = 0;
    Locker lock(&m_lock);
    for (ConnectThreadList::const_iterator i = m_list.begin();
         i != m_list.end(); i++)
    {
        if ((*i)->getPath() == path)
        {
            res += (*i)->getRate();
        }
    }

    return res;
}