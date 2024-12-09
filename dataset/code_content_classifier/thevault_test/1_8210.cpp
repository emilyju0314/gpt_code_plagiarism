static int _wrap__Module_gc(lua_State * L)
	{
		userdata * u = (userdata *)lua_touserdata(L, 1);
		Module * t = (Module *)u->data;
		delete t;
		return 0;
	}