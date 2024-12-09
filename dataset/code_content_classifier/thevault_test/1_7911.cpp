int kforth_program_length(KFORTH_PROGRAM *kfp)
{
	int i, len;

	ASSERT( kfp != NULL );

	len = 0;
	for(i=0; i < kfp->nblocks; i++) {
		len += kfp->block_len[i];
	}

	return len;
}