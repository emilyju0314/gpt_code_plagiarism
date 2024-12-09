void InfoCommand::getInfo(const std::string& name,
                          std::string* result)
{
    BOOST_ASSERT(result);
    const std::string NAME = "name: ";
    const std::string ADAPTER = "adapter: ";
    const std::string FRONTEND = "frontend: ";
    const std::string TYPE = "type: ";
    const std::string SIGNAL_SOURCE = "signal source: ";
    const std::string FREQUENCY = "frequency: ";
    const std::string STATUS = "status: ";
    const std::string SIGNAL = "signal: ";
    const std::string SNR = "snr: ";
    const std::string BER = "ber: ";
    const std::string UNC = "unc: ";
    const std::string BANDWIDTH = "bandwidth: ";
    const std::string ACTIVITY = "activity: ";
    const std::string TUNED_CHANNELS = "tuned channels: ";

    // FIXME!!! add check all lengths
    size_t max_size = TUNED_CHANNELS.size();

    IDevPtr dev = getDev(name);
    *result += "\n\n";
    *result += base::Utils::align(NAME, max_size) +
        dev->getStringParam(dev::NAME) + "\n";
    *result += base::Utils::align(ADAPTER, max_size) +
        dev->getStringParam(dev::ADAPTER) + "\n";
    *result += base::Utils::align(FRONTEND, max_size) +
        dev->getStringParam(dev::FRONTEND) + "\n";

    *result += base::Utils::align(TYPE, max_size);
    if (dev->getStringParam(dev::TYPE) == dev::DVB_S)
    {
        *result += DVB_S_NAME;
    }
    else if (dev->getStringParam(dev::TYPE) == dev::DVB_T)
    {
        *result += DVB_T_NAME;
    }
    else if (dev->getStringParam(dev::TYPE) == dev::DVB_C)
    {
        *result += DVB_C_NAME;
    }
    else
    {
        BOOST_ASSERT(false);
    }
    *result += "\n";

    *result += base::Utils::align(FREQUENCY, max_size) +
        getParamInfo(dev::FREQUENCY, dev) + " Hz\n";

    std::string source_name;
    try
    {
        source_name = Utils::getSourceName(getFactory(),
                                           dev->getStringParam(dev::SOURCE));
    }
    catch(...)
    {
        source_name = NOTAVAILABLE;
    }


    *result += base::Utils::align(SIGNAL_SOURCE, max_size) +
        source_name + "\n";

    *result += base::Utils::align(STATUS, max_size);
    if (dev->hasParam(dev::HASLOCK))
    {
        if (dev->getStringParam(dev::HASLOCK) == "0")
        {
            *result += "does not have lock";
        }
        else
        {
            *result += "has lock";
        }
    }
    *result += "\n";

    *result += base::Utils::align(SIGNAL, max_size) +
        getParamInfo(dev::SIGNAL, dev) + "\n";
    *result += base::Utils::align(SNR, max_size) +
        getParamInfo(dev::SNR, dev) + "\n";
    *result += base::Utils::align(BER, max_size) +
        getParamInfo(dev::BER, dev) + "\n";
    *result += base::Utils::align(UNC, max_size) +
        getParamInfo(dev::UNC, dev) + "\n";
    *result += base::Utils::align(BANDWIDTH, max_size) +
        getParamInfo(dev::BANDWIDTH, dev) + " kHz\n";

    if (dev->getState() == dev::IDLE)
    {
        *result += base::Utils::align(ACTIVITY, max_size) +
            "idle\n";
    }
    else if (dev->getStringParam(dev::DVBACTIVITY) == dev::STREAMING)
    {
        *result += base::Utils::align(ACTIVITY, max_size) +
            "in use\n";

        *result += base::Utils::align(TUNED_CHANNELS, max_size);
        StringList list =
            getModule<DVB>()->getProcessor()->getChannelNames(dev);
        for (StringList::iterator i = list.begin(); i !=list.end(); i++)
        {
            if (i != list.begin())
                *result += ", ";
            *result += *i;
        }

        *result += "\n";
    }
    else if (dev->getStringParam(dev::DVBACTIVITY) == dev::SCANING)
    {
        *result += base::Utils::align(ACTIVITY, max_size) +
            "in use\n";
    }
}