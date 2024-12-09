TEST_F(BufferTests, Buffer_Resize_Success)
    {
        using namespace AZ;
        ExpectedBuffer bufferInfo = CreateValidBuffer();

        RPI::BufferAssetCreator creator;
        creator.Begin(Data::AssetId(AZ::Uuid::CreateRandom()));
        creator.SetBufferViewDescriptor(bufferInfo.m_viewDescriptor);
        creator.SetBuffer(nullptr, 0, bufferInfo.m_bufferDescriptor);
        creator.SetUseCommonPool(RPI::CommonBufferPoolType::ReadOnly);

        Data::Asset<RPI::BufferAsset> asset;
        creator.End(asset);

        uint64_t initialSize = bufferInfo.m_bufferDescriptor.m_byteCount;
        Data::Instance<RPI::Buffer> bufferInst = RPI::Buffer::FindOrCreate(asset);
        ASSERT_NE(bufferInst.get(), nullptr);
        EXPECT_EQ(bufferInst->GetBufferSize(), initialSize);

        // size up
        uint64_t newSize = 2 * initialSize;
        bufferInst->Resize(newSize);
        ASSERT_NE(bufferInst.get(), nullptr);
        EXPECT_EQ(bufferInst->GetBufferSize(), newSize);
        EXPECT_EQ(bufferInst->GetBufferViewDescriptor().m_elementCount*bufferInst->GetBufferViewDescriptor().m_elementSize, newSize);

        // size down
        newSize = initialSize/2;
        bufferInst->Resize(newSize);
        ASSERT_NE(bufferInst.get(), nullptr);
        EXPECT_EQ(bufferInst->GetBufferSize(), newSize);
        EXPECT_EQ(bufferInst->GetBufferViewDescriptor().m_elementCount*bufferInst->GetBufferViewDescriptor().m_elementSize, newSize);
    }