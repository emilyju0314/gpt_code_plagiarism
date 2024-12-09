void kforth_machine_reset(KFORTH_MACHINE *kfm)
{
	KFORTH_STACK_NODE *node;
	int i;

	ASSERT( kfm != NULL );

	kfm->terminated = 0;

	while( kfm->call_sp != NULL ) {
		node = kforth_stack_pop(&kfm->call_sp);
		kforth_stack_node_delete(node);
	}

	while( kfm->data_sp != NULL ) {
		node = kforth_stack_pop(&kfm->data_sp);
		kforth_stack_node_delete(node);
	}

	kfm->call_stack_size = 0;
	kfm->data_stack_size = 0;

	kfm->cb = 0;
	kfm->pc = 0;

	for(i=0; i<10; i++)
		kfm->R[i] = 0;
}