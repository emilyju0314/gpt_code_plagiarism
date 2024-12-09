std::vector<BufferAndViewBindFlags> GenerateCompatibleBufferBindFlagCombinations()
    {
        std::vector<BufferAndViewBindFlags> testCases;
        BufferAndViewBindFlags flags;

        // When the buffer bind flags are equal to or a superset of the buffer view bind flags, the view is compatible with the buffer
        flags.bufferBindFlags = RHI::BufferBindFlags::Constant;
        flags.viewBindFlags = RHI::BufferBindFlags::Constant;
        testCases.push_back(flags); 
        
        flags.bufferBindFlags = RHI::BufferBindFlags::ShaderReadWrite;
        flags.viewBindFlags = RHI::BufferBindFlags::ShaderRead;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::ShaderReadWrite;
        flags.viewBindFlags = RHI::BufferBindFlags::ShaderWrite;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::ShaderReadWrite;
        flags.viewBindFlags = RHI::BufferBindFlags::ShaderReadWrite;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::ShaderRead;
        flags.viewBindFlags = RHI::BufferBindFlags::ShaderRead;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::ShaderWrite;
        flags.viewBindFlags = RHI::BufferBindFlags::ShaderWrite;
        testCases.push_back(flags);

        // When the buffer view bind flags are None, they have no effect and should work with any bind flag used by the buffer
        flags.bufferBindFlags = RHI::BufferBindFlags::ShaderRead;
        flags.viewBindFlags = RHI::BufferBindFlags::None;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::ShaderWrite;
        flags.viewBindFlags = RHI::BufferBindFlags::None;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::ShaderReadWrite;
        flags.viewBindFlags = RHI::BufferBindFlags::None;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::None;
        flags.viewBindFlags = RHI::BufferBindFlags::None;
        testCases.push_back(flags);

        flags.bufferBindFlags = RHI::BufferBindFlags::Constant;
        flags.viewBindFlags = RHI::BufferBindFlags::None;
        testCases.push_back(flags);

        return testCases;
    }