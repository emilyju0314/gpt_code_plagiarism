void kforth_machine_delete(KFORTH_MACHINE *kfm)
{
	KFORTH_STACK_NODE *node;

	ASSERT( kfm != NULL );

	while( kfm->call_sp != NULL ) {
		node = kforth_stack_pop(&kfm->call_sp);
		kforth_stack_node_delete(node);
	}
				
	while( kfm->data_sp != NULL ) {
		node = kforth_stack_pop(&kfm->data_sp);
		kforth_stack_node_delete(node);
	}

	FREE( kfm );
}