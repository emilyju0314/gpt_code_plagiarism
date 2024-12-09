static void push_image_resource(lua_State *L, int width, int height, int channels, int desired_channels, dmBuffer::HBuffer buffer) {
	// Image resource.
	lua_newtable(L);

	// Image resource -> Header.
	lua_newtable(L);

	lua_pushnumber(L, width);
	lua_setfield(L, -2, "width");

	lua_pushnumber(L, height);
	lua_setfield(L, -2, "height");

	lua_pushnumber(L, channels);
	lua_setfield(L, -2, "channels");

	lua_pushnumber(L, 1);
	lua_setfield(L, -2, "num_mip_maps");

	lua_getglobal(L, "resource");
	lua_getfield(L, -1, "TEXTURE_TYPE_2D");
	lua_setfield(L, -3, "type");

	if (desired_channels == 0) {
		desired_channels = channels;
	}
	switch (desired_channels) {
		case 1:
			lua_getfield(L, -1, "TEXTURE_FORMAT_LUMINANCE");
			break;
		case 3:
			lua_getfield(L, -1, "TEXTURE_FORMAT_RGB");
			break;
		case 4:
			lua_getfield(L, -1, "TEXTURE_FORMAT_RGBA");
			break;
		default:
			lua_pushnil(L);
	}
	lua_setfield(L, -3, "format");

	lua_pop(L, 1); // resource
	
	lua_setfield(L, -2, "header");

	if (buffer != 0) {
		dmScript::LuaHBuffer lua_buffer(buffer, dmScript::OWNER_LUA);
		dmScript::PushBuffer(L, lua_buffer);
		lua_setfield(L, -2, "buffer");
	}
}