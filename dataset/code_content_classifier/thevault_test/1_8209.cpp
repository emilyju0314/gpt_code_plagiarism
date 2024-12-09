static int _wrap__gc(lua_State * L)
	{
		userdata * u = (userdata *)lua_touserdata(L, 1);
		Object * t = (Object *)u->data;
		t->release();
		return 0;
	}