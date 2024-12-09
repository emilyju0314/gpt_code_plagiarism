std::string GetPluginName (XPLMPluginID who)
{
    char whoName[256];
    XPLMGetPluginInfo(who, whoName, nullptr, nullptr, nullptr);
    return whoName;
}