static void decDegree( Node *node ){
	//dec degree
	if( --node->degree!=node->colors()-1 ) return;

	//OK node transitioned from sig to insig...

	//move frozen neighbors to coalesce
	NodeIter it;
	for( it=node->edges.begin();it!=node->edges.end();++it ){
		Node *t=(*it);
		if( t->_list==_freeze ) t->insert( _coalesce );
	}

	//simplify if in spill
	if( node->_list==_spill ) node->insert( _simplify );
}