LPUI_QQFRIEND qq_search_get(SLONG index)
{
    if (index < g_search_friend.totol_list)
    {
        return &g_search_friend.p[index];
    }

    return NULL;
}