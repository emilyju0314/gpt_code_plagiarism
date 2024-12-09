static KFORTH_OPERATIONS *FindOperations(void)
{
	static int first_time = 1;
	static KFORTH_OPERATIONS kfops_table[ KFORTH_OPS_LEN ];
	KFORTH_OPERATIONS *kfops;
	int i;

	if( first_time ) {
		first_time = 0;
		kfops = kforth_ops_make();

		kforth_ops_add(kfops,	"ID",			FindOpcode_ID);
		kforth_ops_add(kfops,	"PARENT1",		FindOpcode_PARENT1);
		kforth_ops_add(kfops,	"PARENT2",		FindOpcode_PARENT2);
		kforth_ops_add(kfops,	"STRAIN",		FindOpcode_STRAIN);
		kforth_ops_add(kfops,	"ENERGY",		FindOpcode_ENERGY);
		kforth_ops_add(kfops,	"GENERATION",		FindOpcode_GENERATION);
		kforth_ops_add(kfops,	"NUM-CELLS",		FindOpcode_NUM_CELLS);
		kforth_ops_add(kfops,	"AGE",			FindOpcode_AGE);
		kforth_ops_add(kfops,	"NCHILDREN",		FindOpcode_NCHILDREN);
		kforth_ops_add(kfops,	"EXECUTING",		FindOpcode_EXECUTING);
		kforth_ops_add(kfops,	"NUM-CB",		FindOpcode_NUM_CB);
		kforth_ops_add(kfops,	"NUM-DEAD",		FindOpcode_NUM_DEAD);
		kforth_ops_add(kfops,	"MAX-ENERGY",		FindOpcode_MAX_ENERGY);
		kforth_ops_add(kfops,	"MIN-ENERGY",		FindOpcode_MIN_ENERGY);
		kforth_ops_add(kfops,	"AVG-ENERGY",		FindOpcode_AVG_ENERGY);
		kforth_ops_add(kfops,	"MAX-AGE",		FindOpcode_MAX_AGE);
		kforth_ops_add(kfops,	"MIN-AGE",		FindOpcode_MIN_AGE);
		kforth_ops_add(kfops,	"AVG-AGE",		FindOpcode_AVG_AGE);
		kforth_ops_add(kfops,	"MAX-NUM-CELLS",	FindOpcode_MAX_NUM_CELLS);



		/*
		 * copy to static table. (so clients of this data structure
		 * won't be required to free it)
		 */
		for(i=0; i < KFORTH_OPS_LEN; i++) {
			kfops_table[i] = kfops[i];
		}

		kforth_ops_delete(kfops);
	}

	return kfops_table;
}