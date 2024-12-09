KFORTH_MUTATE_OPTIONS *kforth_mutate_options_make(
			int max_code_blocks,
			int max_apply,
			double prob_mutate_codeblock,
			double prob_duplicate,
			double prob_delete,
			double prob_insert,
			double prob_transpose,
			double prob_modify,
			int max_opcodes )
{
	KFORTH_MUTATE_OPTIONS *kfmo;

	ASSERT( max_code_blocks > 0 );
	ASSERT( max_apply >= 0 && max_apply <= MUTATE_MAX_APPLY_LIMIT );
	ASSERT( prob_mutate_codeblock >= 0.0 && prob_mutate_codeblock <= 1.0 );
	ASSERT( prob_duplicate >= 0.0 && prob_duplicate <= 1.0 );
	ASSERT( prob_delete >= 0.0 && prob_delete <= 1.0 );
	ASSERT( prob_insert >= 0.0 && prob_insert <= 1.0 );
	ASSERT( prob_transpose >= 0.0 && prob_transpose <= 1.0 );
	ASSERT( prob_modify >= 0.0 && prob_modify <= 1.0 );
	ASSERT( max_opcodes > 0 && max_opcodes < KFORTH_OPS_LEN );

	kfmo = (KFORTH_MUTATE_OPTIONS *) CALLOC(1, sizeof(KFORTH_MUTATE_OPTIONS));
	ASSERT( kfmo != NULL );

	kfmo->max_code_blocks	= max_code_blocks;
	kfmo->max_apply		= max_apply;
	kfmo->prob_mutate_codeblock = (int) (prob_mutate_codeblock * PROBABILITY_SCALE);
	kfmo->prob_duplicate	= (int) (prob_duplicate * PROBABILITY_SCALE);
	kfmo->prob_delete	= (int) (prob_delete * PROBABILITY_SCALE);
	kfmo->prob_insert	= (int) (prob_insert * PROBABILITY_SCALE);
	kfmo->prob_transpose	= (int) (prob_transpose * PROBABILITY_SCALE);
	kfmo->prob_modify	= (int) (prob_modify * PROBABILITY_SCALE);
	kfmo->max_opcodes	= max_opcodes;

	return kfmo;
}