static void transpose_instruction(KFORTH_PROGRAM *kfp, KFORTH_MUTATE_OPTIONS *kfmo, EVOLVE_RANDOM *er)
{
	int cb1, pc1;
	int cb2, pc2;
	int block_len1, block_len2;
	int len, i;

	unsigned char save_opcode[XLEN];
	KFORTH_INTEGER save_operand[XLEN];

	ASSERT( kfp != NULL );
	ASSERT( er != NULL );

	cb1 = CHOOSE(er, 0, kfp->nblocks-1);
	block_len1 = kfp->block_len[cb1];

	if( block_len1 == 0 )
		return;

	cb2 = CHOOSE(er, 0, kfp->nblocks-1);
	block_len2 = kfp->block_len[cb2];

	if( block_len2 == 0 )
		return;

	/*
	 * compute, len = MIN(XLEN, block_len1, block_len2)
	 */
	if( block_len1 < block_len2 ) {
		len = CHOOSE(er, 1, (block_len1 < XLEN) ? block_len1 : XLEN);
	} else {
		len = CHOOSE(er, 1, (block_len2 < XLEN) ? block_len2 : XLEN);
	}

	pc1 = CHOOSE(er, 0, block_len1-len);
	pc2 = CHOOSE(er, 0, block_len2-len);

	for(i=0; i<len; i++) {
		save_opcode[i] = kfp->opcode[cb1][pc1+i];
		save_operand[i] = kfp->operand[cb1][pc1+i];
	}

	for(i=0; i<len; i++) {
		kfp->opcode[cb1][pc1+i] = kfp->opcode[cb2][pc2+i];
		kfp->operand[cb1][pc1+i] = kfp->operand[cb2][pc2+i];
	}

	for(i=0; i<len; i++) {
		kfp->opcode[cb2][pc2+i] = save_opcode[i];
		kfp->operand[cb2][pc2+i] = save_operand[i];
	}

}