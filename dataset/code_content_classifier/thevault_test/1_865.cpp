std::vector<std::shared_ptr<plugins::plugin_registry_base>>
    runtime_configuration::load_modules(
        std::vector<std::shared_ptr<components::component_registry_base>>&
            component_registries)
    {
        typedef std::vector<std::shared_ptr<plugins::plugin_registry_base>>
            plugin_list_type;

        // protect against duplicate paths
        std::set<std::string> component_paths;

        // list of base names avoiding to load a module more than once
        std::map<std::string, filesystem::path> basenames;

        // plugin registry object
        plugin_list_type plugin_registries;

        // load plugin paths from component_base_paths and suffixes
        std::string component_base_paths(
            get_entry("hpx.component_base_paths", HPX_DEFAULT_COMPONENT_PATH));
        std::string component_path_suffixes(
            get_entry("hpx.component_path_suffixes", "/lib/hpx"));

        load_component_paths(plugin_registries, component_registries,
            component_base_paths, component_path_suffixes, component_paths,
            basenames);

        // load additional explicit plugin paths from plugin_paths key
        std::string plugin_paths(get_entry("hpx.component_paths", ""));
        load_component_paths(plugin_registries, component_registries,
            plugin_paths, "", component_paths, basenames);

        // read system and user ini files _again_, to allow the user to
        // overwrite the settings from the default component ini's.
        util::init_ini_data_base(*this, hpx_ini_file);

        // let the command line override the config file.
        if (!cmdline_ini_defs.empty())
            parse("<command line definitions>", cmdline_ini_defs, true, false);

        // merge all found ini files of all components
        util::merge_component_inis(*this);

        need_to_call_pre_initialize = true;

        // invoke reconfigure
        reconfigure();

        return plugin_registries;
    }