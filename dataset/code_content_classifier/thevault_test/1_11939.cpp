TEST_F(SettingsRegistryTest, GetType_TypeForObject_TypeMatchesProvidedType)
    {
        ASSERT_TRUE(m_registry->MergeSettings(R"({ "Object": { "Value": 42 } })", AZ::SettingsRegistryInterface::Format::JsonMergePatch));
        AZStd::string_view testPath = "/Object";
        EXPECT_EQ(AZ::SettingsRegistryImpl::Type::Object, m_registry->GetType(testPath));
    }