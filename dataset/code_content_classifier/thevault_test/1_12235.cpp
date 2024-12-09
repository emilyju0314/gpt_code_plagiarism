float CommandLine::GetValueAsFloat(const char* paramName, float defaultValue) const
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
        return AzFramework::StringFunc::ToFloat(m_parameters[paramIndex].m_value.c_str());
    }