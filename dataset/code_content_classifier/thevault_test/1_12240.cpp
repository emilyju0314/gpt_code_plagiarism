AZ::Vector3 CommandLine::GetValueAsVector3(const char* paramName, Command* command) const
    {
        // try to find the parameter index
        const size_t paramIndex = FindParameterIndex(paramName);
        if (paramIndex == InvalidIndex)
        {
            AZStd::string result;
            if (command->GetOriginalCommand()->GetSyntax().GetDefaultValue(paramName, result))
            {
                return AzFramework::StringFunc::ToVector3(result.c_str());
            }
            else
            {
                return AZ::Vector3(0.0f, 0.0f, 0.0);
            }
        }

        // return the parameter value
        return AzFramework::StringFunc::ToVector3(m_parameters[paramIndex].m_value.c_str());
    }