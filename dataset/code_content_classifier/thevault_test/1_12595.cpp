hash_entry* hash_set::get_entry (paddr_t tag)
{
    hash_entry *entry = NULL;
    list<hash_entry *>::iterator it;

    for (it = set_entries.begin(); it != set_entries.end(); ++it)
    {
        if ((tag == (*it)->tag) && !(*it)->free)
        {
            entry = *it;
            break;
        }
    }

    return entry;
}