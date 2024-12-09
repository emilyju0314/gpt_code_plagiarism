int32 CommandLine::GetValueAsInt(const char* paramName, int32 defaultValue) const
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
            return defaultValue;
        }

        // return the parameter value
        return AzFramework::StringFunc::ToInt(m_parameters[paramIndex].m_value.c_str());
    }