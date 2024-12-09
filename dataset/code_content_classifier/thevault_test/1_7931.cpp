KFORTH_PROGRAM *kforth_merge(KFORTH_PROGRAM *kfp1, KFORTH_PROGRAM *kfp2)
{
	ASSERT( kfp1 != NULL );
	ASSERT( kfp2 != NULL );
	ASSERT( kfp1->kfops == kfp2->kfops );

	return kforth_merge_with_mask(0xAAAA, kfp1, kfp2);
}