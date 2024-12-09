static void kforth_stack_push(KFORTH_STACK_NODE **sp, KFORTH_STACK_NODE *node)
{
	ASSERT( sp != NULL );
	ASSERT( node != NULL );

	node->next = NULL;
	node->prev = *sp;

	if( *sp != NULL ) {
		ASSERT( (*sp)->next == NULL );
		(*sp)->next = node;
	}
	*sp = node;
}