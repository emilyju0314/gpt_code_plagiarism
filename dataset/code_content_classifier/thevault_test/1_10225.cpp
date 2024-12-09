void ModuleManager::run() {
    Configuration& global_config = conf_manager_->getGlobalConfiguration();

    global_config.setDefault("experimental_multithreading", false);
    unsigned int threads_num;

    if(global_config.get<bool>("experimental_multithreading")) {
        // Try to fetch a suitable number of workers if multithreading is enabled
        threads_num = global_config.get<unsigned int>("workers", std::max(std::thread::hardware_concurrency(), 1u));
        if(threads_num == 0) {
            throw InvalidValueError(global_config, "workers", "number of workers should be strictly more than zero");
        }
        LOG(WARNING) << "Experimental multithreading enabled - using " << threads_num << " worker threads.";
        --threads_num;
    } else {
        // Default to no additional thread without multithreading
        threads_num = 0;
    }

    // Creates the thread pool
    LOG(DEBUG) << "Initializing thread pool with " << threads_num << " additional thread(s)";
    std::vector<Module*> module_list;
    for(auto& module : modules_) {
        module_list.emplace_back(module.get());
    }
    auto init_function = [log_level = Log::getReportingLevel(), log_format = Log::getFormat()]() {
        // Initialize the threads to the same log level and format as the master setting
        Log::setReportingLevel(log_level);
        Log::setFormat(log_format);
    };
    std::shared_ptr<ThreadPool> thread_pool = std::make_shared<ThreadPool>(threads_num, module_list, init_function);
    for(auto& module : modules_) {
        module->set_thread_pool(thread_pool);
    }

    // Loop over all the events
    auto start_time = std::chrono::steady_clock::now();
    global_config.setDefault<unsigned int>("number_of_events", 1u);
    auto number_of_events = global_config.get<unsigned int>("number_of_events");
    for(unsigned int i = 0; i < number_of_events; ++i) {
        // Check for termination
        if(terminate_) {
            LOG(INFO) << "Interrupting event loop after " << i << " events because of request to terminate";
            number_of_events = i;
            global_config.set<unsigned int>("number_of_events", i);
            break;
        }

        LOG_PROGRESS(STATUS, "EVENT_LOOP") << "Running event " << (i + 1) << " of " << number_of_events;

        // Get object count for linking objects in current event
        auto save_id = TProcessID::GetObjectCount();

        std::string module_name;
        if(!modules_.empty()) {
            module_name = modules_.front()->get_identifier().getName();
        }
        for(auto& module : modules_) {
            // Execute all remaining jobs in the thread pool when switching to a new module type
            if(module->get_identifier().getName() != module_name) {
                module_name = module->get_identifier().getName();
                thread_pool->execute_all();
            }

            auto execute_module = [module = module.get(), event_num = i + 1, this, number_of_events]() {
                LOG_PROGRESS(TRACE, "EVENT_LOOP") << "Running event " << event_num << " of " << number_of_events << " ["
                                                  << module->get_identifier().getUniqueName() << "]";
                // Check if module is satisfied to run
                if(!module->check_delegates()) {
                    LOG(TRACE) << "Not all required messages are received for " << module->get_identifier().getUniqueName()
                               << ", skipping module!";
                    return;
                }

                // Get current time
                auto start = std::chrono::steady_clock::now();
                // Set run module section header
                std::string old_section_name = Log::getSection();
                std::string section_name = "R:";
                section_name += module->get_identifier().getUniqueName();
                Log::setSection(section_name);
                // Set module specific settings
                auto old_settings = set_module_before(module->get_identifier().getUniqueName(), module->get_configuration());
                // Change to ROOT directory is not thread safe, only do this for module without parallelization support
                if(!module->canParallelize()) {
                    // DEPRECATED: Switching to the directory should be removed, but can break current modules
                    module->getROOTDirectory()->cd();
                }
                // Run module
                try {
                    module->run(event_num);
                } catch(EndOfRunException& e) {
                    // Terminate if the module threw the EndOfRun request exception:
                    LOG(WARNING) << "Request to terminate:" << std::endl << e.what();
                    terminate_ = true;
                }
                // Reset logging
                Log::setSection(old_section_name);
                set_module_after(old_settings);
                // Update execution time
                auto end = std::chrono::steady_clock::now();
                module_execution_time_[module] += static_cast<std::chrono::duration<long double>>(end - start).count();
            };

            if(module->canParallelize()) {
                // Submit the module function
                thread_pool->submit_module_function(execute_module);
            } else {
                // Finish thread pool
                thread_pool->execute_all();
                // Execute current module
                execute_module();
            }
        }

        // Finish executing the last remaining tasks
        thread_pool->execute_all();

        // Resetting delegates
        for(auto& module : modules_) {
            LOG(TRACE) << "Resetting messages";
            module->reset_delegates();
        }

        // Reset object count for next event
        TProcessID::SetObjectCount(save_id);
    }
    LOG_PROGRESS(STATUS, "EVENT_LOOP") << "Finished run of " << number_of_events << " events";
    auto end_time = std::chrono::steady_clock::now();
    total_time_ += static_cast<std::chrono::duration<long double>>(end_time - start_time).count();

    // Remove pool from modules, wait for the threads to finish and destroy pool
    LOG(TRACE) << "Destroying thread pool";
    for(auto& module : modules_) {
        module->set_thread_pool(nullptr);
    }
    thread_pool.reset();
    assert(thread_pool.use_count() == 0);
}