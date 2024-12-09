const ParameterVector Utils::getCommands(const std::string& data)
{
    const ParameterVector commands = base::Utils::split(data, " \r\n");
    return commands;
}