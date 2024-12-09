static void modify_instruction(KFORTH_PROGRAM *kfp, KFORTH_MUTATE_OPTIONS *kfmo, EVOLVE_RANDOM *er)
{
	int cb, pc, block_len, len, i;

	ASSERT( kfp != NULL );
	ASSERT( er != NULL );

	cb = CHOOSE(er, 0, kfp->nblocks-1);

	block_len = kfp->block_len[cb];

	if( block_len == 0 )
		return;

	len = CHOOSE(er, 1, ((block_len < XLEN) ? block_len : XLEN) );

	pc = CHOOSE(er, 0, block_len - len);

	for(i=0; i<len; i++) {
		modify_single_instruction(er, kfmo, kfp, cb, pc+i);
	}
}