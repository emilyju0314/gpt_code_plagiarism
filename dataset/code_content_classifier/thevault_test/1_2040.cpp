bool DirectionalGraph::eraseNode( const node_iterator &node ){
	if( nodes.find(*node) == nodes.end() )
		return false;

	return eraseNode(*node);
}