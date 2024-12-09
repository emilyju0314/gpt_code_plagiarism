static KFORTH_PROGRAM *kforth_merge_with_mask(int mask, KFORTH_PROGRAM *kfp1, KFORTH_PROGRAM *kfp2)
{
	KFORTH_PROGRAM *p, *kfp;
	int cb, pc, len;
	int bit, curmask;

	ASSERT( mask >= 0 && mask <= 0xFFFF );
	ASSERT( kfp1 != NULL );
	ASSERT( kfp2 != NULL );
	ASSERT( kfp1->kfops == kfp2->kfops );

	kfp = (KFORTH_PROGRAM*) CALLOC(1, sizeof(KFORTH_PROGRAM));

	kfp->nblocks = (kfp1->nblocks > kfp2->nblocks) ?
				kfp1->nblocks : kfp2->nblocks;

	kfp->block_len = (int*) CALLOC(kfp->nblocks, sizeof(int));
	kfp->opcode = (unsigned char**) CALLOC(kfp->nblocks, sizeof(unsigned char*));
	kfp->operand = (KFORTH_INTEGER**) CALLOC(kfp->nblocks, sizeof(KFORTH_INTEGER));
	kfp->kfops = kfp1->kfops;

	bit = 0;
	curmask = mask;
	for(cb=0; cb < kfp->nblocks; cb++) {
		
		if( (curmask & 0x0001) == 0 ) {
			if( cb < kfp1->nblocks )
				p = kfp1;
			else
				p = kfp2;
		} else {
			if( cb < kfp2->nblocks )
				p = kfp2;
			else
				p = kfp1;
		}

		len = p->block_len[cb];
		kfp->block_len[cb] = len;
		kfp->opcode[cb] = (unsigned char*) CALLOC(len, sizeof(unsigned char));
		kfp->operand[cb] = (KFORTH_INTEGER*) CALLOC(len, sizeof(KFORTH_INTEGER));

		for(pc=0; pc < len; pc++) {
			kfp->opcode[cb][pc] = p->opcode[cb][pc];
			kfp->operand[cb][pc] = p->operand[cb][pc];
		}

		curmask = curmask >> 1;
		bit += 1;
		if( bit >= 16 ) {
			curmask = mask;
		}
	}

	return kfp;
}