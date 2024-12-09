void CommandLine::SetCommandLine(const AZStd::string& commandLine)
    {
        // get rid of previous parameters
        m_parameters.clear();

        // extract all parameters
        AZStd::string paramName;
        AZStd::string paramValue;
        size_t offset = 0;
        while (ExtractNextParam(commandLine, paramName, paramValue, &offset))
        {
            // if the parameter name is empty then it isn't a real parameter
            if (!paramName.empty())
            {
                m_parameters.emplace_back(Parameter {paramName, paramValue});
            }
        }
    }