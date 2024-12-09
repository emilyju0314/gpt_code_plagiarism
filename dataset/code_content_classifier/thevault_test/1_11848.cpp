void TaaPass::GenerateFilterWeights(AZ::Vector2 jitterOffset)
    {
        static const AZStd::array<Vector2, 9> pixelOffsets =
        {
            // Center
            Vector2(0.0f, 0.0f),
            // Cross
            Vector2( 1.0f,  0.0f),
            Vector2( 0.0f,  1.0f),
            Vector2(-1.0f,  0.0f),
            Vector2( 0.0f, -1.0f),
            // Diagonals
            Vector2( 1.0f,  1.0f),
            Vector2( 1.0f, -1.0f),
            Vector2(-1.0f,  1.0f),
            Vector2(-1.0f, -1.0f),
        };

        float sum = 0.0f;
        for (uint32_t i = 0; i < 9; ++i)
        {
            m_filterWeights[i] = BlackmanHarris(pixelOffsets[i] + jitterOffset);
            sum += m_filterWeights[i];
        }

        // Normalize the weight so the sum of all weights is 1.0.
        float normalization = 1.0f / sum;
        for (uint32_t i = 0; i < 9; ++i)
        {
            m_filterWeights[i] *= normalization;
        }
    }