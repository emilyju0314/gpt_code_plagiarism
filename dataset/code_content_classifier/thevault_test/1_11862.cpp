TEST_F(BufferTests, SetBufferNoBegin)
    {
        using namespace AZ;

        ExpectedBuffer validBuffer = CreateValidBuffer();
        const size_t bufferSize = validBuffer.m_bufferDescriptor.m_byteCount;

        RPI::BufferAssetCreator creator;

        ErrorMessageFinder messageFinder("Begin() was not called", 2);

        creator.SetBuffer(validBuffer.m_data.data(), bufferSize, validBuffer.m_bufferDescriptor);

        //Ending the buffer here should also result in failure
        Data::Asset<RPI::BufferAsset> asset;
        ASSERT_FALSE(creator.End(asset));
        ASSERT_FALSE(asset.IsReady());
        ASSERT_EQ(asset.Get(), nullptr);
    }