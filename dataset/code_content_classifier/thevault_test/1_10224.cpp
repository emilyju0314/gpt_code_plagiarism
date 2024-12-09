void ModuleManager::init() {
    auto start_time = std::chrono::steady_clock::now();
    LOG_PROGRESS(STATUS, "INIT_LOOP") << "Initializing " << modules_.size() << " module instantiations";
    for(auto& module : modules_) {
        LOG_PROGRESS(TRACE, "INIT_LOOP") << "Initializing " << module->get_identifier().getUniqueName();

        // Pass the config manager to this instance
        module->set_config_manager(conf_manager_);

        // Create main ROOT directory for this module class if it does not exists yet
        LOG(TRACE) << "Creating and accessing ROOT directory";
        std::string module_name = module->get_configuration().getName();
        auto directory = modules_file_->GetDirectory(module_name.c_str());
        if(directory == nullptr) {
            directory = modules_file_->mkdir(module_name.c_str());
            if(directory == nullptr) {
                throw RuntimeError("Cannot create or access overall ROOT directory for module " + module_name);
            }
        }
        directory->cd();

        // Create local directory for this instance
        TDirectory* local_directory = nullptr;
        if(module->get_identifier().getIdentifier().empty()) {
            local_directory = directory;
        } else {
            local_directory = directory->mkdir(module->get_identifier().getIdentifier().c_str());
            if(local_directory == nullptr) {
                throw RuntimeError("Cannot create or access local ROOT directory for module " + module->getUniqueName());
            }
        }

        // Change to the directory and save it in the module
        local_directory->cd();
        module->set_ROOT_directory(local_directory);

        // Get current time
        auto start = std::chrono::steady_clock::now();
        // Set init module section header
        std::string old_section_name = Log::getSection();
        std::string section_name = "I:";
        section_name += module->get_identifier().getUniqueName();
        Log::setSection(section_name);
        // Set module specific settings
        auto old_settings = set_module_before(module->get_identifier().getUniqueName(), module->get_configuration());
        // Change to our ROOT directory
        module->getROOTDirectory()->cd();
        // Init module
        module->init();
        // Reset delegates
        LOG(TRACE) << "Resetting messages";
        module->reset_delegates();
        // Reset logging
        Log::setSection(old_section_name);
        set_module_after(old_settings);
        // Update execution time
        auto end = std::chrono::steady_clock::now();
        module_execution_time_[module.get()] += static_cast<std::chrono::duration<long double>>(end - start).count();
    }
    LOG_PROGRESS(STATUS, "INIT_LOOP") << "Initialized " << modules_.size() << " module instantiations";
    auto end_time = std::chrono::steady_clock::now();
    total_time_ += static_cast<std::chrono::duration<long double>>(end_time - start_time).count();
}