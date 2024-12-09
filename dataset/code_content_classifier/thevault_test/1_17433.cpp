const char *    XPMPMultiplayerInitLegacyData(const char* inCSLFolder,
                                              const char* inPluginName,
                                              const char* resourceDir,
                                              XPMPIntPrefsFuncTy inIntPrefsFunc,
                                              const char* inDefaultICAO,
                                              const char* inPluginLogAcronym)
{
    // We just pass on the calls to the individual functions:
    
    // Internal init first
    const char* ret = XPMPMultiplayerInit (inPluginName,
                                           resourceDir,
                                           inIntPrefsFunc,
                                           inDefaultICAO,
                                           inPluginLogAcronym);
    if (ret[0])                                     // failed?
        return ret;
    
    // Then try loading the first set of CSL models
    return XPMPLoadCSLPackage(inCSLFolder);
}