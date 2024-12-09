std::vector<Vector3> GenerateNoiseForSignificantFigureRange(AZ::u32 startDecimalPlace, AZ::u32 endDecimalPlace)
    {
        std::vector<Vector3> noise(endDecimalPlace - startDecimalPlace + 1);

        for (AZ::u32 decimal = startDecimalPlace, i = 0; decimal <= endDecimalPlace; decimal++, i++)
        {
            float x = GenerateNoiseWithSignificantFigures(decimal);
            float y = GenerateNoiseWithSignificantFigures(decimal);
            float z = GenerateNoiseWithSignificantFigures(decimal);
            noise[i] = Vector3{x, y, z};
        }

        return noise;
    }