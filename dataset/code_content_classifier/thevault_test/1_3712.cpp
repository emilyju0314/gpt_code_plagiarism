void CMaterialSystem::AddEndFrameCleanupFunc( EndFrameCleanupFunc_t func )
{
	// Shouldn't have two copies in our list
	Assert( m_EndFrameCleanupFunc.Find( func ) == -1 );
	m_EndFrameCleanupFunc.AddToTail( func );
}