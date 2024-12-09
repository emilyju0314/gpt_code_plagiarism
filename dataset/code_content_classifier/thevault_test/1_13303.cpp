const cli::ParameterVector
StatCommand::getCompletion(const cli::ParameterVector& setparams)
{
    cli::ParameterVector res;
    if (setparams.empty())
    {
        res.push_back(STAT_COMMAND_PARAM_INPUT);
        res.push_back(STAT_COMMAND_PARAM_OUTPUT);
    }

    return res;
}