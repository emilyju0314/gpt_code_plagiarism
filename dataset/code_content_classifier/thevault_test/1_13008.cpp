Sample::value_type GetSampleFromNumber(const int sample_num)
    {
        // throw if not found
        if (sample_num < 0 or sample_num >= Sample::static_size)
        {
            throw std::domain_error("[dy::GetSampleInfo] Error: sample number out of bounds!");
        }
        return static_cast<Sample::value_type>(sample_num);
    }