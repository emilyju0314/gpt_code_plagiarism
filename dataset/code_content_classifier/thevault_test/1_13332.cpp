const cli::ParameterVector
InfoCommand::getCompletion(const cli::ParameterVector& setparams)
{
    cli::ParameterVector result;

    if (setparams.empty())
    {
        result.push_back(cli::ALL);
        StringList list = getDevNames();
        std::copy(list.begin(), list.end(),
                  std::back_inserter(result));
    }

    return result;
}