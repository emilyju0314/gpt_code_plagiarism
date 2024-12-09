int luaU_dump (LuaThread* L, const LuaProto* f, lua_Writer w, void* data, int strip)
{
 THREAD_CHECK(L);
 DumpState D;
 D.L=L;
 D.writer=w;
 D.data=data;
 D.strip=strip;
 D.status=0;
 DumpHeader(&D);
 DumpFunction(f,&D);
 return D.status;
}