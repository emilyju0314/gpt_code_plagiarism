const cli::ParameterVector
ScanStart::getCompletion(const cli::ParameterVector& setparams)
{
    cli::ParameterVector res;

    if (setparams.empty())
    {
        // possible source names
        IDevList list =
            getFactory()->getResources()->getResourceByType(dev::DVB_ALL);
        for (IDevList::iterator i = list.begin(); i != list.end(); i++)
        {
            const std::string source = (*i)->getStringParam(dev::SOURCE);
            if (!source.empty())
            {
                const std::string source_name =
                    dvb::Utils::getSourceName(getFactory(),
                                              source);
                if (std::find(res.begin(), res.end(), source_name) ==
                    res.end())
                {
                    res.push_back(source_name);
                }
            }
        }
    }
    else if (setparams.size() == 1)
    {
        IDevPtr dev = getDev(setparams[0]);
        // possible frequency table
        StringList list;
        if (dev->getStringParam(dev::TYPE) == dev::DVB_T)
        {
            list = base::Utils::getFiles(dir::SHARE + "/scan/dvb-t");
        }
        else if (dev->getStringParam(dev::TYPE) == dev::DVB_S)
        {
            list = base::Utils::getFiles(dir::SHARE + "/scan/dvb-s");
        }

        for (StringList::iterator i = list.begin(); i != list.end(); i++)
        {
            const std::string fname = base::Utils::getFileName(*i);
            if (std::find(res.begin(), res.end(), fname) == res.end())
            {
                res.push_back(fname);
            }
        }
    }

    return res;
}