static void combine( Node *a,Node *b ){
	assert( a->_list==_coalesce && (b->_list==_coalesce||b->_list==_freeze) );

	a->cant_spill=true;

	b->alias=a;
	b->insert( _coalesced );

	NodeIter it;

	//fix moves
	for( it=b->moves.begin();it!=b->moves.end();++it ){
		Node *t=*it;

		t->moves.erase(b);
		if( t==a ) continue;

		if( !a->edges.count(t) ){
			t->moves.insert(a);
			a->moves.insert(t);
		}else if( !t->moveRelated() ){
			freezeNode(t);
		}
	}

	//fix edges
	for( it=b->edges.begin();it!=b->edges.end();++it ){
		Node *t=(*it);

		t->edges.erase(b);

		if( a->edges.count(t) ){
			decDegree(t);
			continue;
		}

		t->edges.insert(a);
		a->edges.insert(t);
		if( t->_list==_selected ) continue;

		if( !a->colored() ) ++a->degree;
		if( !t->moves.count(a) ) continue;

		t->moves.erase(a);
		a->moves.erase(t);
		if( !t->moveRelated() )	freezeNode(t);
	}

	a->usage+=b->usage;
	if( !a->moveRelated() ) freezeNode( a );
}