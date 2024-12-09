void AssetProcessingStateDataUnitTest::BuilderInfoTest(AssetProcessor::AssetDatabaseConnection* stateData)
{
    using BuilderInfoEntry = AzToolsFramework::AssetDatabase::BuilderInfoEntry;
    using BuilderInfoEntryContainer = AzToolsFramework::AssetDatabase::BuilderInfoEntryContainer;

    // empty database should have no builder info:

    BuilderInfoEntryContainer results;
    auto resultGatherer = [&results](BuilderInfoEntry&& element)
    {
        results.push_back(AZStd::move(element));
        return true; // returning false would stop iterating.  We want all results, so we return true.
    };
    
    UNIT_TEST_EXPECT_TRUE(stateData->QueryBuilderInfoTable(resultGatherer));
    UNIT_TEST_EXPECT_TRUE(results.empty());

    BuilderInfoEntryContainer newEntries;

    newEntries.emplace_back(BuilderInfoEntry(AzToolsFramework::AssetDatabase::InvalidEntryId, AZ::Uuid::CreateString("{648B7B06-27A3-42AC-897D-FA4557C28654}"), "Finger_Print"));
    newEntries.emplace_back(BuilderInfoEntry(AzToolsFramework::AssetDatabase::InvalidEntryId, AZ::Uuid::CreateString("{0B657D45-A5B0-485B-BF34-0E8779F9A482}"), "Finger_Print"));

    UNIT_TEST_EXPECT_TRUE(stateData->SetBuilderInfoTable(newEntries));
    // make sure each entry has a number assigned:
    UNIT_TEST_EXPECT_TRUE(newEntries[0].m_builderInfoID != AzToolsFramework::AssetDatabase::InvalidEntryId);
    UNIT_TEST_EXPECT_TRUE(newEntries[1].m_builderInfoID != AzToolsFramework::AssetDatabase::InvalidEntryId);

    UNIT_TEST_EXPECT_TRUE(stateData->QueryBuilderInfoTable(resultGatherer));
    UNIT_TEST_EXPECT_TRUE(results.size() == 2);
    UNIT_TEST_EXPECT_TRUE(results[0].m_builderInfoID != AzToolsFramework::AssetDatabase::InvalidEntryId);
    UNIT_TEST_EXPECT_TRUE(results[1].m_builderInfoID != AzToolsFramework::AssetDatabase::InvalidEntryId);

    // they could be in any order, so fix that first:
    bool isInCorrectOrder = (results[0].m_builderInfoID == newEntries[0].m_builderInfoID) && (results[1].m_builderInfoID == newEntries[1].m_builderInfoID);
    bool isInReverseOrder = (results[1].m_builderInfoID == newEntries[0].m_builderInfoID) && (results[0].m_builderInfoID == newEntries[1].m_builderInfoID);

    UNIT_TEST_EXPECT_TRUE(isInCorrectOrder || isInReverseOrder);

    if (isInReverseOrder)
    {
        BuilderInfoEntry temp = results[0];
        results[0] = results[1];
        results[1] = temp;
    }

    for (size_t idx = 0; idx < 2; ++idx)
    {
        UNIT_TEST_EXPECT_TRUE(results[idx].m_builderUuid == newEntries[idx].m_builderUuid);
        UNIT_TEST_EXPECT_TRUE(results[idx].m_builderInfoID == newEntries[idx].m_builderInfoID);
        UNIT_TEST_EXPECT_TRUE(results[idx].m_analysisFingerprint == newEntries[idx].m_analysisFingerprint);
    }

    // now REPLACE the entries with fewer and make sure it actually chops it down and also replaces the fields.
    newEntries.clear();
    results.clear();
    newEntries.emplace_back(BuilderInfoEntry(AzToolsFramework::AssetDatabase::InvalidEntryId, AZ::Uuid::CreateString("{8863194A-BCB2-4A4C-A7D9-4E90D68814D4}"), "Finger_Print2"));
    UNIT_TEST_EXPECT_TRUE(stateData->SetBuilderInfoTable(newEntries));
    // make sure each entry has a number assigned:
    UNIT_TEST_EXPECT_TRUE(newEntries[0].m_builderInfoID != AzToolsFramework::AssetDatabase::InvalidEntryId);
    UNIT_TEST_EXPECT_TRUE(stateData->QueryBuilderInfoTable(resultGatherer));
    UNIT_TEST_EXPECT_TRUE(results.size() == 1);
    UNIT_TEST_EXPECT_TRUE(results[0].m_builderInfoID != AzToolsFramework::AssetDatabase::InvalidEntryId);
    UNIT_TEST_EXPECT_TRUE(results[0].m_builderUuid == newEntries[0].m_builderUuid);
    UNIT_TEST_EXPECT_TRUE(results[0].m_builderInfoID == newEntries[0].m_builderInfoID);
    UNIT_TEST_EXPECT_TRUE(results[0].m_analysisFingerprint == newEntries[0].m_analysisFingerprint);
}