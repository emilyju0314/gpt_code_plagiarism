SLONG qq_chat_add_chat(SLONG index, SLONG group, SLONG sid,char *message)
{
    QQ_CHAT_MSG *p;
    QQ_CHAT_MSG *tp1, *tp2;
    QQ_CHAT_MSG **pp;
    UI_QQFRIEND *pf;
    
    pp = qq_chat_get_list(group);

    if (pp)
    {
        p = qq_chat_mem_alloc();
        if (NULL == p)
            return TTN_NOT_OK;

        if (pp[index])
        {
            for( tp1 = pp[index]; tp1 != NULL; tp1 = tp1->next)
                tp2 = tp1;
            tp2->next = p;
        }
        else
        {
            pp[index] = p;
        }

        pf = qf_get(index, group);
        if (pf)
        {
            p->sid = pf->sid;
        }

        lstrcpyn((LPSTR)p->msg, (LPCSTR)message, 200);
        p->index = index;
        p->group = group;
        p->next  = NULL;

        qq_chat_list_add(p);

        qq_chat.group_count[group-QQ_MY_FRIENDS]++;

        return TTN_OK;
    }

    return TTN_NOT_OK;
}