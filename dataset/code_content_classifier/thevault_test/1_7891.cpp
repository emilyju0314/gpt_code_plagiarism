static CONFIG_INSTANCE *parse_base_instance(CONFIG_FILE *cf)
{
	int t;
	CONFIG_INSTANCE *ci;
	DEFINITION *def;
	DLIST *count_head;

	t = gettoken(cf);
	if( t != T_IDENT )
		error("structure name expected");

	def = search_def_list(cf->definitions, cf->tokenbuf);
	if( def == NULL )
		error("instance %s has not been defined", cf->tokenbuf);

	ci = (CONFIG_INSTANCE*) malloc( sizeof(CONFIG_INSTANCE) );
	if( ci == NULL )
		error("out of memory");

	ci->cf = cf;
	ci->definition = def;

	count_head = NULL;
	ci->instance = parse_instance(cf, def, &count_head, NULL);
	dlist_destroy(&count_head, NULL);

	return ci;
}