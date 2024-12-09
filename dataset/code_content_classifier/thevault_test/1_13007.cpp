Sample::value_type GetSampleFromName(const std::string& sample_name)
    {
        for (const auto& sample_info : Sample::GetInfos())
        {
            if (sample_info.name == sample_name)
            {
                return sample_info.sample; 
            }
        }

        // throw if not found
        throw std::domain_error(Form("[dy::GetSampleInfo] Error: sample %s not found!", sample_name.c_str()));
    }