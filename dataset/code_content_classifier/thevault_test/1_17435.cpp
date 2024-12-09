void XPMPSetPluginName (const char* inPluginName,
                        const char* inPluginLogAcronym)
{
    if (inPluginName)
        glob.pluginName = inPluginName;
    glob.logAcronym = inPluginLogAcronym ? inPluginLogAcronym : glob.pluginName;
}