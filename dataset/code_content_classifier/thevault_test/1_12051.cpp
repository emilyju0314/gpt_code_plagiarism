static float GetIconScale(const float distSq)
    {
        AZ_PROFILE_FUNCTION(AzToolsFramework);

        return s_iconMinScale +
            (s_iconMaxScale - s_iconMinScale) *
            (1.0f - AZ::GetClamp(AZ::GetMax(0.0f, sqrtf(distSq) - s_iconCloseDist) / s_iconFarDist, 0.0f, 1.0f));
    }