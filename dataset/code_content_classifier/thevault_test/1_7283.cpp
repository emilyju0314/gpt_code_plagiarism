static bool canCoalesce( Node *a,Node *b ){
	assert( a->_list==_coalesce && (b->_list==_coalesce||b->_list==_freeze||b->_list==_colored) );

	if( b->colored() ) return false;

	NodeIter it;

	bool briggs;

	//Briggs...
	int n=0;
	for( it=a->edges.begin();it!=a->edges.end();++it ){
		Node *t=(*it);
		if( t->sigDegree() ) ++n;
	}
	for( it=b->edges.begin();it!=b->edges.end();++it ){
		Node *t=(*it);
		if( t->sigDegree() && !t->edges.count(a) ) ++n;
	}
	briggs=n<a->colors();

	return briggs;
}