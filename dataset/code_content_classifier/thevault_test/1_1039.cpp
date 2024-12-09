BOOL  qq_chat_specify_check(SLONG index, SLONG group)
{
    QQ_CHAT_MSG **p;
    BOOL    result = FALSE;
    p = qq_chat_get_list(group);
    if (p)
    {
        result = (NULL != p[index]);
    }
    return result;
}