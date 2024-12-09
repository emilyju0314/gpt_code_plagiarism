void runtime_configuration::load_component_path(
        std::vector<std::shared_ptr<plugins::plugin_registry_base>>&
            plugin_registries,
        std::vector<std::shared_ptr<components::component_registry_base>>&
            component_registries,
        std::string const& path, std::set<std::string>& component_paths,
        std::map<std::string, filesystem::path>& basenames)
    {
        namespace fs = filesystem;

        using plugin_list_type =
            std::vector<std::shared_ptr<plugins::plugin_registry_base>>;

        if (!path.empty())
        {
            fs::path this_p(path);
            std::error_code fsec;
            fs::path canonical_p =
                fs::canonical(this_p, fs::initial_path(), fsec);
            if (fsec)
                canonical_p = this_p;

            std::pair<std::set<std::string>::iterator, bool> p =
                component_paths.insert(canonical_p.string());

            if (p.second)
            {
                // have all path elements, now find ini files in there...
                fs::path this_path(*p.first);
                if (fs::exists(this_path, fsec) && !fsec)
                {
                    plugin_list_type tmp_regs =
                        util::init_ini_data_default(this_path.string(), *this,
                            basenames, modules_, component_registries);

                    std::copy(tmp_regs.begin(), tmp_regs.end(),
                        std::back_inserter(plugin_registries));
                }
            }
        }
    }