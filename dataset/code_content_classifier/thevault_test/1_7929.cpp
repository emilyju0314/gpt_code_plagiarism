void kforth_mutate(KFORTH_PROGRAM *kfp,
			KFORTH_MUTATE_OPTIONS *kfmo,
			EVOLVE_RANDOM *er)
{
	long x;
	int mutate_code_block;
	int napply, i;

	ASSERT( kfp != NULL );
	ASSERT( kfmo != NULL );
	ASSERT( er != NULL );
	ASSERT( kfp->nblocks > 0 );

	if( kfmo->max_apply == 1 ) {
		napply = 1;

	} else if( kfmo->max_apply == 0 ) {
		return;

	} else {
		napply = CHOOSE(er, 1, kfmo->max_apply);
	}

	for(i=0; i < napply; i++) {
		/*
		 * Mutate at codeblock-level or instruction-level?
		 */
		x = CHOOSE(er, 0, PROBABILITY_SCALE);
		if( x < kfmo->prob_mutate_codeblock )
			mutate_code_block = 1;
		else
			mutate_code_block = 0;

		/*
		 * Do Duplication?
		 */
		x = CHOOSE(er, 0, PROBABILITY_SCALE);
		if( x < kfmo->prob_duplicate ) {
			if( mutate_code_block )
				duplicate_code_block(kfp, kfmo, er);
			else
				duplicate_instruction(kfp, kfmo, er);
		}

		/*
		 * Do Deletion?
		 */
		x = CHOOSE(er, 0, PROBABILITY_SCALE);
		if( x < kfmo->prob_delete ) {
			if( mutate_code_block )
				delete_code_block(kfp, kfmo, er);
			else
				delete_instruction(kfp, kfmo, er);
		}

		/*
		 * Do Insertion?
		 */
		x = CHOOSE(er, 0, PROBABILITY_SCALE);
		if( x < kfmo->prob_insert ) {
			if( mutate_code_block )
				insert_code_block(kfp, kfmo, er);
			else
				insert_instruction(kfp, kfmo, er);
		}

		/*
		 * Do Transposition?
		 */
		x = CHOOSE(er, 0, PROBABILITY_SCALE);
		if( x < kfmo->prob_transpose ) {
			if( mutate_code_block )
				transpose_code_block(kfp, kfmo, er);
			else
				transpose_instruction(kfp, kfmo, er);
		}

		/*
		 * Do Modification?
		 */
		x = CHOOSE(er, 0, PROBABILITY_SCALE);
		if( x < kfmo->prob_modify ) {
			if( mutate_code_block )
				modify_code_block(kfp, kfmo, er);
			else
				modify_instruction(kfp, kfmo, er);
		}

	}

#if 0
	/* EXPERIMENTAL IDEA, NOT RELEASED TO PUBLIC YET */
	/*
	 * remove any empty code blocks at the end of the program.
	 * Incomming program (before mutations) shouldn't have any empty
	 * trailing code blocks. This will truncate just those
	 * that were added by the mutation operations.
	 *
	 */
	{
		int cb;

		cb = kfp->nblocks-1;
		while( cb >= 1 && kfp->block_len[cb] == 0 ) {
			FREE(kfp->opcode[cb]);
			FREE(kfp->operand[cb]);
			cb--;
		}
		kfp->nblocks = cb+1;
	}
	
#endif
	

}