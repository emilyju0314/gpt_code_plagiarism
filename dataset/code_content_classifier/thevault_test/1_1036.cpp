SLONG qq_search_add(LPUI_QQFRIEND p)
{
    if( g_search_friend.totol_list < MAX_SEARCH_LIST)
    {
        memcpy(&g_search_friend.p[g_search_friend.totol_list], p, sizeof(UI_QQFRIEND));
        g_search_friend.totol_list++;
        return TTN_OK;
    }

    return TTN_NOT_OK;
}