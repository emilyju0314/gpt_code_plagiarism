const cli::ParameterVector
StationDelCommand::getCompletion(const cli::ParameterVector& setparams)
{
    cli::ParameterVector res;

    if (setparams.empty())
    {
        const StringList names = getAssignedChannels();
        std::copy(names.begin(), names.end(),
                  std::back_inserter(res));
    }

    return res;
}