static const char* RGBWeightToString(RGBWeight weight)
    {
        static const char* RGBWeightNames[] = { "Uniform", "Luminance", "CIEXYZ" };
        AZ_Assert(weight <= RGBWeight::ciexyz, "Invalid RGBWeight!");
        return RGBWeightNames[(int)weight];
    }