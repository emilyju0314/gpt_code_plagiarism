void MotionData::CalculateInterpolationIndicesUniform(float sampleTime, float sampleSpacing, float duration, size_t numSamples, size_t& indexA, size_t& indexB, float& t)
    {
        if (sampleTime < 0.0f)
        {
            indexA = 0;
            indexB = 0;
            t = 0.0f;
            return;
        }

        if (sampleTime >= duration)
        {
            indexA = numSamples - 1;
            indexB = indexA;
            t = 0.0f;
            return;
        }

        indexA = static_cast<size_t>(floor(sampleTime / sampleSpacing));
        indexB = indexA + 1;

        if (indexB > numSamples - 1)
        {
            indexB = indexA;
            t = 0.0f;
            return;
        }

        t = (sampleTime - (indexA * sampleSpacing)) / sampleSpacing;
    }