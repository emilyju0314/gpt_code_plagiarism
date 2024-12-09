static KFORTH_STACK_NODE *kforth_stack_node_make(void)
{
	KFORTH_STACK_NODE *node;

	node = (KFORTH_STACK_NODE*) CALLOC(1, sizeof(KFORTH_STACK_NODE));
	ASSERT( node != NULL );

	return node;
}