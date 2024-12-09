static void insert_instruction(KFORTH_PROGRAM *kfp, KFORTH_MUTATE_OPTIONS *kfmo, EVOLVE_RANDOM *er)
{
	int cb, pc, block_len, len, i;
	unsigned char opcode[XLEN];
	KFORTH_INTEGER operand[XLEN];

	ASSERT( kfp != NULL );
	ASSERT( er != NULL );

	cb = CHOOSE(er, 0, kfp->nblocks-1);

	block_len = kfp->block_len[cb];

	/*
	 * Pick 1 to XLEN random instructions.
	 */
	len = CHOOSE(er, 1, XLEN);
	for(i=0; i<len; i++) {
		choose_instruction(er, kfmo, &opcode[i], &operand[i]);
	}

	/*
	 * Grow program to fit len more instructions in 'cb'
	 */
	kfp->opcode[cb] = (unsigned char*)
			REALLOC(kfp->opcode[cb], (block_len+len) * sizeof(unsigned char));

	kfp->operand[cb] = (KFORTH_INTEGER*)
			REALLOC(kfp->operand[cb], (block_len+len) * sizeof(KFORTH_INTEGER));

	kfp->block_len[cb] = block_len + len;

	/*
	 * make gap at 'pc' for len instructions
	 */
	pc = CHOOSE(er, 0, block_len);
	if( pc < block_len ) {
		for(i=block_len+len-1; i > pc+len-1; i--) {
			kfp->opcode[cb][i] = kfp->opcode[cb][i-len];
			kfp->operand[cb][i] = kfp->operand[cb][i-len];
		}
	}

	for(i=0; i < len; i++) {
		kfp->opcode[cb][pc+i] = opcode[i];
		kfp->operand[cb][pc+i] = operand[i];
	}
}