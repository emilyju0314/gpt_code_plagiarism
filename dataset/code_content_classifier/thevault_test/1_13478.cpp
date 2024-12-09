void InThreadContainer::setInfo(const InputInfoList& list)
{
    if (m_stop.isStopped())
    {
        return;
    }

    InThreadList old = m_list;

    // process all gotten data
    std::for_each(list.begin(), list.end(),
                  boost::bind(&InThreadContainer::addInfo, this,
                              _1, boost::ref(old)));

    // remove missing
    std::for_each(old.begin(), old.end(),
                  boost::bind(&InThreadContainer::delInfo,
                              this, _1));
}