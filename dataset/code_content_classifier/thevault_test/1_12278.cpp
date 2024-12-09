AZ::OSString ModuleManager::PreProcessModule(AZStd::string_view moduleName)
    {
        // Let the application process the path
        AZ::OSString finalPath{ moduleName };
        ComponentApplicationBus::Broadcast(&ComponentApplicationBus::Events::ResolveModulePath, finalPath);

        return finalPath;
    }