AZStd::optional<AZStd::chrono::milliseconds> ParseSecondsOption(const AZStd::string& optionName, const AZ::CommandLine& cmd)
    {
        if (const auto option = ParseUnsignedIntegerOption(optionName, cmd);
            option.has_value())
        {
            return AZStd::chrono::seconds(option.value());
        }

        return AZStd::nullopt;
    }