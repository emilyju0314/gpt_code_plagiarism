bool is_label_in(cup* cup, const int label)
{
    for(; cup; cup = cup->next)
        if (label == cup->label)
            return true;
    return false;
}