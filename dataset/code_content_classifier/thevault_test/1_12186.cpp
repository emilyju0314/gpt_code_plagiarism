TEST_F(WeakAssetTest, DISABLED_WeakAsset_ConstructionAndDestruction_UpdatesAssetDataWeakRefCount)
    {
        TestAssetData testData;
        EXPECT_EQ(testData.GetWeakUseCount(), 0);

        // When transitioning the weak use count from 1 to 0, one assert will fire due to the asset manager not being initialized.
        AZ_TEST_START_TRACE_SUPPRESSION;
        {
            AssetInternal::WeakAsset<TestAssetData> weakAsset(&testData, AssetLoadBehavior::Default);
            EXPECT_EQ(testData.GetWeakUseCount(), 1);
        }
        AZ_TEST_STOP_TRACE_SUPPRESSION(1);

        EXPECT_EQ(testData.GetWeakUseCount(), 0);
    }