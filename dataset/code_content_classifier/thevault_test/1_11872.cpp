TEST_F(BufferTests, BufferSystem_CreateDuplicatedNamedBufferEnableUniqueName_Fail)
    {
        using namespace AZ;

        ExpectedBuffer bufferInfo = CreateValidBuffer();

        RPI::CommonBufferDescriptor desc;
        desc.m_poolType = RPI::CommonBufferPoolType::ReadOnly;
        desc.m_bufferName = "Buffer1";
        desc.m_byteCount = bufferInfo.m_bufferDescriptor.m_byteCount;
        desc.m_isUniqueName = true;

        Data::Instance<RPI::Buffer> bufferInst = RPI::BufferSystemInterface::Get()->CreateBufferFromCommonPool(desc);
        // buffer created
        EXPECT_NE(bufferInst.get(), nullptr);

        AZ_TEST_START_ASSERTTEST;
        Data::Instance<RPI::Buffer> bufferInst2 = RPI::BufferSystemInterface::Get()->CreateBufferFromCommonPool(desc);
        AZ_TEST_STOP_ASSERTTEST(1);
        // buffer NOT created
        EXPECT_EQ(bufferInst2.get(), nullptr);
    }