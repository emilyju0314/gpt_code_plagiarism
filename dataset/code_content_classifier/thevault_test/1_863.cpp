void runtime_configuration::load_components_static(
        std::vector<components::static_factory_load_data_type> const&
            static_modules)
    {
        std::vector<std::shared_ptr<components::component_registry_base>>
            registries;
        for (components::static_factory_load_data_type const& d :
            static_modules)
        {
            auto new_registries = util::load_component_factory_static(
                *this, d.name, d.get_factory);
            registries.reserve(registries.size() + new_registries.size());
            std::copy(new_registries.begin(), new_registries.end(),
                std::back_inserter(registries));
        }

        // read system and user ini files _again_, to allow the user to
        // overwrite the settings from the default component ini's.
        util::init_ini_data_base(*this, hpx_ini_file);

        // let the command line override the config file.
        if (!cmdline_ini_defs.empty())
            parse("<command line definitions>", cmdline_ini_defs, true, false);

        // merge all found ini files of all components
        util::merge_component_inis(*this);

        need_to_call_pre_initialize = true;

        // invoke last reconfigure
        reconfigure();
        for (auto& registry : registries)
        {
            registry->register_component_type();
        }
    }