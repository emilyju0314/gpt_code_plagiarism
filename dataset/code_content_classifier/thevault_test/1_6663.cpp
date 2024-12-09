int
OLSR::node_id(nsaddr_t addr) {
	// Preventing a bad use for this function
        if ((u_int32_t)addr == IP_BROADCAST)
	{
		printf("IP_BROADCAST_ADDR :%d\n",addr);
		return addr;
	}
	// Getting node id
	Node* node = Node::get_node_by_address(addr);
	assert(node != NULL);
	return node->nodeid();
}