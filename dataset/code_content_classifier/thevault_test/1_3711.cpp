void CMaterialSystem::AddRestoreFunc( MaterialBufferRestoreFunc_t func )
{
	// Shouldn't have two copies in our list
	Assert( m_RestoreFunc.Find( func ) == -1 );
	m_RestoreFunc.AddToTail( func );
}