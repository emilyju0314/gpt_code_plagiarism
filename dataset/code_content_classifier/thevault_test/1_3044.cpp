void lua_pushvec2( lua_State* L, vec2 val )
{
	lua_createtable(L, 0, 2);
	lua_pushnumber(L, val.X());
	lua_setfield(L, -2, "x");
	lua_pushnumber(L, val.Y());
	lua_setfield(L, -2, "y");
	luaL_getmetatable(L, "Apollo.vec2");
	lua_setmetatable(L, -2);
}