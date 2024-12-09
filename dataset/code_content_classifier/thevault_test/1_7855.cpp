bool OrganismFinder::evalute(KFORTH_MACHINE *kfm, ORGANISM *o)
{
	KFORTH_INTEGER val;
	int n;

	ASSERT( kfm != NULL );
	ASSERT( o != NULL );

	organism = o;
	kforth_machine_reset(kfm);

	//
	// Run machine until terminated, or number of
	// steps exceeds 1,000.
	//
	for(n=0; n < 1000; n++) {
		kforth_machine_execute(kfm);
		if( kfm->terminated ) {
			break;
		}
	}

	if( kfm->terminated ) {
		if( kfm->data_stack_size == 1 ) {
			val = kforth_data_stack_pop(kfm);
			if( val == 0 ) {
				// non-match
				return false;
			} else {
				// match
				return true;
			}
		} else {
			//
			// expression terminated but data stack is
			// something other than 1 in length, we
			// will treat this case as false.
			//
			return false;
		}
	} else {
		//
		// somehow the damn expression never finished within
		// 1000 steps without terminated. Therefore we
		// just assume a bug and return false.
		// A non-looping, non-recursive
		// expression should always terminate.
		//
		return false;
	}
}