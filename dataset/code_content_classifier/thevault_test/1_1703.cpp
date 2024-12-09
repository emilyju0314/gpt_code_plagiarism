bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
    _plugin_registercommand(pluginHandle, "lua", cbLuaCommand, false);

    if (g_pLuaContext != nullptr)
    {
        // Double init?
        return false;
    }

    std::string basePath = Utils::getx64DbgBasePath();
    dprintf("Base Path: %s\n", basePath.c_str());

    std::string luaBasePath = Utils::pathCombine(basePath, "lua");
    dprintf("Lua Base Path: %s\n", luaBasePath.c_str());

    g_pLuaContext = new LuaContext();
    g_pLuaContext->setBasePath(luaBasePath);

    dprintf("Lua context created\n");

    if (!g_pLuaContext->createGlobalState())
    {
        dprintf("Unable to register lua libraries.\n");
    }
    else
    {
        dprintf("Registered lua libraries.\n");
    }

    if (!g_pLuaContext->executeAutorunScripts())
    {
        dprintf("One ore multiple scripts failed.\n");
    }

    pluginScriptInit();

    return true; //Return false to cancel loading the plugin.
}