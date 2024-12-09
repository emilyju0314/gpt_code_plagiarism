static DEFINITION *parse_definition(CONFIG_FILE *cf, char *struct_name)
{
	int t;
	DEFINITION *def, *d, *save_def;
	DLIST *clist;
	DLIST *index_list, *curr;

	t = gettoken(cf);
	if( t == '{' ) {
		/*
		 * non-array structure.
		 */
		clist = parse_component_list(cf);

		def = (DEFINITION*) malloc( sizeof(DEFINITION) );
		if( def == NULL )
			error("out of memory");
		def->type = DEF_STRUCT;
		def->default_value = NULL;
		def->components = clist;
		def->index = NULL;

	} else if( t == '[' ) {
		/*
		 * Array structure.
		 */
		index_list = parse_indexes(cf);
		t = gettoken(cf);
		if( t != '{' )
			error("syntax error in structure %s", struct_name);

		clist = parse_component_list(cf);

		save_def = def = (DEFINITION*) malloc( sizeof(DEFINITION) );
		if( def == NULL )
			error("out of memory");
		def->type = DEF_ARRAY;
		def->default_value = NULL;
		def->components = NULL;
		def->index = (char*)index_list->p;

		for(curr=index_list->next; curr; curr=curr->next) {
			d = (DEFINITION*) malloc( sizeof(DEFINITION) );
			if( d == NULL )
				error("out of memory");
			d->name = strdup("[]");
			d->type = DEF_ARRAY;
			d->default_value = NULL;
			d->components = NULL;
			d->index = (char*)curr->p;
			dlist_add(&def->components, d);
			def = d;
		}
		def->components = clist;
		dlist_destroy(&index_list, NULL);

		def = save_def;

	} else
		error("unexpected %s in structure definition for %s",
				cf->tokenbuf, struct_name);

	return def;
}