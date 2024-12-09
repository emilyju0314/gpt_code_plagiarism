static void modify_code_block(KFORTH_PROGRAM *kfp, KFORTH_MUTATE_OPTIONS *kfmo, EVOLVE_RANDOM *er)
{
	int cb, pc;

	ASSERT( kfp != NULL );
	ASSERT( er != NULL );

	cb = CHOOSE(er, 0, kfp->nblocks-1);

	if( kfp->block_len[cb] == 0 )
		return;

	for(pc=0; pc < kfp->block_len[cb]; pc++) {
		if( kfp->opcode[cb][pc] == 0 ) {
			modify_single_instruction(er, kfmo, kfp, cb, pc);
		}
	}

}