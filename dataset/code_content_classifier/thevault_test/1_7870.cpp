void kforth_ops_add(KFORTH_OPERATIONS *kfops, char *name, KFORTH_FUNCTION func)
{
	int i;
	int found_empty_slot;

	ASSERT( kfops != NULL );
	ASSERT( name != NULL );
	ASSERT( func != NULL );

	ASSERT( kforth_valid_operator_name(name) );

	found_empty_slot = 0;
	for(i=0; i < KFORTH_OPS_LEN; i++) {
		if( kfops[i].name == NULL ) {
			found_empty_slot = 1;
			break;
		}

		ASSERT( stricmp(name, kfops[i].name) != 0 );
	}

	ASSERT( found_empty_slot );

	kfops[i].name	= name;
	kfops[i].func	= func;
}