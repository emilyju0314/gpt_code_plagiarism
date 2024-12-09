void Streamer::processInRoute()
{
    InfoSet current = getInputInfoFromDB();

    // elements to be deleted
    InfoSet deldata = m_info.getDel(current);
    std::for_each(deldata.begin(), deldata.end(),
                  boost::bind(&Streamer::delInputInfo, this, _1));

    // elements to be added
    InfoSet newdata = m_info.getAdd(current);
    std::for_each(newdata.begin(), newdata.end(),
                  boost::bind(&Streamer::addInputInfo, this, _1));
}