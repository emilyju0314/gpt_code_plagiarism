cup* cut_next_three(cup* current)
{
    auto first = current->next;
    auto last = current->next->next->next;
    current->next = last->next;
    last->next = nullptr;
    return first;
}