TEST_F(WeakAssetTest, DISABLED_WeakAsset_AssignmentOperator_CopiesDataAndIncrementsWeakRefCount)
    {
        TestAssetData testData;
        EXPECT_EQ(testData.GetWeakUseCount(), 0);

        // When transitioning the weak use count from 1 to 0, one assert will fire due to the asset manager not being initialized.
        AZ_TEST_START_TRACE_SUPPRESSION;
        {
            const AssetInternal::WeakAsset<TestAssetData> weakAsset(&testData, AssetLoadBehavior::PreLoad);
            EXPECT_EQ(testData.GetWeakUseCount(), 1);

            AssetInternal::WeakAsset<TestAssetData> weakAsset2;

            weakAsset2 = weakAsset;
            EXPECT_EQ(testData.GetWeakUseCount(), 2);
            EXPECT_EQ(weakAsset.GetId(), weakAsset2.GetId());
        }
        AZ_TEST_STOP_TRACE_SUPPRESSION(1);
    }