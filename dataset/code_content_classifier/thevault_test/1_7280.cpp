static void freezeNode( Node *node ){
	assert( !node->moveRelated() );
	if( node->colored() ) node->insert( _colored );
	else if( node->sigDegree() ) node->insert( _spill );
	else node->insert( _simplify );
}