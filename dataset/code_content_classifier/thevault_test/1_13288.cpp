void Processor::doStartStream(const IMessagePtr& in,
                              const IMessagePtr& out)
{
    BOOST_ASSERT(in);

    const std::string type = in->getValue(msg::key::TYPE);
    BOOST_ASSERT(type.empty() == false);
    const std::string source = in->getValue(msg::key::DVBSOURCE);
    BOOST_ASSERT(source.empty() == false);

    StreamChannelPtr channel(new StreamChannel(type, source, m_factory));
    BOOST_ASSERT(channel);

    const std::string channel_id = in->getValue(msg::key::TVCHANNELID);
    BOOST_ASSERT(channel_id.empty() == false);
    // retrive DVB tune data and other info from DB
    channel->setData(channel_id);

    m_channels.insertStreamChannel(channel); // can produce exception

    // setting some result info
    BOOST_ASSERT(out);

    const std::string channel_name = channel->getName();
    BOOST_ASSERT(channel_name.empty() == false);
    out->setData(msg::key::TVCHANNELNAME, channel_name);

    const std::string channel_no = channel->getNumber();
    BOOST_ASSERT(channel_no.empty() == false);
    out->setData(msg::key::TVCHANNELNO, channel_no);

    const std::string resource =
        channel->getDev()->getStringParam(dev::UUID);
    out->setData(msg::key::RESOURCE, resource);

    // set initial dvb info
    IDevPtr dev = channel->getDev();
    BOOST_ASSERT(dev);
    dev->setState(dev::WORK);
    dev->setParam(dev::DVBACTIVITY, dev::STREAMING);
    dev->setParam(dev::HASLOCK, 0);
    dev->setParam(dev::SIGNAL, 0);
    dev->setParam(dev::SNR, 0);
    dev->setParam(dev::UNC, 0);
    dev->setParam(dev::BER, 0);
    dev->setParam(dev::LOSTLOCK, 0);
    dev->setParam(dev::RATE, 0);
}