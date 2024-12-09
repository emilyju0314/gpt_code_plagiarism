const char *    XPMPMultiplayerInit(const char* inPluginName,
                                    const char* resourceDir,
                                    XPMPIntPrefsFuncTy inIntPrefsFunc,
                                    const char* inDefaultICAO,
                                    const char* inPluginLogAcronym)
{
    // Initialize random number generator
    std::srand(unsigned(std::time(nullptr)));

    /// Assume that this is XP's main thread
    glob.ThisThreadIsXP();
    
    // Store the pointers to the configuration callback functions
    glob.prefsFuncInt   = inIntPrefsFunc    ? inIntPrefsFunc    : PrefsFuncIntDefault;
    
    // Get the plugin's name and store it for later reference
    XPMPSetPluginName(inPluginName, inPluginLogAcronym);
    if (glob.pluginName == UNKNOWN_PLUGIN_NAME) {
        char szPluginName[256];
        XPLMGetPluginInfo(XPLMGetMyID(), szPluginName, nullptr, nullptr, nullptr);
        glob.pluginName = szPluginName;
        if (!inPluginLogAcronym)
            glob.logAcronym = glob.pluginName;
    }

    // Get X-Plane's version numbers
    glob.ReadVersions();    
    LOG_MSG(logINFO, "XPMP2 %.2f initializing under X-Plane version %d/%s and XPLM version %d",
            XPMP2_VER, glob.verXPlane, GetGraphicsDriverTxt(), glob.verXPLM);
    
    // Read a potential global XPMP2-specific config file
    glob.ReadConfigFile();

    // And get initial config values (defines, e.g., log level, which we'll need soon)
    glob.UpdateCfgVals();

    // Look for all supplemental files
    const char* ret = XPMPValidateResourceFiles(resourceDir);
    if (ret[0]) return ret;
    
    // Define the default ICAO aircraft type
    XPMPSetDefaultPlaneICAO(inDefaultICAO);
    
    // Initialize all modules
    CSLModelsInit();
    AcInit();
    TwoDInit();
    AIMultiInit();
    MapInit();
    RemoteInit();
    
    // Load related.txt
    ret = RelatedLoad(glob.pathRelated);
    if (ret[0]) return ret;

    // Load Doc8643.txt
    ret = Doc8643Load(glob.pathDoc8643);
    if (ret[0]) return ret;
    
    // If available (it is not required) load the Obj8DataRefs.txt file
    if (!glob.pathObj8DataRefs.empty()) {
        ret = Obj8DataRefsLoad(glob.pathObj8DataRefs);
        if (ret[0]) return ret;
    }

    // Success
    return "";
}