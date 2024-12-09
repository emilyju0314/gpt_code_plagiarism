void Add(struct Freq* freq, hash_t index, data_type data, struct Cache* cache)
{
	struct Item* item = New_Item_Constructor(data, freq), * tmp = NULL;

	assert(cache);

	if (cache->cache_size != cache->cache_max_size)
		cache->cache_size += 1;

	if (freq->child == NULL)
	{
		freq->child = item;
		freq->old_child = item;
	}
	else
	{
		tmp = freq->child;
		freq->child = item;
		item->next = tmp;
		tmp->prev = item;
	}

	Hashtab_Insert(item, index, cache);
}