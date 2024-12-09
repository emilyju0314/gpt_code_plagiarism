TEST_F(SettingsRegistryBuilderTest, SettingsExporter_ExportRegistryToJson_ProducesIdenticalJsonToRegularWriter)
    {
        static constexpr char json[] =
            R"( {
                    "TestValues":
                    {
                        "BoolTrue": true,
                        "BoolFalse": false,
                        "Integer": 42,
                        "Double": 42.0,
                        "String": "hello",
                        "Array": [ null, true, false, 42, 42.0, "hello", { "Field": 42 }, [ 42, 42.0 ] ]
                    }
                })";

        rapidjson::Document document;
        document.Parse(json);
        ASSERT_FALSE(document.HasParseError());
        rapidjson::StringBuffer jsonOutputBuffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(jsonOutputBuffer);
        document.FindMember("TestValues")->value.Accept(writer);

        AZ::SettingsRegistryImpl registry;
        ASSERT_TRUE(registry.MergeSettings(json, AZ::SettingsRegistryInterface::Format::JsonMergePatch));
        rapidjson::StringBuffer registryOutputBuffer;
        AZStd::vector<AZStd::string> excludes;
        SettingsRegistryBuilder::SettingsExporter exporter(registryOutputBuffer, excludes);
        registry.Visit(exporter, "/TestValues");
        ASSERT_TRUE(exporter.Finalize());

        EXPECT_EQ(jsonOutputBuffer.GetLength(), registryOutputBuffer.GetLength());
        EXPECT_STREQ(jsonOutputBuffer.GetString(), registryOutputBuffer.GetString());
    }