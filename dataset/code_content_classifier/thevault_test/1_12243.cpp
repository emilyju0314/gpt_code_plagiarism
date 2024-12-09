size_t CommandLine::FindParameterIndex(const char* paramName) const
    {
        // compare all parameter names on a non-case sensitive way
        const auto foundParameter = AZStd::find_if(begin(m_parameters), end(m_parameters), [paramName](const Parameter& parameter)
        {
            return AzFramework::StringFunc::Equal(parameter.m_name, paramName, false /* no case */);
        });

        return foundParameter != end(m_parameters) ? AZStd::distance(begin(m_parameters), foundParameter) : InvalidIndex;
    }