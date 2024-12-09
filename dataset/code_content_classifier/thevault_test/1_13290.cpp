const StringList Processor::getChannelNames(const IDevPtr& dev) const
{
    StreamChannelList list = m_channels.getStreamChannels(dev);
    StringList res;
    // stop all channel associated with the dev
    for (StreamChannelList::iterator i = list.begin();
         i != list.end(); i++)
    {
        // we should add it
        res.push_back((*i)->getName());
    }

    return res;
}