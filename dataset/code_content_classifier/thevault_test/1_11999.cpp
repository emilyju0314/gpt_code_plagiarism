void BenchmarkAssetBuilderWorker::FillBuffer(AZStd::vector<uint8_t>& buffer, uint64_t bufferSize, uint64_t seed)
    {
        AZ::SimpleLcgRandom random(seed);
        uint64_t randomNum = 0;

        for (uint64_t offset = 0; offset < bufferSize; offset++)
        {
            // For efficiency, we only get a new random uint64 when we've used up all the random bytes
            // from the last one.  The SimpleLcgRandom generator only produces a 48-bit random number,
            // so we only get 6 usable bytes from each u64 random number.
            constexpr uint64_t usableRandomBytes = UINT64_C(6);
            constexpr uint32_t bitsPerByte = 8;
            randomNum = ((offset % usableRandomBytes) == 0) ? random.Getu64Random() : randomNum >> bitsPerByte;
            buffer[offset] = azlossy_cast<uint8_t>(randomNum);
        }
    }