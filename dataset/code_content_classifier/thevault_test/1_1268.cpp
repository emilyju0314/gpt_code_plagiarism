void onCtorParam(
    XmlRpc::XmlRpcValue prev,
    XmlRpc::XmlRpcValue curr)
{
    if (g_shouldNotCall) {
        ADD_FAILURE() << "Unexpected setting of parameter" << std::endl;
    }
    else if (g_paramSet)
    {
        // Only the current value should be valid
        EXPECT_FALSE(prev.valid());
        EXPECT_TRUE(curr.valid());
        testParam(g_currentParamType, g_currentValue, curr);
    }
    else if (g_paramDeleted)
    {
        // Only the previous value should be valid
        EXPECT_TRUE(prev.valid());
        EXPECT_FALSE(curr.valid());
        testParam(g_previousParamType, g_previousValue, prev);
    }
    else
    {
        // Previous and current values should both be valid
        EXPECT_TRUE(prev.valid());
        EXPECT_TRUE(curr.valid());
        testParam(g_currentParamType, g_currentValue, curr);
        testParam(g_previousParamType, g_previousValue, prev);
    }
}