bool ModulesProxy::isLoaded(const std::string& id,
                            const Ice::Current& crn)
{
    return m_factory->isLoaded(id);
}