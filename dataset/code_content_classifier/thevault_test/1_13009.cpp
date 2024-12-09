bool IsSample(const std::string& sample_name)
    {
        for (const auto& sample_info : Sample::GetInfos())
        {
            if (sample_info.name == sample_name)
            {
                return true; 
            }
        }
        return false;
    }