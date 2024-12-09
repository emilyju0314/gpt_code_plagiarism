TChain* GetSampleTChain(const Sample::value_type& sample)
    {
        const Sample::Info info = GetSampleInfo(sample);

        // build the list of files
        std::vector<std::string> vpath = lt::string_split(info.ntuple_path, ",");

        // build the chain
        TChain* chain = new TChain("Events");
        for (const auto& file : vpath)
        {
            chain->Add(file.c_str());
        }
        return chain;
    }