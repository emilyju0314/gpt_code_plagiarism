ts::PluginSharedLibrary::PluginSharedLibrary(const UString& filename, Report& report) :
    ApplicationSharedLibrary(filename, u"tsplugin_", TS_PLUGINS_PATH, true, report),
    new_input(nullptr),
    new_output(nullptr),
    new_processor(nullptr)
{
    // If still not loaded, error
    if (!isLoaded()) {
        report.error(errorMessage());
        return;
    }

    // Locate and check the API version
    const UString path(fileName());
    const int* version = reinterpret_cast<const int*>(getSymbol("tspInterfaceVersion"));

    if (version == nullptr) {
        report.error(u"no symbol tspInterfaceVersion in " + path);
        unload();
        return;
    }

    if (*version != TSP::API_VERSION) {
        report.error(u"incompatible API version %d in %s, expected %d", {*version, path, TSP::API_VERSION});
        unload();
        return;
    }

    // Load the plugin entry points
    new_input = reinterpret_cast<NewInputProfile>(getSymbol("tspNewInput"));
    new_output = reinterpret_cast<NewOutputProfile>(getSymbol("tspNewOutput"));
    new_processor = reinterpret_cast<NewProcessorProfile>(getSymbol("tspNewProcessor"));
}