void insert_after(cup* after, cup* picked)
{
    auto last = after->next;
    after->next = picked;

    while (picked->next)
        picked = picked->next;

    picked->next = last;
}