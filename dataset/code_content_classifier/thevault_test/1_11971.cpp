TEST_F(ModelTests, CreateModelNoLods)
    {
        using namespace AZ;

        RPI::ModelAssetCreator creator;

        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));

        ErrorMessageFinder messageFinder("No valid ModelLodAssets have been added to this ModelAsset.");

        // Since there are no LODs set on this model it
        // we should not be able to successfully end the creator
        Data::Asset<RPI::ModelAsset> asset;
        ASSERT_FALSE(creator.End(asset));
        ASSERT_FALSE(asset.IsReady());
        ASSERT_EQ(asset.Get(), nullptr);
    }