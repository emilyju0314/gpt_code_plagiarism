const cli::ParameterVector
RouteDelCommand::getCompletion(const cli::ParameterVector& setparams)
{
    cli::ParameterVector res;
    if (setparams.empty())
    {
        StringList list =
            getModule<Network>()->getValues(mod::SELECT_NOT_USED,
                                            mod::NAME);
        std::copy(list.begin(), list.end(),
                  std::back_inserter(res));
    }

    return res;
}