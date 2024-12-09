void hash_set::replace_entry (hash_entry *incoming, hash_entry *outgoing)
{
    list<hash_entry *>::iterator it;

    assert (incoming != NULL);
    assert (outgoing != NULL);


    for (it = set_entries.begin(); it != set_entries.end(); it++)
    {
        if ((*it)->tag == outgoing->tag)
        {
            set_entries.remove(outgoing);
            set_entries.push_front(incoming);
            break;
        }
    }
}