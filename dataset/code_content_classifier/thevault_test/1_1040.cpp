BOOL qq_chat_specify_check_by_sindex(SLONG sid, SLONG group)
{
    QQ_CHAT_MSG **p;
    SLONG count, i;
    BOOL    result = FALSE;

    p = qq_chat_get_list(group);
    if (p)
    {
        count = qfl_max_count(group);

        for( i = 0; i < count; i++)
        {
            if (p[i])
            {
                if ( p[i]->sid == sid)
                {
                    result = TRUE;
                    break;
                }
            }
        }
    }
    return result;
}