static int luno_tosystempath(lua_State *L)
{
    const OUString aURL = luno_luatooustring(L, 1);
    OUString aSysPath;
    osl::FileBase::RC e = osl::FileBase::getSystemPathFromFileURL(aURL, aSysPath);
    if (e != osl::FileBase::E_None)
        luaL_error(L, "Illegal system path passed.");
    luno_pushoustring(L, aSysPath);
    return 1;
}