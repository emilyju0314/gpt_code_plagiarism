static DEFINITION *parse_base_definition(CONFIG_FILE *cf)
{
	int t;
	char struct_name[ BUFSIZ ];
	DEFINITION *def;

	t = gettoken(cf);
	if( t != T_IDENT )
		error("%s unexpected after 'struct' keyword", cf->tokenbuf);

	strcpy(struct_name, cf->tokenbuf);

	def = parse_definition(cf, struct_name);
	def->name = strdup(struct_name);

	return def;
}