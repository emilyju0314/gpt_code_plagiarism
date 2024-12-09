std::vector<ImageAndViewBindFlags> GenerateIncompatibleImageBindFlagCombinations()
    {
        std::vector<ImageAndViewBindFlags> testCases;
        ImageAndViewBindFlags flags;

        flags.imageBindFlags = RHI::ImageBindFlags::Color;
        flags.viewBindFlags = RHI::ImageBindFlags::ShaderRead;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::ShaderRead;
        flags.viewBindFlags = RHI::ImageBindFlags::ShaderWrite;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::ShaderRead;
        flags.viewBindFlags = RHI::ImageBindFlags::ShaderReadWrite;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::ShaderWrite;
        flags.viewBindFlags = RHI::ImageBindFlags::ShaderRead;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::ShaderWrite;
        flags.viewBindFlags = RHI::ImageBindFlags::ShaderReadWrite;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::None;
        flags.viewBindFlags = RHI::ImageBindFlags::ShaderRead;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::None;
        flags.viewBindFlags = RHI::ImageBindFlags::ShaderWrite;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::None;
        flags.viewBindFlags = RHI::ImageBindFlags::ShaderReadWrite;
        testCases.push_back(flags);

        return testCases;
    }