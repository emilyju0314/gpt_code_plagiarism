TEST_F(BufferTests, BufferAssetCreation_NoPoolSpecified_Fail)
    {
        using namespace AZ;

        ExpectedBuffer bufferInfo = CreateValidBuffer();

        RPI::BufferAssetCreator creator;
        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));
        creator.SetBufferViewDescriptor(bufferInfo.m_viewDescriptor);
        creator.SetBuffer(nullptr, 0, bufferInfo.m_bufferDescriptor);

        Data::Asset<RPI::BufferAsset> asset;
        
        // Failed
        ErrorMessageFinder messageFinder("BufferAssetCreator::ValidateBuffer Failed; need valid pool asset or select a valid common pool.", 1);
        ASSERT_FALSE(creator.End(asset));
        EXPECT_FALSE(asset.IsReady());
        EXPECT_EQ(asset.Get(), nullptr);
    }