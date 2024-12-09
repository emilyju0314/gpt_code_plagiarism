static void insert_code_block(KFORTH_PROGRAM *kfp, KFORTH_MUTATE_OPTIONS *kfmo, EVOLVE_RANDOM *er)
{
	int cb, pc, nblocks, i, len;
	unsigned char opcode;
	KFORTH_INTEGER operand;

	ASSERT( kfp != NULL );
	ASSERT( er != NULL );

	/*
	 * Grow program to fit 1 more code block
	 */
	nblocks = kfp->nblocks;

	if( nblocks >= kfmo->max_code_blocks )
		return;

	kfp->block_len = (int*)
			REALLOC(kfp->block_len, (nblocks+1) * sizeof(int));

	kfp->opcode = (unsigned char**)
			REALLOC(kfp->opcode, (nblocks+1) * sizeof(unsigned char*));

	kfp->operand = (KFORTH_INTEGER**)
			REALLOC(kfp->operand, (nblocks+1) * sizeof(KFORTH_INTEGER*));

	kfp->nblocks = nblocks+1;

	if( nblocks == 0 ) {
		cb = 0;
	} else {
		cb = CHOOSE(er, 0, nblocks);
		if( cb < nblocks ) {
			for(i=nblocks; i>cb; i--) {
				kfp->block_len[i]	= kfp->block_len[i-1];
				kfp->opcode[i]		= kfp->opcode[i-1];
				kfp->operand[i]		= kfp->operand[i-1];
			}
		}
	}

	/*
	 * create code block at 'cb'
	 * Random length between 0 and XLEN.
	 */
	len = CHOOSE(er, 0, XLEN);

	kfp->block_len[cb]	= len;
	kfp->opcode[cb]		= (unsigned char*) CALLOC(len, sizeof(unsigned char));
	kfp->operand[cb]	= (KFORTH_INTEGER*) CALLOC(len, sizeof(KFORTH_INTEGER));

	for(pc=0; pc < len; pc++) {
		choose_instruction(er, kfmo, &opcode, &operand);
		kfp->opcode[cb][pc] = opcode;
		kfp->operand[cb][pc] = operand;
	}

}