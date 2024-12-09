table_entry_pos_t lmtable::ngcnt(table_entry_pos_t	*cnt)
	{
		ngram	ng(lmtable::getDict(),0);
		memset(cnt, 0, (maxlev+1)*sizeof(*cnt));
		ngcnt(cnt, ng, 1, 0, cursize[1]);
		return 0;
	}