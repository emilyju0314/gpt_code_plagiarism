cup* add_cup_after(cup* after, cup_finder& f, int label)
{
    auto new_cup = new cup(label);
    if (after)
    {
        new_cup->next = after->next;
        after->next = new_cup;
    }
    f.cup_by_value[label] = new_cup;
    return new_cup;
}