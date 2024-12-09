Sample::Info CreateSampleInfo(const Sample::value_type sample, const std::vector<edm::ParameterSet>& pset_vec)
    {
        assert(pset_vec.size() == Sample::static_size);
        const auto& pset = pset_vec[sample];
        Sample::Info info
        {
            pset.getParameter<std::string>("name"),
            pset.getParameter<std::string>("title"),
            pset.getParameter<std::string>("latex"),
            pset.getParameter<std::string>("ntuple_path"),
            static_cast<Color_t>(pset.getParameter<int>("color")),
            pset.getParameter<double>("eff"),
            sample
        };
        return info;
    }