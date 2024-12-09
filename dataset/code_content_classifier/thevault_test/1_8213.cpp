static int searcher(lua_State * L)
	{
		const char * src = lua_tostring(L, 1);

		int length = strlen(src);

		// luaopen_ needs 8 chars.
		char * dst = new char[length+8+1];
		memcpy(dst, "luaopen_", 8); 

		for(int i = 0; i<=length; i++)
			dst[i+8] = (src[i] == '.') ? '_' : src[i];

		void * sym = instance->getSymbol(dst);

		if(sym == 0)
			lua_pushfstring(L, "\tno symbol \"%s\" in love.native.\n", dst);
		else
			lua_pushcfunction(L, (lua_CFunction)sym);

		delete [] dst;

		return 1;
	}