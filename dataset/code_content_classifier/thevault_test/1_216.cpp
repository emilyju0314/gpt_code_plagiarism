bool luaConf::getBool(string varName)
{
	int stack = 0;
	bool b;

	char_separator<char> sep(".");
	tokenizer<char_separator<char>> tokens(varName, sep);

	auto t = tokens.begin();

	lua_getglobal(L, (*t).c_str());	// object to stack @ -1
	stack++;

	while (true) {

		if (lua_isboolean(L, -1)) {
			b = lua_toboolean(L, -1) != 0;	// convert to bool (really)
			break;
		} else if (lua_istable(L, -1)) {
			lua_pushnil(L); // nil key
			if (lua_next(L, -2)) {
				lua_pop(L, 2); // pop off k,v
				t++;
				if (t != tokens.end()) {
					lua_getfield(L, -1, (*t).c_str());
					stack++;
				}
			} else {
				goto error;
			}
		} else {
			goto error;
		}
	}
	lua_pop(L, stack);
	debug("%s: loaded %s", name(), varName.c_str());
	return b;
error:
	lua_pop(L, stack);
	error("%s: variable '%s' is empty or does not exist",
	      name(), varName.c_str());
	return false;
}