void CommandLine::GetValue(const char* paramName, const char* defaultValue, AZStd::string* outResult) const
    {
        // try to find the parameter index
        const size_t paramIndex = FindParameterIndex(paramName);
        if (paramIndex == InvalidIndex)
        {
            *outResult = defaultValue;
            return;
        }

        // return the default value if the parameter value is empty
        if (m_parameters[paramIndex].m_value.empty())
        {
            *outResult = defaultValue;
            return;
        }

        // return the parameter value
        *outResult = m_parameters[paramIndex].m_value;
    }