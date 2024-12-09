std::vector<std::pair<ModuleIdentifier, Module*>> ModuleManager::create_detector_modules(
    void* library, Configuration& config, Messenger* messenger, GeometryManager* geo_manager, std::mt19937_64& seeder) {
    std::string module_name = config.getName();
    LOG(DEBUG) << "Creating instantions for detector module " << module_name;

    // Create the basic identifier
    std::string identifier;
    if(!config.get<std::string>("input").empty()) {
        identifier += "_";
        identifier += config.get<std::string>("input");
    }
    if(!config.get<std::string>("output").empty()) {
        identifier += "_";
        identifier += config.get<std::string>("output");
    }

    // Open the library and get the module generator function
    void* generator = dlsym(library, ALLPIX_GENERATOR_FUNCTION);
    // If the generator function was not found, throw an error
    if(generator == nullptr) {
        LOG(ERROR) << "Module library is invalid or outdated: required interface function not found!";
        throw allpix::DynamicLibraryError(module_name);
    }
    // Convert to correct generator function
    auto module_generator =
        reinterpret_cast<Module* (*)(Configuration&, Messenger*, std::shared_ptr<Detector>)>(generator); // NOLINT

    // Handle empty type and name arrays:
    bool instances_created = false;
    std::vector<std::pair<std::shared_ptr<Detector>, ModuleIdentifier>> instantiations;

    // Create all names first with highest priority
    std::set<std::string> module_names;
    if(config.has("name")) {
        std::vector<std::string> names = config.getArray<std::string>("name");
        for(auto& name : names) {
            auto det = geo_manager->getDetector(name);
            instantiations.emplace_back(det, ModuleIdentifier(module_name, det->getName() + identifier, 0));

            // Save the name (to not instantiate it again later)
            module_names.insert(name);
        }
        instances_created = !names.empty();
    }

    // Then create all types that are not yet name instantiated
    if(config.has("type")) {
        std::vector<std::string> types = config.getArray<std::string>("type");
        for(auto& type : types) {
            auto detectors = geo_manager->getDetectorsByType(type);

            for(auto& det : detectors) {
                // Skip all that were already added by name
                if(module_names.find(det->getName()) != module_names.end()) {
                    continue;
                }

                instantiations.emplace_back(det, ModuleIdentifier(module_name, det->getName() + identifier, 1));
            }
        }
        instances_created = !types.empty();
    }

    // Create for all detectors if no name / type provided
    if(!instances_created) {
        auto detectors = geo_manager->getDetectors();

        for(auto& det : detectors) {
            instantiations.emplace_back(det, ModuleIdentifier(module_name, det->getName() + identifier, 2));
        }
    }

    // Construct instantiations from the list of requests
    std::vector<std::pair<ModuleIdentifier, Module*>> module_list;
    for(auto& instance : instantiations) {
        LOG(DEBUG) << "Creating detector instantiation " << instance.second.getUniqueName();
        // Get current time
        auto start = std::chrono::steady_clock::now();

        // Create and add module instance config
        Configuration& instance_config = conf_manager_->addInstanceConfiguration(instance.second, config);

        // Add internal module config
        instance_config.set<uint64_t>("_seed", seeder());
        std::string output_dir;
        output_dir = instance_config.get<std::string>("_global_dir");
        output_dir += "/";
        std::string path_mod_name = instance.second.getUniqueName();
        std::replace(path_mod_name.begin(), path_mod_name.end(), ':', '/');
        output_dir += path_mod_name;

        // Set the log section header
        std::string old_section_name = Log::getSection();
        std::string section_name = "C:";
        section_name += instance.second.getUniqueName();
        Log::setSection(section_name);
        // Set module specific log settings
        auto old_settings = set_module_before(instance.second.getUniqueName(), instance_config);
        // Build module
        Module* module = module_generator(instance_config, messenger, instance.first);
        // Reset logging
        Log::setSection(old_section_name);
        set_module_after(old_settings);
        // Update execution time
        auto end = std::chrono::steady_clock::now();
        module_execution_time_[module] += static_cast<std::chrono::duration<long double>>(end - start).count();

        // Set the module directory afterwards to catch invalid access in constructor
        module->get_configuration().set<std::string>("_output_dir", output_dir);

        // Check if the module called the correct base class constructor
        if(module->getDetector().get() != instance.first.get()) {
            throw InvalidModuleStateException(
                "Module " + module_name +
                " does not call the correct base Module constructor: the provided detector should be forwarded");
        }

        // Store the module
        module_list.emplace_back(instance.second, module);
    }

    return module_list;
}