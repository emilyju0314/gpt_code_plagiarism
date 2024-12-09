hash_entry::hash_entry (hash_set * const hset, unsigned indx) :
    my_set(hset),
    idx(indx)
{
    this->tag = 0x0;
    this->free = true;
    this->have_data = false;
    this->dirty = false;
}