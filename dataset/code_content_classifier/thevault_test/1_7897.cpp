PHASCII_SCHEMA *Phascii_GetSchema(PHASCII_INSTANCE ph_entry, char *expr)
{
	CONFIG_FILE *cf;
	CONFIG_INSTANCE *ci;
	char *p;
	DLIST *curr;
	DEFINITION *def, *d, *next;
	PHASCII_SCHEMA *head, *cs;
	int t, found;

	ci = (CONFIG_INSTANCE*) ph_entry;

	cf = ci->cf;
	def = ci->definition;
	cf->error[0] = '\0';

	/* empty expression */
	if( expr == NULL || expr[0] == '\0' ) {
		head = NULL;
		cs = (PHASCII_SCHEMA *) malloc( sizeof(PHASCII_SCHEMA) );
		cs->name = strdup(def->name);
		switch( def->type ) {
		case DEF_STRUCT:
			cs->type = PHASCII_STRUCT;
			cs->indexes = NULL;
			break;

		case DEF_ARRAY:
			cs->type = PHASCII_ARRAY;
			cs->indexes = get_schema_indexes(def);
			break;

		case DEF_COMPONENT:
			/* should never happen */
			cs->type = PHASCII_COMPONENT;
			cs->indexes = NULL;
			break;
		}
		schema_add(&head, cs);
		return head;
	}

	p = expr;

	t = expr_gettoken(&p);
	if( t != ET_IDENT ) {
		sprintf(cf->error, "syntax error");
		return NULL;
	}

	if( ident_cmp(etoken_ident, def->name) ) {
		sprintf(cf->error, "identifier %s does not match instance name",
								etoken_ident);
		return NULL;
	}

	for(;;) {
		t = expr_gettoken(&p);
		if( t == ET_EOF )
			break;

		if( t != '.' ) {
			sprintf(cf->error, "syntax error");
			return NULL;
		}

		t = expr_gettoken(&p);
		if( t != ET_IDENT ) {
			sprintf(cf->error, "syntax error");
			return NULL;
		}

		switch( def->type ) {
			case DEF_STRUCT:
				/* search component list for name */
				found = FALSE;
				curr=def->components;
				while( curr ) {
					d = (DEFINITION*)curr->p;
					if( !ident_cmp(etoken_ident, d->name) ) {
						found = TRUE;
						break;
					}
					curr=curr->next;
				}
				if( !found ) {
					sprintf(cf->error, "no such component %s.%s",
						def->name, etoken_ident);
					return NULL;
				}

				def = d;
				break;

			case DEF_ARRAY:
				d = def;
				for(;;) {
					next = (DEFINITION*)d->components->p;
					if( strcmp(next->name, "[]") != 0 )
						break;
					d = next;
				}
				def = d;
				/* search component list for name */
				found = FALSE;
				curr=def->components;
				while( curr ) {
					d = (DEFINITION*)curr->p;
					if( !ident_cmp(etoken_ident, d->name) ) {
						found = TRUE;
						break;
					}
					curr=curr->next;
				}
				if( !found ) {
					sprintf(cf->error, "no such component %s.%s",
						def->name, etoken_ident);
					return NULL;
				}

				def = d;
				break;

			case DEF_COMPONENT:
				break;
		}
	}

	if( def->type == DEF_ARRAY ) {
		d = def;
		for(;;) {
			next = (DEFINITION*)d->components->p;
			if( strcmp(next->name, "[]") != 0 )
				break;
			d = next;
		}
		def = d;
	}

	head = NULL;
	for(curr=def->components; curr; curr=curr->next) {
		d = (DEFINITION*)curr->p;
		cs = (PHASCII_SCHEMA *) malloc( sizeof(PHASCII_SCHEMA) );
		cs->name = strdup(d->name);
		switch( d->type ) {
		case DEF_STRUCT:
			cs->type = PHASCII_STRUCT;
			cs->indexes = NULL;
			break;

		case DEF_ARRAY:
			cs->type = PHASCII_ARRAY;
			cs->indexes = get_schema_indexes(d);
			break;

		case DEF_COMPONENT:
			cs->type = PHASCII_COMPONENT;
			cs->indexes = NULL;
			break;
		}
		schema_add(&head, cs);
	}

	return head;
}