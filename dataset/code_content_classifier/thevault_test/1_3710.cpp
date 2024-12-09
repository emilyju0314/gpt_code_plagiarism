void CMaterialSystem::AddReleaseFunc( MaterialBufferReleaseFunc_t func )
{
	// Shouldn't have two copies in our list
	Assert( m_ReleaseFunc.Find( func ) == -1 );
	m_ReleaseFunc.AddToTail( func );
}