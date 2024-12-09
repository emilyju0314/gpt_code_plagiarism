static void enumerateGlobalHandles()
{
    for (GlobalHandleMap::iterator it = globalHandleMap().begin(), end = globalHandleMap().end(); it != end; ++it) {
        GlobalHandleInfo* info = it->second;
        UNUSED_PARAM(info);
        v8::Value* handle = it->first;
        UNUSED_PARAM(handle);
    }
}