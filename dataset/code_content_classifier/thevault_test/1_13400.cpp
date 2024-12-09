const std::string RouteDelCommand::getRouteNames() const
{
    StringList names =
        getModule<Network>()->getValues(mod::SELECT_NOT_USED,
                                        mod::NAME);
    return base::Utils::convert2String(names, ", ");
}