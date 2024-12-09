std::vector<NodeStack::NodeDef>::iterator NodeStack::getNodeById( Core::i32 id )
{
	assert( id > -1 );
	for ( std::vector<NodeDef>::iterator it = m_Nodes.begin();
		it != m_Nodes.end();
		++it )
	{
		if ( (*it).getId() == id )
		{
			 return it;
		}
	}
	return m_Nodes.end();
}