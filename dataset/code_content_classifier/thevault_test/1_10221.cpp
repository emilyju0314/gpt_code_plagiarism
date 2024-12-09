std::pair<ModuleIdentifier, Module*> ModuleManager::create_unique_modules(
    void* library, Configuration& config, Messenger* messenger, GeometryManager* geo_manager, std::mt19937_64& seeder) {
    // Make the vector to return
    std::string module_name = config.getName();

    // Return error if user tried to specialize the unique module:
    if(config.has("name")) {
        throw InvalidValueError(config, "name", "unique modules cannot be specialized using the \"name\" keyword.");
    }
    if(config.has("type")) {
        throw InvalidValueError(config, "type", "unique modules cannot be specialized using the \"type\" keyword.");
    }

    // Create the identifier
    std::string identifier_str;
    if(!config.get<std::string>("input").empty()) {
        identifier_str += config.get<std::string>("input");
    }
    if(!config.get<std::string>("output").empty()) {
        if(!identifier_str.empty()) {
            identifier_str += "_";
        }
        identifier_str += config.get<std::string>("output");
    }
    ModuleIdentifier identifier(module_name, identifier_str, 0);

    // Get the generator function for this module
    void* generator = dlsym(library, ALLPIX_GENERATOR_FUNCTION);
    // If the generator function was not found, throw an error
    if(generator == nullptr) {
        LOG(ERROR) << "Module library is invalid or outdated: required interface function not found!";
        throw allpix::DynamicLibraryError(module_name);
    }

    // Create and add module instance config
    Configuration& instance_config = conf_manager_->addInstanceConfiguration(identifier, config);

    // Specialize instance configuration
    instance_config.set<uint64_t>("_seed", seeder());
    std::string output_dir;
    output_dir = instance_config.get<std::string>("_global_dir");
    output_dir += "/";
    std::string path_mod_name = identifier.getUniqueName();
    std::replace(path_mod_name.begin(), path_mod_name.end(), ':', '_');
    output_dir += path_mod_name;

    // Convert to correct generator function
    auto module_generator = reinterpret_cast<Module* (*)(Configuration&, Messenger*, GeometryManager*)>(generator); // NOLINT

    LOG(DEBUG) << "Creating unique instantiation " << identifier.getUniqueName();

    // Get current time
    auto start = std::chrono::steady_clock::now();
    // Set the log section header
    std::string old_section_name = Log::getSection();
    std::string section_name = "C:";
    section_name += identifier.getUniqueName();
    Log::setSection(section_name);
    // Set module specific log settings
    auto old_settings = set_module_before(identifier.getUniqueName(), instance_config);
    // Build module
    Module* module = module_generator(instance_config, messenger, geo_manager);
    // Reset log
    Log::setSection(old_section_name);
    set_module_after(old_settings);
    // Update execution time
    auto end = std::chrono::steady_clock::now();
    module_execution_time_[module] += static_cast<std::chrono::duration<long double>>(end - start).count();

    // Set the module directory afterwards to catch invalid access in constructor
    module->get_configuration().set<std::string>("_output_dir", output_dir);

    // Store the module and return it to the Module Manager
    return std::make_pair(identifier, module);
}