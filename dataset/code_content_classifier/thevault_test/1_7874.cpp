static void kfop_print_stack(KFORTH_MACHINE *kfm)
{
	KFORTH_STACK_NODE *node;

	ASSERT( kfm != NULL );

	node = kfm->data_sp;
	if( node ) {
		/* scan to beginning */
		while( node->prev != NULL ) {
			node = node->prev;
		}

		while( node != NULL ) {
#ifndef __linux__
			printf("%I64d\n", node->u.data.value);
#else
			printf("%lld\n", node->u.data.value);
#endif
			node = node->next;
		}
	} else {
		printf("(empty)\n");
	}
}