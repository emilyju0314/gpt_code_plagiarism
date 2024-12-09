static void transpose_code_block(KFORTH_PROGRAM *kfp, KFORTH_MUTATE_OPTIONS *kfmo, EVOLVE_RANDOM *er)
{
	int cb1, cb2;
	unsigned char *save_opcode;
	KFORTH_INTEGER *save_operand;
	int save_len;

	ASSERT( kfp != NULL );
	ASSERT( er != NULL );

	cb1 = CHOOSE(er, 0, kfp->nblocks-1);
	cb2 = CHOOSE(er, 0, kfp->nblocks-1);

	if( cb1 == cb2 )
		return;

	save_opcode		= kfp->opcode[cb1];
	save_operand		= kfp->operand[cb1];
	save_len		= kfp->block_len[cb1];

	kfp->opcode[cb1]	= kfp->opcode[cb2];
	kfp->operand[cb1]	= kfp->operand[cb2];
	kfp->block_len[cb1]	= kfp->block_len[cb2];

	kfp->opcode[cb2]	= save_opcode;
	kfp->operand[cb2]	= save_operand;
	kfp->block_len[cb2]	= save_len;
}