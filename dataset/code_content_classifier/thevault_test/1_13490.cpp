void Utils::setCompletionResponse(const IMessagePtr& msg,
                                  const ParameterVector& params)
{
    BOOST_ASSERT(msg);
    setParams(msg, params);
}