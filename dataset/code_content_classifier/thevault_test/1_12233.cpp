void CommandLine::GetValue(const char* paramName, const char* defaultValue, AZStd::string& outResult) const
    {
        // Try to find the parameter index.
        const size_t paramIndex = FindParameterIndex(paramName);
        if (paramIndex == InvalidIndex)
        {
            outResult = defaultValue;
            return;
        }

        // Return the default value if the parameter value is empty.
        if (m_parameters[paramIndex].m_value.empty())
        {
            outResult = defaultValue;
            return;
        }

        // Return the actual parameter value.
        outResult = m_parameters[paramIndex].m_value.c_str();
    }