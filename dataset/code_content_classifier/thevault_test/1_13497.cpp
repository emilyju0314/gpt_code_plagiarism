void ScanThread::tuneDVBS(const ScanData& data)
{
    // note: it's locked at the caller

    BOOST_ASSERT(data.size() == 5);

    // check dev type
    BOOST_ASSERT(m_dev->getStringParam(dev::TYPE) == dev::DVB_S);

    //# freq pol sr fec
    //S 12578000 H 19850000 3/4
    m_dev->setParam(dev::FREQUENCY, data[1]);
    m_dev->setParam(dev::POLARITY, data[2]);
    // symbol rate has to be deleted by 1000 for GST
    uint sr = boost::lexical_cast<uint>(data[3]);
    const std::string sr_conv =
        boost::lexical_cast<std::string>(sr/1000);
    m_dev->setParam(dev::SYMBOL_RATE, sr_conv);

    m_dev->setParam(dev::CODE_RATE_HP,
                    m_conv.getCodeRate(data[4]));
}