TEST_F(BufferTests, SetEmptyBuffer)
    {
        using namespace AZ;

        //Use a valid buffer for the buffer descriptor
        ExpectedBuffer validBuffer = CreateValidBuffer();

        RPI::BufferAssetCreator creator;

        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));

        // Setting nullptr should succeed if the buffer descriptor is valid
        // as the BufferAsset should be usable for R/W buffers
        creator.SetBuffer(nullptr, 0, validBuffer.m_bufferDescriptor);

        ASSERT_EQ(0, creator.GetErrorCount());
        ASSERT_EQ(0, creator.GetWarningCount());
    }