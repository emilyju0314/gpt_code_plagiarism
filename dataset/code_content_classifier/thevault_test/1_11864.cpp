TEST_F(BufferTests, SetInvalidBufferDescriptor)
    {
        using namespace AZ;

        //Use a valid buffer for the buffer data
        ExpectedBuffer validBuffer = CreateValidBuffer();
        const size_t bufferSize = validBuffer.m_bufferDescriptor.m_byteCount;

        RHI::BufferDescriptor invalidBufferDescriptor;
        invalidBufferDescriptor.m_byteCount = 0;

        RPI::BufferAssetCreator creator;

        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));
        creator.SetPoolAsset(CreateTestBufferPoolAsset());

        ErrorMessageFinder messageFinder("Size of the buffer in the descriptor was 0");
        messageFinder.AddIgnoredErrorMessage("Cannot continue building BufferAsset", true);
        
        creator.SetBuffer(validBuffer.m_data.data(), bufferSize, invalidBufferDescriptor);
        

        // Ending the buffer here should also result in failure
        Data::Asset<RPI::BufferAsset> asset;
        ASSERT_FALSE(creator.End(asset));
        ASSERT_FALSE(asset.IsReady());
        ASSERT_EQ(asset.Get(), nullptr);
    }