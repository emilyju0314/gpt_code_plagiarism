float GenerateNoiseWithSignificantFigures(AZ::u32 afterDecimalPlace)
    {
        // number of significant figures of randomness to generate
        const double numSigFigs = 8;

        // scaling factor to push the noise back into the desired range
        const double sigFactor = std::pow(10.0, numSigFigs + afterDecimalPlace);

        // random value for first guaranteed significant digit
        const auto firstSigFig = azlossy_cast<AZ::u64>(rndFirstSigFig(gen)) * std::pow(10.0, numSigFigs - 1);

        // random value for the other significant digits
        const auto otherSigFigs = azlossy_cast<AZ::u64>(rndOtherSigFigs(gen) * std::pow(10.0, numSigFigs - 1));

        // unscaled random value with rndSigFigs significant figures
        const auto fixedLengthRandom = firstSigFig + otherSigFigs;

        // scaled random value to push the noise into the desired significant digit range
        const float noise = aznumeric_cast<float>(fixedLengthRandom / sigFactor);

        return noise;
    }