TEST_F(BufferTests, SetEmptyBufferWithNonZeroSize)
    {
        using namespace AZ;

        //Use a valid buffer for the bufferDescriptor
        ExpectedBuffer validBuffer = CreateValidBuffer();

        RPI::BufferAssetCreator creator;

        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));
        creator.SetPoolAsset(CreateTestBufferPoolAsset());

        ErrorMessageFinder messageFinder("Initial buffer data was not provided but the initial size was non-zero.");
        messageFinder.AddIgnoredErrorMessage("Cannot continue building BufferAsset", true);
        
        creator.SetBuffer(nullptr, 1, validBuffer.m_bufferDescriptor);

        // Ending the buffer here should also result in failure
        Data::Asset<RPI::BufferAsset> asset;
        ASSERT_FALSE(creator.End(asset));
        ASSERT_FALSE(asset.IsReady());
        ASSERT_EQ(asset.Get(), nullptr);
    }