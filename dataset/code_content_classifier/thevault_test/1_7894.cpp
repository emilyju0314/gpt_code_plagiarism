PHASCII_INSTANCE Phascii_GetInstance(PHASCII_FILE phf)
{
	CONFIG_FILE *cf;
	CONFIG_INSTANCE *ci;
	DEFINITION *def, *d;
	char buf[ BUFSIZ ];
	int t, found;
	DLIST *curr;

	cf = (CONFIG_FILE*) phf;

	/*
	 * Clear any possible errors.
	 */
	cf->error[0] = '\0';

	/*
	 * Setup error handler.
	 */
	if( setjmp(jmpbuf) ) {
		sprintf(buf, "%s: Line: %d, %s.", cf->filename, cf->lineno, cf_errorbuf);
		strcpy(cf->error, buf);
		return NULL;
	}

	ci = NULL;
	for(;;) {
		t = gettoken(cf);
		if( t == T_STRUCT ) {
			def = parse_base_definition(cf);

			/*
			 * See if we are creating a new definition.
			 */
			found = FALSE;
			for(curr=cf->definitions; curr; curr=curr->next) {
				d = (DEFINITION*)curr->p;
				if( !ident_cmp(d->name, def->name) ) {
					found = TRUE;
					break;
				}
			}
			if( found ) {
				/*
				 * It is possible that the caller has a 'ci'
				 * which points to the definition we are going to
				 * be updating. This is rare, but it is easy
				 * enough to protect ourselves against.
				 * Just move the definition to another
				 * list.
				 */
				dlist_delete(&cf->definitions, d, NULL, NULL);
				dlist_add(&cf->old_definitions, d);
			}
			dlist_add(&cf->definitions, def);

		} else if( t == T_IDENT ) {
			ungettoken(cf, t);
			ci = parse_base_instance(cf);
			break;

		} else if( t == T_EOF ) {
			break;

		} else {
			error("missing definition or instance at or near '%s'", cf->tokenbuf);
		}
	}
	return (PHASCII_INSTANCE *) ci;
}