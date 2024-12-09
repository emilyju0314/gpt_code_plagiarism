TEST_F(BufferTests, SetViewDescriptorNoBegin)
    {
        using namespace AZ;

        ExpectedBuffer validBuffer = CreateValidBuffer();

        RPI::BufferAssetCreator creator;

        ErrorMessageFinder messageFinder("Begin() was not called", 2);
        
        creator.SetBufferViewDescriptor(validBuffer.m_viewDescriptor);

        //Ending the buffer here should also result in failure
        Data::Asset<RPI::BufferAsset> asset;
        ASSERT_FALSE(creator.End(asset));
        ASSERT_FALSE(asset.IsReady());
        ASSERT_EQ(asset.Get(), nullptr);
    }