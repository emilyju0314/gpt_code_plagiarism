TEST_F(BufferTests, SetBufferTooMuchInitialData)
    {
        using namespace AZ;

        //Use a valid buffer for the buffer data
        ExpectedBuffer validBuffer = CreateValidBuffer();

        const size_t invalidInitialDataSize = validBuffer.m_bufferDescriptor.m_byteCount + 1;

        RPI::BufferAssetCreator creator;

        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));
        creator.SetPoolAsset(CreateTestBufferPoolAsset());

        ErrorMessageFinder messageFinder("initialSize is larger than the total size in the descriptor.");
        messageFinder.AddIgnoredErrorMessage("Cannot continue building BufferAsset", true);
        
        creator.SetBuffer(validBuffer.m_data.data(), invalidInitialDataSize, validBuffer.m_bufferDescriptor);

        // Ending the buffer here should also result in failure
        Data::Asset<RPI::BufferAsset> asset;
        ASSERT_FALSE(creator.End(asset));
        ASSERT_FALSE(asset.IsReady());
        ASSERT_EQ(asset.Get(), nullptr);
    }