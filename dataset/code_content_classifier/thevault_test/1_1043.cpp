void qq_chat_del_chat(SLONG index, SLONG group)
{
    QQ_CHAT_MSG **pp;
    QQ_CHAT_MSG *p;
    pp = qq_chat_get_list(group);

    if (pp)
    {
        if (pp[index])
        {
            p = pp[index];
            pp[index] = pp[index]->next;
            qq_chat_del_specify(p);
            qq_chat_mem_free(p);

            qq_chat.group_count[group - QQ_MY_FRIENDS]--;
            
        }
    }
}