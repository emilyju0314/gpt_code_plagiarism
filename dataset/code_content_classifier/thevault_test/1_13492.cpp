const CommandMode Utils::getCommandMode(const IMessagePtr& msg)
{
    if (msg->getValue(msg::key::cli::TYPE) == msg::key::cli::TYPECOMPLETE)
        return GETCOMPLETION;
    if (msg->getValue(msg::key::cli::TYPE) == msg::key::cli::TYPEPROCESS)
        return PROCESS;

    return UNKNOWN;
}