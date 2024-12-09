NvDlaError Profile::getLoadable(const std::string &name, int index, ILoadable **i_loadable)
{
    bool nameSpecified = name.length() > 0;
    bool indexSpecified = index >= 0;

    NvDlaError e = NvDlaSuccess;
    if ( !i_loadable )
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadParameter);
    }

    *i_loadable = 0;

    if ( (nameSpecified && indexSpecified) || !(nameSpecified || indexSpecified) )
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_BadParameter, "must specify (only) one of index or name for loadable association with profile");
    }

    if ( nameSpecified )
    {
        if ( m_loadablesByName.find(name) != m_loadablesByName.end() )
        {
            *i_loadable = m_loadablesByName[name];
        }
        if ( debug() )
        {
            gLogInfo << "profile getLoadable looked for loadable with name " << name << endl;
        }
    }
    else if ( indexSpecified )
    {
        size_t u_index(index); // note sign checked above.
        if ( u_index < m_loadables.size() )
        {
            *i_loadable = m_loadables[u_index];
        }
    }


 fail:
    return e;
}