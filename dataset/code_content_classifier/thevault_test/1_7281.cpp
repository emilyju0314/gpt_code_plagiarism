static void selectNode( Node *node ){
	assert( node->_list==_simplify || node->_list==_spill );
	node->degree=0;
	node->insert( _selected );
	NodeIter it;
	for( it=node->edges.begin();it!=node->edges.end();++it ){
		Node *t=(*it);
		decDegree( t );
	}
}