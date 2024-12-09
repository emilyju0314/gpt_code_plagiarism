int Remove_LFU(struct Cache* cache)
{
	data_type data = 0;
	hash_t index, res = 0;

	assert(cache);

	struct Freq* freq = cache->freq_head->next;
	struct Item* item = freq->old_child;

	cache->cache_size -= 1;
	data = item->data;
	index = Hash_Func(data);

	if (item->prev == NULL)
	{
		free(item);
		freq->old_child = NULL;
		freq->child = NULL;

		if (freq->value != 1)
		{
			Delete_Freq(freq);
			res = 1;
		}
	}
	else
	{
		item->prev->next = NULL;
		freq->old_child = item->prev;
		free(item);
	}

	Hashtab_Delete(data, index, cache);

	return res;
}