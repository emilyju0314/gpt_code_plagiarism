int _wrap_draws(lua_State * L)
	{
		Image * image = luax_checktype<Image>(L, 1, "Image", LOVE_GRAPHICS_IMAGE_BITS);
		float x = (float)luaL_optnumber(L, 2, 0.0f);
		float y = (float)luaL_optnumber(L, 3, 0.0f);
		float angle = (float)luaL_optnumber(L, 4, 0.0f);
		float sx = (float)luaL_optnumber(L, 5, 1.0f);
		float sy = (float)luaL_optnumber(L, 6, sx);
		float ox = (float)luaL_optnumber(L, 7, 0);
		float oy = (float)luaL_optnumber(L, 8, 0);
		float rx = (float)luaL_optnumber(L, 9, 0);
		float ry = (float)luaL_optnumber(L, 10, 0);
		float rw = (float)luaL_optnumber(L, 11, image->getWidth());
		float rh = (float)luaL_optnumber(L, 12, image->getHeight());
		image->draws(x, y, angle, sx, sy, ox, oy, rx, ry, rw, rh);
		return 0;
	}