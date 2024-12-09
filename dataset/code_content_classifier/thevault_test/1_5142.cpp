void ts::PluginRepository::loadAllPlugins(Report& report)
{
    // Do nothing if loading dynamic libraries is disallowed.
    if (!_sharedLibraryAllowed) {
        return;
    }

    // Get list of shared library files
    UStringVector files;
    ApplicationSharedLibrary::GetPluginList(files, u"tsplugin_", TS_PLUGINS_PATH);

    // Load all plugins and register allocator functions (when not zero).
    for (size_t i = 0; i < files.size(); ++i) {
        PluginSharedLibrary shlib(files[i], report);
        if (shlib.isLoaded()) {
            const UString name(shlib.moduleName());
            registerInput(name, shlib.new_input);
            registerOutput(name, shlib.new_output);
            registerProcessor(name, shlib.new_processor);
        }
    }
}