bool luaConf::getString(string varName, string &varValue)
{
	int stack = 0;

	char_separator<char> sep(".");
	tokenizer<char_separator<char>> tokens(varName, sep);

	auto t = tokens.begin();

	lua_getglobal(L, (*t).c_str());	// object to stack @ -1
	stack++;

	while (true) {
		if (lua_isstring(L, -1)) {
			varValue = lua_tostring(L, -1);
			break;
		} else if (lua_istable(L, -1)) {
			lua_pushnil(L); // nil key
			if (lua_next(L, -2)) { // puts k,v on stack
				lua_pop(L, 2); // pop off v
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
	return true;
error:
	lua_pop(L, stack);
	error("%s: variable '%s' is empty or does not exist",
	      name(), varName.c_str());
	return false;
}