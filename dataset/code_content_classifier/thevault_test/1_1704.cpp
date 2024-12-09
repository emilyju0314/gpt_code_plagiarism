void pluginStop()
{
    if (g_pLuaContext)
    {
        dprintf("Shutting down lua environment");

        delete g_pLuaContext;
        g_pLuaContext = nullptr;
    }
}