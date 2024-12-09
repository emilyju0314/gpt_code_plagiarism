TEST_F(BundlingSystemComponentFixture, DISABLED_BundleSystemComponent_SharedCatalogName_Success)
    {
        // This bundle was built for PC but is generic and the test should work fine on other platforms
        // gamepropertioessmall_pc.pak has a smaller version of the gameproperties csv
        // gamepropertiesuserrequest_pc.pak has a bigger version of gameproperties and adds userrequest.csv
        const char testGamePropertiesAsset[] = "staticdata/test/gameproperties.csv";
        const char testUserRequestAsset[] = "staticdata/test/userrequest.csv";
        const char testGamePropertiesAssetPak[] = "test/bundle/gamepropertiessmall_pc.pak";
        const char testUserRequestAssetPak[] = "test/bundle/gamepropertiesuserrequest_pc.pak";

        EXPECT_FALSE(TestAssetId(testGamePropertiesAsset));
        EXPECT_FALSE(TestAssetId(testUserRequestAsset));
        EXPECT_TRUE(gEnv->pCryPak->OpenPack("@products@", testGamePropertiesAssetPak));
        EXPECT_TRUE(TestAssetId(testGamePropertiesAsset));
        EXPECT_FALSE(TestAssetId(testUserRequestAsset));
        AZ::Data::AssetId testAssetId;
        AZ::Data::AssetCatalogRequestBus::BroadcastResult(testAssetId, &AZ::Data::AssetCatalogRequestBus::Events::GetAssetIdByPath, testGamePropertiesAsset, AZ::Data::s_invalidAssetType, false);

        EXPECT_TRUE(testAssetId.IsValid());

        AZ::Data::AssetInfo assetInfo;
        AZ::Data::AssetCatalogRequestBus::BroadcastResult(assetInfo, &AZ::Data::AssetCatalogRequestBus::Events::GetAssetInfoById, testAssetId);
        EXPECT_NE(assetInfo.m_sizeBytes, 0);
        AZ::u64 assetSize1 = assetInfo.m_sizeBytes;

        EXPECT_TRUE(gEnv->pCryPak->OpenPack("@products@", testUserRequestAssetPak));
        EXPECT_TRUE(TestAssetId(testGamePropertiesAsset));
        EXPECT_TRUE(TestAssetId(testUserRequestAsset));

        AZ::Data::AssetCatalogRequestBus::BroadcastResult(assetInfo, &AZ::Data::AssetCatalogRequestBus::Events::GetAssetInfoById, testAssetId);
        AZ::u64 assetSize2 = assetInfo.m_sizeBytes;
        EXPECT_NE(assetSize1, assetSize2);

        EXPECT_TRUE(gEnv->pCryPak->ClosePack(testUserRequestAssetPak));
        EXPECT_TRUE(TestAssetId(testGamePropertiesAsset));
        EXPECT_FALSE(TestAssetId(testUserRequestAsset));
        AZ::Data::AssetCatalogRequestBus::BroadcastResult(assetInfo, &AZ::Data::AssetCatalogRequestBus::Events::GetAssetInfoById, testAssetId);
        EXPECT_EQ(assetSize1, assetInfo.m_sizeBytes);

        EXPECT_TRUE(gEnv->pCryPak->ClosePack(testGamePropertiesAssetPak));
        EXPECT_FALSE(TestAssetId(testGamePropertiesAsset));
        EXPECT_FALSE(TestAssetId(testUserRequestAsset));

        EXPECT_TRUE(gEnv->pCryPak->OpenPack("@products@", testUserRequestAssetPak));

        AZ::Data::AssetCatalogRequestBus::BroadcastResult(assetInfo, &AZ::Data::AssetCatalogRequestBus::Events::GetAssetInfoById, testAssetId);
        AZ::u64 assetSize3 = assetInfo.m_sizeBytes;
        EXPECT_EQ(assetSize3, assetSize2);

        EXPECT_TRUE(gEnv->pCryPak->OpenPack("@products@", testGamePropertiesAssetPak));
        AZ::Data::AssetCatalogRequestBus::BroadcastResult(assetInfo, &AZ::Data::AssetCatalogRequestBus::Events::GetAssetInfoById, testAssetId);
        AZ::u64 assetSize4 = assetInfo.m_sizeBytes;
        EXPECT_EQ(assetSize4, assetSize1);
    }