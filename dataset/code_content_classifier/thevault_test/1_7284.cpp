static void freeze(){

	int min=0x7fffffff;
	Node *node=0;
	for( Node *t=_freeze->succ;t!=_freeze;t=t->succ ){
		if( t->degree<min ){
			node=t;
			min=t->degree;
		}
	}

#ifdef _DEBUG_REGALLOC
	cout<<"Freezing:\t"<<node->reg->id<<endl;
#endif

	NodeIter it;
	for( it=node->moves.begin();it!=node->moves.end();++it ){
		Node *t=*it;
		t->moves.erase(node);
		if( !t->moveRelated() ) freezeNode( t );
	}

	node->moves.clear();
	freezeNode( node );
}