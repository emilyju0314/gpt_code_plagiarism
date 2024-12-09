std::vector<BufferAndViewBindFlags> GenerateIncompatibleBufferBindFlagCombinations()
    {
        std::vector<BufferAndViewBindFlags> testCases;
        BufferAndViewBindFlags flags;

        flags.bufferBindFlags = RHI::BufferBindFlags::Constant;
        flags.viewBindFlags = RHI::BufferBindFlags::ShaderRead;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::ShaderRead;
        flags.viewBindFlags = RHI::BufferBindFlags::ShaderWrite;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::ShaderRead;
        flags.viewBindFlags = RHI::BufferBindFlags::ShaderReadWrite;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::ShaderWrite;
        flags.viewBindFlags = RHI::BufferBindFlags::ShaderRead;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::ShaderWrite;
        flags.viewBindFlags = RHI::BufferBindFlags::ShaderReadWrite;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::None;
        flags.viewBindFlags = RHI::BufferBindFlags::ShaderRead;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::None;
        flags.viewBindFlags = RHI::BufferBindFlags::ShaderWrite;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::None;
        flags.viewBindFlags = RHI::BufferBindFlags::ShaderReadWrite;
        testCases.push_back(flags);

        return testCases;
    }