void kforth_machine_execute(KFORTH_MACHINE *kfm)
{
	int cb, pc;
	int nblocks, block_len;
	int opcode;
	KFORTH_FUNCTION func;
	KFORTH_STACK_NODE *node;

	ASSERT( kfm != NULL );
	ASSERT( kfm->terminated == 0 );

	cb = kfm->cb;
	pc = kfm->pc;

	nblocks = kfm->program->nblocks;
	ASSERT( cb < nblocks );

	block_len = kfm->program->block_len[cb];

	if( pc >= block_len ) {
		/*
		 * return from code block
		 */
		if( kfm->call_sp != NULL ) {
			node = kforth_stack_pop(&kfm->call_sp);
			kfm->call_stack_size -= 1;
			ASSERT( kfm->call_stack_size >= 0 );

			kfm->cb = node->u.call.cb;
			kfm->pc = node->u.call.pc+1;

			kforth_stack_node_delete(node);

		} else {
#ifdef GROW_USING_CB
			// not true when GROW calls a cb.
#else
			ASSERT( cb == 0 );
#endif


			kfm->terminated = 1;
		}

	} else {
		/*
		 * Normal instruction
		 */
		opcode = kfm->program->opcode[cb][pc];
		ASSERT( opcode >= 0 && opcode < KFORTH_OPS_LEN );

		func = kfm->program->kfops[opcode].func;

		(*func)(kfm);

		kfm->pc = kfm->pc + 1;
	}
}