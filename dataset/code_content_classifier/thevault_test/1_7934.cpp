KFORTH_MUTATE_OPTIONS *kforth_mutate_options_copy(KFORTH_MUTATE_OPTIONS *kfmo)
{
	KFORTH_MUTATE_OPTIONS *new_kfmo;

	ASSERT( kfmo != NULL );

	new_kfmo = (KFORTH_MUTATE_OPTIONS *) CALLOC(1, sizeof(KFORTH_MUTATE_OPTIONS));
	ASSERT( new_kfmo != NULL );

	*new_kfmo = *kfmo;

	return new_kfmo;
}