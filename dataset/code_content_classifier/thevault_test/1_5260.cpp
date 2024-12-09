ts::tsp::PluginExecutor::RestartData::RestartData(const UStringVector& params, bool same, Report& rep) :
    report(rep),
    same_args(same),
    args(params),
    mutex(),
    condition(),
    completed(false)
{
}