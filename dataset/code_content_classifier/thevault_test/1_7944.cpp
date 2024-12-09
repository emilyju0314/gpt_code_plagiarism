void Cell_Simulate(CELL *c)
{
	ORGANISM *o;
	int before, after, usage;

	ASSERT( c != NULL );
	ASSERT( ! c->kfm->terminated );

	o = c->organism;

	before = (c->kfm->call_stack_size + c->kfm->data_stack_size) - NOCOST_STACK;
	if( before < 0 ) {
		before = 0;
	}

	kforth_machine_execute(c->kfm);

	after = (c->kfm->call_stack_size + c->kfm->data_stack_size) - NOCOST_STACK;
	if( after < 0 ) {
		after = 0;
	}

	usage = (after - before);

	if( usage <= o->energy ) {
		o->energy -= usage;
	} else {
		kforth_machine_reset(c->kfm);
		c->kfm->terminated = 1;
		o->energy += before;
	}

}