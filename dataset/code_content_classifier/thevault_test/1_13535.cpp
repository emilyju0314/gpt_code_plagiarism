void ConnectThreadContainer::stopThreads(const InThreadPtr& thread)
{
    BOOST_ASSERT(thread);
    const std::string path = thread->getInfo()->getPath();
    BOOST_ASSERT(path.empty() == false);

    ConnectThreadList stoplist;

    Locker lock(&m_lock);
    for (ConnectThreadList::iterator i = m_list.begin();
         i != m_list.end(); i++)
    {
        if ((*i)->getPath() == path)
        {
            stoplist.push_back(*i);
            getFactory()->getStopThread()->addConnectThread(*i);
        }
    }

    // remove them from the list
    for (ConnectThreadList::iterator i = stoplist.begin();
         i != stoplist.end(); i++)
    {
        m_list.remove(*i);
    }
}