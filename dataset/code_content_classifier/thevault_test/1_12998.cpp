void TBox :: dump ( dumpInterface* dump ) const
{
	dump->prologue();

	// dump all (relevant) roles
	dumpAllRoles(dump);

	// dump all (relevant) concepts
	for ( c_const_iterator pc = c_begin(); pc != c_end(); ++pc )
		if ( isRelevant(*pc) )
			dumpConcept( dump, *pc );

	for ( i_const_iterator pi = i_begin(); pi != i_end(); ++pi )
		if ( isRelevant(*pi) )
			dumpConcept( dump, *pi );

	// dump GCIs
	if ( getTG() != bpTOP )
	{
		dump->startAx (diImpliesC);
		dump->dumpTop();
		dump->contAx (diImpliesC);
		dumpExpression ( dump, getTG() );
		dump->finishAx (diImpliesC);
	}

	dump->epilogue();
}