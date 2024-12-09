static void duplicate_code_block(KFORTH_PROGRAM *kfp, KFORTH_MUTATE_OPTIONS *kfmo, EVOLVE_RANDOM *er)
{
	int cb, nblocks, pc, i, len;
	KFORTH_INTEGER *operand;
	unsigned char *opcode;

	ASSERT( kfp != NULL );
	ASSERT( er != NULL );

	nblocks = kfp->nblocks;

	if( nblocks == 0 )
		return;

	if( nblocks >= kfmo->max_code_blocks )
		return;

	/*
	 * Pick a code block to duplicate (and remember it)
	 */
	cb	= CHOOSE(er, 0, nblocks-1);
	len	= kfp->block_len[cb];
	opcode	= kfp->opcode[cb];
	operand	= kfp->operand[cb];

	/*
	 * Grow program to fit 1 more code block
	 */
	kfp->block_len = (int*)
			REALLOC(kfp->block_len, (nblocks+1) * sizeof(int));

	kfp->opcode = (unsigned char**)
			REALLOC(kfp->opcode, (nblocks+1) * sizeof(unsigned char*));

	kfp->operand = (KFORTH_INTEGER**)
			REALLOC(kfp->operand, (nblocks+1) * sizeof(KFORTH_INTEGER*));

	kfp->nblocks = nblocks+1;

	/*
	 * Shift all code blocks at 'cb'
	 */
	cb = CHOOSE(er, 0, nblocks);
	if( cb < nblocks ) {
		for(i=nblocks; i>cb; i--) {
			kfp->block_len[i]	= kfp->block_len[i-1];
			kfp->opcode[i]		= kfp->opcode[i-1];
			kfp->operand[i]		= kfp->operand[i-1];
		}
	}

	kfp->block_len[cb] = len;
	kfp->opcode[cb] = (unsigned char*) CALLOC(len, sizeof(unsigned char));
	kfp->operand[cb] = (KFORTH_INTEGER*) CALLOC(len, sizeof(KFORTH_INTEGER));

	for(pc=0; pc<len; pc++) {
		kfp->opcode[cb][pc] = opcode[pc];
		kfp->operand[cb][pc] = operand[pc];
	}
}