void __LuaBind ( lua_State* L )
{
	lua_pushcfunction(L, import);
	lua_setglobal(L, "import");
	lua_pushcfunction(L, VEC_new);
	lua_setglobal(L, "vec");
	lua_cpcall(L, luaopen_component, NULL);
	luaL_newmetatable(L, "Apollo.vec2");
	luaL_register(L, NULL, registryObjectVector);
	luaL_register(L, "input", registryInput);
	luaL_register(L, "xml", registryXML);
	luaL_register(L, "mode_manager", registryModeManager);
    luaL_register(L, "resource_manager", registryResourceManager);
    luaL_register(L, "graphics", registryGraphics);
    luaL_register(L, "sound", registrySound);
	luaL_register(L, "preferences", registryPreferences);
	luaL_register(L, "net_server", registryNetServer);
	luaL_register(L, "window", registryWindowManager);
    luaL_register(L, "xnet", registryXnet);
}