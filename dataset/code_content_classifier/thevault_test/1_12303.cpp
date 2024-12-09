TEST_F(MaterialPropertySerializerTests, LoadAndStoreJson_DefaultGeneralData)
    {
        // Note we are keeping id and type because they are required fields
        const AZStd::string inputJson = R"(
        {
            "name": "testProperty",
            "type": "Float"
        }
        )";

        MaterialTypeSourceData::PropertyDefinition propertyData;
        JsonTestResult loadResult = LoadTestDataFromJson(propertyData, inputJson);

        EXPECT_EQ(AZ::JsonSerializationResult::Tasks::ReadField, loadResult.m_jsonResultCode.GetTask());
        EXPECT_EQ(AZ::JsonSerializationResult::Processing::Completed, loadResult.m_jsonResultCode.GetProcessing());
        EXPECT_EQ(AZ::JsonSerializationResult::Outcomes::PartialDefaults, loadResult.m_jsonResultCode.GetOutcome());

        EXPECT_TRUE(propertyData.m_displayName.empty());
        EXPECT_TRUE(propertyData.m_description.empty());

        EXPECT_TRUE(loadResult.ContainsMessage("/name", "Success"));
        EXPECT_TRUE(loadResult.ContainsMessage("/type", "Success"));

        EXPECT_FALSE(loadResult.ContainsOutcome(JsonSerializationResult::Outcomes::Skipped));

        TestStoreToJson(propertyData, inputJson);
    }