AZStd::optional<RepoPath> ParsePathOption(const AZStd::string& optionName, const AZ::CommandLine& cmd)
    {  
        if (const auto numSwitchValues = cmd.GetNumSwitchValues(optionName);
            numSwitchValues)
        {
            AZ_TestImpact_Eval(
                numSwitchValues == 1,
                CommandLineOptionsException,
                AZStd::string::format("Unexpected number of parameters for %s option", optionName.c_str()));

            const auto value = cmd.GetSwitchValue(optionName, 0);
            AZ_TestImpact_Eval(
                !value.empty(),
                CommandLineOptionsException,
                AZStd::string::format("%s file option value is empty", optionName.c_str()));

            return value;
        }

        return AZStd::nullopt;
    }