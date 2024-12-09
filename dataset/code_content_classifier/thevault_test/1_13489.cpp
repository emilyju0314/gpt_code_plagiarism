const ParameterVector Utils::getCompletionRequest(const IMessagePtr& msg)
{
    BOOST_ASSERT(msg);
    BOOST_ASSERT(msg->getValue(msg::key::cli::TYPE) ==
                    msg::key::cli::TYPECOMPLETE);
    return getParams(msg);
}