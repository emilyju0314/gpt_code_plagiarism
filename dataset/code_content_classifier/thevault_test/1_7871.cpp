int kforth_ops_max_opcode(KFORTH_OPERATIONS *kfops)
{
	int i, found_empty_slot;

	ASSERT( kfops != NULL );

	found_empty_slot = 0;
	for(i=0; i < KFORTH_OPS_LEN; i++) {
		if( kfops[i].name == NULL ) {
			found_empty_slot = 1;
			break;
		}
	}

	ASSERT( found_empty_slot );
	ASSERT( i >= 0 );

	return i-1;
}