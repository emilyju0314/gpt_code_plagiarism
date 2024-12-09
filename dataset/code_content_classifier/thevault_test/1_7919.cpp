static void modify_single_instruction(EVOLVE_RANDOM *er, KFORTH_MUTATE_OPTIONS *kfmo,
				KFORTH_PROGRAM *kfp, int cb, int pc)
{
	int delta;

	ASSERT( er != NULL );
	ASSERT( kfmo != NULL );
	ASSERT( kfp != NULL );
	ASSERT( cb >= 0 && cb < kfp->nblocks );
	ASSERT( pc >= 0 && pc < kfp->block_len[cb] );

	if( kfp->opcode[cb][pc] == 0 ) {
		delta = CHOOSE(er, -XLEN, XLEN);
		if( delta == 0 ) {
			/*
			 * swap sign
		 	 */
			kfp->operand[cb][pc] = -kfp->operand[cb][pc];

		} else {
			/*
			 * Increment or Decrement by 1 - XLEN
			 */
			kfp->operand[cb][pc] += delta;
		}
	} else {
		kfp->opcode[cb][pc] = (unsigned char) CHOOSE(er, 1, kfmo->max_opcodes);
	}

}