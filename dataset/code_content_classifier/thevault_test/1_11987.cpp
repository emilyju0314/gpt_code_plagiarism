std::vector<unsigned long> GenerateBitsetTestCases()
    {
        std::vector<unsigned long> testCases;

        testCases.push_back(0b0000'0000'0000'0000'0000'0000'0000'0000);
        testCases.push_back(0b1111'1111'1111'1111'1111'1111'1111'1111);
        testCases.push_back(0b1010'1010'1010'1010'1010'1010'1010'1010);
        testCases.push_back(0b0101'0101'0101'0101'0101'0101'0101'0101);
        testCases.push_back(0b0000'0000'0000'0000'1111'1111'1111'1111);
        testCases.push_back(0b1111'1111'1111'1111'0000'0000'0000'0000);

        // Asymmetrical test cases
        testCases.push_back(0b1100'1010'1000'1000'0011'1101'0100'1100);
        testCases.push_back(0b0111'1100'1000'1001'1000'0001'1001'1001);

        return testCases;
    }