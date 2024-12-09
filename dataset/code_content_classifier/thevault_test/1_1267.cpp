void testParam(
    std::string& paramType,
    boost::any& paramValue,
    XmlRpc::XmlRpcValue& value)
{
    if (paramType == "int")
    {
        EXPECT_EQ(
            boost::any_cast<int>(paramValue),
            static_cast<int>(value));
    }
    else if (paramType == "string")
    {
        EXPECT_EQ(
            boost::any_cast<std::string>(paramValue),
            static_cast<std::string>(value));
    }
    else if (paramType == "double")
    {
        EXPECT_EQ(
            boost::any_cast<double>(paramValue),
            static_cast<double>(value));
    }
    else if (paramType == "bool")
    {
        EXPECT_EQ(
            boost::any_cast<bool>(paramValue),
            static_cast<bool>(value));
    }
    else if (paramType == "StringVector")
    {
        StringVector list1 = boost::any_cast<StringVector>(paramValue);
        ASSERT_EQ(value.getType(), XmlRpc::XmlRpcValue::TypeArray);

        // All list items should be identical
        ASSERT_EQ(list1.size(), value.size());
        for (int i = 0; i < list1.size(); ++i) {
            EXPECT_EQ(list1[i], static_cast<std::string>(value[i]));
        }
    }
    else if (paramType == "StringMap")
    {
        StringMap map1 = boost::any_cast<StringMap>(paramValue);
        ASSERT_EQ(value.getType(), XmlRpc::XmlRpcValue::TypeStruct);

        // All map items should be identical
        ASSERT_EQ(map1.size(), value.size());
        XmlRpc::XmlRpcValue::iterator it;
        for (it = value.begin(); it != value.end(); it++)
        {
            const std::string& key = it->first;
            XmlRpc::XmlRpcValue& data = it->second;

            ASSERT_TRUE(map1.count(key) > 0);
            ASSERT_EQ(map1[key], static_cast<std::string>(data));
        }
    }
}