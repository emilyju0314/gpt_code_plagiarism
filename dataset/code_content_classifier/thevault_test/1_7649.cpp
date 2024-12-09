struct Output* Hashtab_Lookup(struct Hash_Item* cur_hash, data_type data)
{
	struct Output* res = (struct Output*) calloc(1, sizeof(struct Output));
	assert(res);

	if (cur_hash->item == NULL)
	{
		res->res = DOESNT_EXIST;
		res->item = NULL;

		return res;
	}
	else if (cur_hash->next == NULL)
	{
		if (cur_hash->value == data)
		{
			res->item = cur_hash->item;
			res->res = EXIST;
			return res;
		}
		else
		{
			res->item = NULL;
			res->res = DOESNT_EXIST;
			return res;
		}
	}
	else
		while (cur_hash != NULL)
		{
			if (data == cur_hash->value)
			{
				res->item = cur_hash->item;
				res->res = EXIST;
				return res;
			}
			cur_hash = cur_hash->next;
		}

	res->res = DOESNT_EXIST;
	res->item = NULL;
	return res;
}