TEST_F(MaterialPropertySerializerTests, LoadAndStoreJson_GeneralData)
    {
        const AZStd::string inputJson = R"(
        {
            "name": "testProperty",
            "displayName": "Test Property",
            "description": "This is a property description",
            "type": "Float"
        }
        )";

        MaterialTypeSourceData::PropertyDefinition propertyData;
        JsonTestResult loadResult = LoadTestDataFromJson(propertyData, inputJson);

        EXPECT_EQ(AZ::JsonSerializationResult::Tasks::ReadField, loadResult.m_jsonResultCode.GetTask());
        EXPECT_EQ(AZ::JsonSerializationResult::Processing::Completed, loadResult.m_jsonResultCode.GetProcessing());
        EXPECT_EQ(AZ::JsonSerializationResult::Outcomes::PartialDefaults, loadResult.m_jsonResultCode.GetOutcome());

        EXPECT_EQ("testProperty", propertyData.m_name);
        EXPECT_EQ("Test Property", propertyData.m_displayName);
        EXPECT_EQ("This is a property description", propertyData.m_description);
        EXPECT_EQ(MaterialPropertyDataType::Float, propertyData.m_dataType);

        EXPECT_TRUE(loadResult.ContainsMessage("/name", "Success"));
        EXPECT_TRUE(loadResult.ContainsMessage("/displayName", "Success"));
        EXPECT_TRUE(loadResult.ContainsMessage("/description", "Success"));
        EXPECT_TRUE(loadResult.ContainsMessage("/type", "Success"));

        EXPECT_FALSE(loadResult.ContainsOutcome(JsonSerializationResult::Outcomes::Skipped));

        TestStoreToJson(propertyData, inputJson);
    }