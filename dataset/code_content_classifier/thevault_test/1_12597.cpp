void hash_set::update_lru (hash_entry *entry)
{
    set_entries.remove (entry);
    set_entries.push_front (entry);
}