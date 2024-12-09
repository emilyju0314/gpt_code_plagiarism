bool CommandLine::GetValueAsBool(const char* paramName, bool defaultValue) const
    {
        // try to find the parameter index
        const size_t paramIndex = FindParameterIndex(paramName);
        if (paramIndex == InvalidIndex)
        {
            return defaultValue;
        }

        // return the default value if the parameter value is empty
        if (m_parameters[paramIndex].m_value.empty())
        {
            return true;
        }

        // return the parameter value
        return AzFramework::StringFunc::ToBool(m_parameters[paramIndex].m_value.c_str());
    }