hash_set::hash_set (hash_table *table, int asoc, unsigned set_idx) :
    index(set_idx), assoc(asoc)
{
    this->my_table = table;

    set_entries.clear();
    for (int i = 0; i < assoc; i++)
    {
        set_entries.push_front(new hash_entry (this, set_idx * assoc + i));
    }
}