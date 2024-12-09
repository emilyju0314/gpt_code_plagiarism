TEST_F(BufferTests, BufferAssetCreation_NoInitialData_Success)
    {
        using namespace AZ;

        ExpectedBuffer bufferInfo = CreateValidBuffer();

        RPI::BufferAssetCreator creator;
        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));
        creator.SetPoolAsset(CreateTestBufferPoolAsset());
        creator.SetBufferViewDescriptor(bufferInfo.m_viewDescriptor);

        // empty initial data
        creator.SetBuffer(nullptr, 0, bufferInfo.m_bufferDescriptor);

        Data::Asset<RPI::BufferAsset> asset;

        EXPECT_TRUE(creator.End(asset));
        EXPECT_TRUE(asset.IsReady());
        EXPECT_NE(asset.Get(), nullptr);
    }