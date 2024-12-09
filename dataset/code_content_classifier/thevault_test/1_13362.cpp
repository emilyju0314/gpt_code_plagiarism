const cli::ParameterVector
StationAddCommand::getCompletion(const cli::ParameterVector& setparams)
{
    cli::ParameterVector res;

    if (setparams.empty())
    {
        const StringList names = getNotAssignedChannels();
        std::copy(names.begin(), names.end(),
                  std::back_inserter(res));
    }
    else if (setparams.size() == 1)
    {
        const StringList names = getNotAssignedRoutes();
        std::copy(names.begin(), names.end(),
                  std::back_inserter(res));
    }
    else if (setparams.size() == 2)
    {
        for (int i = 0; i < 10; i++)
        {
            res.push_back(boost::lexical_cast<std::string>(i));
        }
    }

    return res;
}