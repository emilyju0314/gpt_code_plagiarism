static void kfop_push(KFORTH_MACHINE *kfm)
{
	KFORTH_STACK_NODE *node;
	int cb, pc;

	node = kforth_stack_node_make();

	cb = kfm->cb;
	pc = kfm->pc;

	node->u.data.value = kfm->program->operand[cb][pc];

	kforth_stack_push(&kfm->data_sp, node);
	kfm->data_stack_size += 1;
}