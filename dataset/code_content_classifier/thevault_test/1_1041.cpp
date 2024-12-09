BOOL qq_chat_check_group(SLONG group)
{
    if (group >= QQ_MY_FRIENDS && group <= QQ_STRANGERS)
        return (qq_chat.group_count[group-QQ_MY_FRIENDS]);
    else
        return FALSE;
}