void kforth_mutate_options_defaults(KFORTH_MUTATE_OPTIONS *kfmo)
{
	KFORTH_MUTATE_OPTIONS *tmp;

	ASSERT( kfmo != NULL );

	tmp = kforth_mutate_options_make(100, 10, 0.25, 0.02, 0.06, 0.02, 0.02, 0.02,
						EvolveMaxOpcodes() );

	*kfmo = *tmp;

	kforth_mutate_options_delete(tmp);
}