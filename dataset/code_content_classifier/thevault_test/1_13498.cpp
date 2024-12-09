void ScanThread::tuneDVBT(const ScanData& data)
{
    // note: it's locked at the caller

    BOOST_ASSERT(data.size() == 9);

    // check dev type
    BOOST_ASSERT(m_dev->getStringParam(dev::TYPE) == dev::DVB_T);

    // # T freq bw fec_hi fec_lo mod transmission-mode
    // guard-interval hierarchy
    // T 578000000 8MHz 3/4 NONE QAM64 8k 1/32 NONE
    m_dev->setParam(dev::FREQUENCY, data[1]);

    m_dev->setParam(dev::DVBBANDWIDTH,
                    m_conv.getBandwidth(data[2]));

    m_dev->setParam(dev::CODE_RATE_HP,
                    m_conv.getCodeRate(data[3]));

    m_dev->setParam(dev::CODE_RATE_LP,
                    m_conv.getCodeRate(data[4]));

    m_dev->setParam(dev::MODULATION,
                    m_conv.getModulation(data[5]));

    m_dev->setParam(dev::TRANSMODE,
                    m_conv.getTransmode(data[6]));

    m_dev->setParam(dev::GUARD,
                    m_conv.getGuard(data[7]));

    m_dev->setParam(dev::HIERARCHY,
                    m_conv.getHierarchy(data[8]));

}