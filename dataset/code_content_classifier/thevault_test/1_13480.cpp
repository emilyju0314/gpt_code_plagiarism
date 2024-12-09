void InThreadContainer::addInfo(const InputInfoPtr& info)
{
    Locker lock(&m_lock);

    InThreadList::iterator found =
        std::find_if(m_list.begin(), m_list.end(),
                     boost::bind<bool>(IsRouteMatch(), info, _1));
    if (found != m_list.end())
    {
        (*found)->updateInfo(info);
    }
    else
    {
        // path should be unique
        InThreadList::iterator find_path = std::find_if(
            m_list.begin(), m_list.end(),
            boost::bind<bool>(IsRouteMatch(),
                              info->getPath(), _1));
        BOOST_ASSERT(find_path == m_list.end());

        if (m_stop.isStopped())
            return;

        // start the thread
        InThreadPtr thread = getFactory()->getInThread(info);
        getFactory()->getScheduler()->startThread(thread);
        m_list.push_back(thread);
    }
}