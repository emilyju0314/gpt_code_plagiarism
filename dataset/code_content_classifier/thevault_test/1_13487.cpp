const cli::ParameterVector
InputDelCommand::getCompletion(const cli::ParameterVector& setparams)
{
    cli::ParameterVector res;
    if (setparams.empty())
    {
        InputInfoList infos = getModule<Streamer>()->getInputInfo();
        for (InputInfoList::iterator i = infos.begin(); i != infos.end(); i++)
        {
            res.push_back((*i)->getRouteInfo()->getName());
        }
    }
    return res;
}