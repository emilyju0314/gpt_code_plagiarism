void CMaterialSystem::AddEndFramePriorToNextContextFunc( EndFramePriorToNextContextFunc_t func )
{
	// Shouldn't have two copies in our list
	Assert( m_EndFramePriorToNextContextFunc.Find( func ) == m_EndFramePriorToNextContextFunc.InvalidIndex() );
	m_EndFramePriorToNextContextFunc.AddToTail( func );
}