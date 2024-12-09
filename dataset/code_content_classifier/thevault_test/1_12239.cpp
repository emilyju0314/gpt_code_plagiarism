void CommandLine::GetValue(const char* paramName, Command* command, AZStd::string* outResult) const
    {
        // try to find the parameter index
        const size_t paramIndex = FindParameterIndex(paramName);
        if (paramIndex == InvalidIndex)
        {
            command->GetOriginalCommand()->GetSyntax().GetDefaultValue(paramName, *outResult);
            return;
        }

        // return the parameter value
        *outResult = m_parameters[paramIndex].m_value;
    }