AZ::Vector4 CommandLine::GetValueAsVector4(const char* paramName, Command* command) const
    {
        // try to find the parameter index
        const size_t paramIndex = FindParameterIndex(paramName);
        if (paramIndex == InvalidIndex)
        {
            AZStd::string result;
            if (command->GetOriginalCommand()->GetSyntax().GetDefaultValue(paramName, result))
            {
                return AzFramework::StringFunc::ToVector4(result.c_str());
            }
            else
            {
                return AZ::Vector4(0.0f, 0.0f, 0.0f, 1.0f);
            }
        }

        // return the parameter value
        return AzFramework::StringFunc::ToVector4(m_parameters[paramIndex].m_value.c_str());
    }