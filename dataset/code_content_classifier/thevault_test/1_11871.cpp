TEST_F(BufferTests, BufferSystem_GetCommonPools_Success)
    {
        using namespace AZ;

        for (uint32_t type = 0; type < static_cast<uint32_t>(RPI::CommonBufferPoolType::Count); type++)
        {
            ASSERT_NE(RPI::BufferSystemInterface::Get()->GetCommonBufferPool((RPI::CommonBufferPoolType)type).get(), nullptr);
        }
    }