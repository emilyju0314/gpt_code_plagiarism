KFORTH_PROGRAM *kforth_merge_rnd(EVOLVE_RANDOM *er, KFORTH_PROGRAM *kfp1, KFORTH_PROGRAM *kfp2)
{
	int mask;

	ASSERT( er != NULL );
	ASSERT( kfp1 != NULL );
	ASSERT( kfp2 != NULL );
	ASSERT( kfp1->kfops == kfp2->kfops );

	mask = CHOOSE(er, 0x0000, 0xFFFF);

	return kforth_merge_with_mask(mask, kfp1, kfp2);
}