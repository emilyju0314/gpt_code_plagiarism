void ModuleManager::finalize() {
    auto start_time = std::chrono::steady_clock::now();
    LOG_PROGRESS(TRACE, "FINALIZE_LOOP") << "Finalizing module instantiations";
    for(auto& module : modules_) {
        LOG_PROGRESS(TRACE, "FINALIZE_LOOP") << "Finalizing " << module->get_identifier().getUniqueName();

        // Get current time
        auto start = std::chrono::steady_clock::now();
        // Set finalize module section header
        std::string old_section_name = Log::getSection();
        std::string section_name = "F:";
        section_name += module->get_identifier().getUniqueName();
        Log::setSection(section_name);
        // Set module specific settings
        auto old_settings = set_module_before(module->get_identifier().getUniqueName(), module->get_configuration());
        // Change to our ROOT directory
        module->getROOTDirectory()->cd();
        // Finalize module
        module->finalize();
        // Remove the pointer to the ROOT directory after finalizing
        module->set_ROOT_directory(nullptr);
        // Remove the config manager
        module->set_config_manager(nullptr);
        // Reset logging
        Log::setSection(old_section_name);
        set_module_after(old_settings);
        // Update execution time
        auto end = std::chrono::steady_clock::now();
        module_execution_time_[module.get()] += static_cast<std::chrono::duration<long double>>(end - start).count();
    }
    // Close module ROOT file
    modules_file_->Close();
    LOG_PROGRESS(STATUS, "FINALIZE_LOOP") << "Finalization completed";
    auto end_time = std::chrono::steady_clock::now();
    total_time_ += static_cast<std::chrono::duration<long double>>(end_time - start_time).count();

    long double slowest_time = 0;
    std::string slowest_module;
    for(auto& module_time : module_execution_time_) {
        if(module_time.second > slowest_time) {
            slowest_time = module_time.second;
            slowest_module = module_time.first->getUniqueName();
        }
    }
    LOG(STATUS) << "Executed " << modules_.size() << " instantiations in " << seconds_to_time(total_time_) << ", spending "
                << std::round((100 * slowest_time) / std::max(1.0l, total_time_)) << "% of time in slowest instantiation "
                << slowest_module;
    for(auto& module : modules_) {
        LOG(INFO) << " Module " << module->getUniqueName() << " took " << module_execution_time_[module.get()] << " seconds";
    }

    Configuration& global_config = conf_manager_->getGlobalConfiguration();
    long double processing_time = 0;
    if(global_config.get<unsigned int>("number_of_events") > 0) {
        processing_time = std::round((1000 * total_time_) / global_config.get<unsigned int>("number_of_events"));
    }

    LOG(STATUS) << "Average processing time is \x1B[1m" << processing_time << " ms/event\x1B[0m, event generation at \x1B[1m"
                << std::round(global_config.get<double>("number_of_events") / total_time_) << " Hz\x1B[0m";
}