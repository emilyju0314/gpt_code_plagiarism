const InThreadPtr StatCommand::getInThread(const InputInfoPtr& info) const
{
    BOOST_ASSERT(info);
    Factory* factory = getModule<Streamer>()->getHTTPFactory();
    BOOST_ASSERT(factory);
    InThreadContainerPtr inthreads = factory->getInThreadContainer();
    BOOST_ASSERT(inthreads);
    InThreadPtr inthread = inthreads->getThreadByPath(info->getPath());
    BOOST_ASSERT(inthread);

    return inthread;
}