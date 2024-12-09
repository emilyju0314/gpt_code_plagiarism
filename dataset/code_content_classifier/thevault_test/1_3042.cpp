vec2 luaL_checkvec2(lua_State* L, int narg)
{
	if (!lua_istable(L, narg))
	{
		luaL_argerror(L, narg, "must pass a vector table (not a table)");
	}
	float x, y;
	lua_getfield(L, narg, "x");
	if (!lua_isnumber(L, -1))
	{
		luaL_argerror(L, narg, "must pass a vector table (bad x value)");
	}
	x = lua_tonumber(L, -1);
	lua_getfield(L, narg, "y");
	if (!lua_isnumber(L, -1))
	{
		luaL_argerror(L, narg, "must pass a vector table (bad y value)");
	}
	y = lua_tonumber(L, -1);
	lua_pop(L, 2);
	return vec2(x, y);
}