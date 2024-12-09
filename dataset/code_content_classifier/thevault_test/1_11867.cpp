TEST_F(BufferTests, SetBufferWithZeroSize)
    {
        using namespace AZ;

        //Use a valid buffer for the bufferDescriptor
        ExpectedBuffer validBuffer = CreateValidBuffer();

        RPI::BufferAssetCreator creator;

        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));
        creator.SetPoolAsset(CreateTestBufferPoolAsset());

        ErrorMessageFinder messageFinder("Initial buffer data was not null but the initial size was zero.");
        messageFinder.AddIgnoredErrorMessage("Cannot continue building BufferAsset", true);
        
        creator.SetBuffer(validBuffer.m_data.data(), 0, validBuffer.m_bufferDescriptor);

        // Ending the buffer here should also result in failure
        Data::Asset<RPI::BufferAsset> asset;
        ASSERT_FALSE(creator.End(asset));
        ASSERT_FALSE(asset.IsReady());
        ASSERT_EQ(asset.Get(), nullptr);
    }