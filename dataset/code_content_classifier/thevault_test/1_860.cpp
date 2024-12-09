std::vector<std::string> command_line_handling::preprocess_config_settings(
        int argc, char** argv)
    {
        std::vector<std::string> options;
        options.reserve(static_cast<std::size_t>(argc) + ini_config_.size());

        // extract all command line arguments from configuration settings and
        // remove them from this list
        auto it = std::stable_partition(ini_config_.begin(), ini_config_.end(),
            [](std::string const& e) { return e.find("--hpx:") != 0; });

        std::move(it, ini_config_.end(), std::back_inserter(options));
        ini_config_.erase(it, ini_config_.end());

        // store the command line options that came from the configuration
        // settings in the registry
        if (!options.empty())
        {
            std::string config_options;
            for (auto const& option : options)
            {
                config_options += " " + option;
            }

            rtcfg_.add_entry("hpx.commandline.config_options", config_options);
        }

        // now append all original command line options
        for (int i = 1; i != argc; ++i)
        {
            options.emplace_back(argv[i]);
        }

        return options;
    }