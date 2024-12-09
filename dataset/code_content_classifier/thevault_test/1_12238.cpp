AZ::Vector4 CommandLine::GetValueAsVector4(const char* paramName, const AZ::Vector4& defaultValue) const
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
        return AzFramework::StringFunc::ToVector4(m_parameters[paramIndex].m_value.c_str());
    }