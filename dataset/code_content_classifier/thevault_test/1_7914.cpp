static void write_keylist(FILE *fp, UNIVERSE *u)
{
	KEYLIST *keylist;
	KEYLIST_ITEM *curr;
	int i;

	ASSERT( fp != NULL );
	ASSERT( u != NULL );

	keylist = u->keylist;

	for(i=0; i < KEYLIST_HASH_TABLE_SIZE; i++) {
		if( keylist->table[i] == NULL )
			continue;

		for(curr=keylist->table[i]; curr; curr=curr->next) {
			fprintf(fp, "KEYLIST \"%s\" \"%s\"\n", curr->key, curr->value);
		}
	}

}