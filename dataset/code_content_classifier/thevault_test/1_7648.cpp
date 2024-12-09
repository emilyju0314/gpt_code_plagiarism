void Remove_Item(struct Item* cur, hash_t index, struct Cache* cache)
{
	struct Freq* freq = cur->parent;
	cache->cache_size -= 1;

	Hashtab_Delete(cur->data, index, cache);

	if (cur->prev == NULL && cur->next == NULL)
	{
		free(cur);
		freq->old_child = NULL;
		freq->child = NULL;

		if (freq->value != 1)
			Delete_Freq(freq);
	}
	else if (cur->next == NULL)
	{
		cur->prev->next = NULL;
		freq->old_child = cur->prev;

		free(cur);
	}
	else if (cur->prev == NULL)
	{
		freq->child = cur->next;
		cur->next->prev = NULL;

		free(cur);
	}
	else
	{
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		free(cur);
	}
}