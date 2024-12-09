std::vector<ImageAndViewBindFlags> GenerateCompatibleImageBindFlagCombinations()
    {
        std::vector<ImageAndViewBindFlags> testCases;
        ImageAndViewBindFlags flags;

        // When the image bind flags are equal to or a superset of the image view bind flags, the view is compatible with the image
        flags.imageBindFlags = RHI::ImageBindFlags::Color;
        flags.viewBindFlags = RHI::ImageBindFlags::Color;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::ShaderReadWrite;
        flags.viewBindFlags = RHI::ImageBindFlags::ShaderRead;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::ShaderReadWrite;
        flags.viewBindFlags = RHI::ImageBindFlags::ShaderWrite;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::ShaderReadWrite;
        flags.viewBindFlags = RHI::ImageBindFlags::ShaderReadWrite;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::ShaderRead;
        flags.viewBindFlags = RHI::ImageBindFlags::ShaderRead;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::ShaderWrite;
        flags.viewBindFlags = RHI::ImageBindFlags::ShaderWrite;
        testCases.push_back(flags);

        // When the image view bind flags are None, they have no effect and should work with any bind flag used by the image
        flags.imageBindFlags = RHI::ImageBindFlags::ShaderRead;
        flags.viewBindFlags = RHI::ImageBindFlags::None;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::ShaderWrite;
        flags.viewBindFlags = RHI::ImageBindFlags::None;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::ShaderReadWrite;
        flags.viewBindFlags = RHI::ImageBindFlags::None;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::None;
        flags.viewBindFlags = RHI::ImageBindFlags::None;
        testCases.push_back(flags);

        flags.imageBindFlags = RHI::ImageBindFlags::Color;
        flags.viewBindFlags = RHI::ImageBindFlags::None;
        testCases.push_back(flags);

        return testCases;
    }