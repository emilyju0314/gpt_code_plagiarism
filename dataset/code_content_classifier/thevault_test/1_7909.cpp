void kforth_delete(KFORTH_PROGRAM *kfp)
{
	int cb;

	ASSERT( kfp != NULL );

	for(cb=0; cb < kfp->nblocks; cb++ ) {
		FREE( kfp->opcode[cb] );
		FREE( kfp->operand[cb] );
	}

	FREE( kfp->opcode );
	FREE( kfp->operand );
	FREE( kfp->block_len );

	FREE( kfp );
}