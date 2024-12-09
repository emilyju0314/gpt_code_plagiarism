static KFORTH_STACK_NODE *kforth_stack_pop(KFORTH_STACK_NODE **sp)
{
	KFORTH_STACK_NODE *top;

	ASSERT( sp != NULL );
	ASSERT( *sp != NULL );

	top = *sp;
	*sp = (*sp)->prev;
	if( *sp != NULL )
		(*sp)->next = NULL;
	top->prev = NULL;

	return top;
}