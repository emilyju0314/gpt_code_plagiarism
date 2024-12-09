TEST_F(BufferTests, BufferSystem_CreateDuplicatedNamedBuffers_Success)
    {
        using namespace AZ;

        ExpectedBuffer bufferInfo = CreateValidBuffer();

        RPI::CommonBufferDescriptor desc;
        desc.m_poolType = RPI::CommonBufferPoolType::ReadOnly;
        desc.m_bufferName = "Buffer1";
        desc.m_byteCount = bufferInfo.m_bufferDescriptor.m_byteCount;

        Data::Instance<RPI::Buffer> bufferInst = RPI::BufferSystemInterface::Get()->CreateBufferFromCommonPool(desc);
        // buffer created
        EXPECT_NE(bufferInst.get(), nullptr);
                
        Data::Instance<RPI::Buffer> bufferInst2 = RPI::BufferSystemInterface::Get()->CreateBufferFromCommonPool(desc);
        // buffer created
        EXPECT_NE(bufferInst2.get(), nullptr);
    }