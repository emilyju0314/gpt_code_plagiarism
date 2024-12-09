static int luno_absolutize(lua_State *L)
{
    const OUString aBaseURL = luno_luatooustring(L, 1);
    const OUString aRelURL = luno_luatooustring(L, 2);
    OUString aAbsURL;
    osl::FileBase::RC e = osl::FileBase::getAbsoluteFileURL(aBaseURL, aRelURL, aAbsURL);
    if (e != osl::FileBase::E_None)
        luaL_error(L, "Illegal URL passed.");
    luno_pushoustring(L, aAbsURL);
    return 1;
}