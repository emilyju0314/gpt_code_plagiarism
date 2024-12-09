bool CommandLine::CheckIfHasValue(const char* paramName) const
    {
        // try to find the parameter index
        const size_t paramIndex = FindParameterIndex(paramName);
        if (paramIndex == InvalidIndex)
        {
            return false;
        }

        // return true the parameter has a value that is not empty
        return (m_parameters[paramIndex].m_value.empty() == false);
    }