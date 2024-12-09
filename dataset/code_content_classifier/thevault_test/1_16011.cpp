static int luno_tourl(lua_State *L)
{
    const OUString aSysPath = luno_luatooustring(L, 1);
    OUString aURL;
    osl::FileBase::RC e = osl::FileBase::getFileURLFromSystemPath(aSysPath, aURL);
    if (e != osl::FileBase::E_None)
        luaL_error(L, "Illegal URL passed.");
    luno_pushoustring(L, aURL);
    return 1;
}