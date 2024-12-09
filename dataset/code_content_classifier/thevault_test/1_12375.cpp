AZStd::optional<size_t> ParseUnsignedIntegerOption(const AZStd::string& optionName, const AZ::CommandLine& cmd)
    {
        if (const auto numSwitchValues = cmd.GetNumSwitchValues(optionName);
            numSwitchValues)
        {
            AZ_TestImpact_Eval(
                numSwitchValues == 1,
                CommandLineOptionsException,
                AZStd::string::format("Unexpected number of parameters for %s option", optionName.c_str()));

            const auto strValue = cmd.GetSwitchValue(optionName, 0);
            size_t successfulParse = 0; // Will be non-zero if the parse was successful
            auto value = AZStd::stoul(strValue, &successfulParse, 0);

            AZ_TestImpact_Eval(
                successfulParse,
                CommandLineOptionsException,
                AZStd::string::format("Couldn't parse unsigned integer option value: %s", strValue.c_str()));

            return aznumeric_caster(value);
        }

        return AZStd::nullopt;
    }