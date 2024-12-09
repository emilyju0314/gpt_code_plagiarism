const ParameterVector Utils::getCompletionResponse(const IMessagePtr& msg)
{
    BOOST_ASSERT(msg);
    return getParams(msg);
}