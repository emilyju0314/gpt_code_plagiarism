void NodeStack::addNode( i32 id, d32 xPos, d32 yPos, d32 xHold, i32 idXHold, 
						d32 yHold, i32 idYHold, d32 zHold, i32 idZHold )
{
	NodeDef node( id, xPos, yPos, xHold, idXHold, yHold, idYHold, zHold, idZHold );
	m_Nodes.push_back( node );
}