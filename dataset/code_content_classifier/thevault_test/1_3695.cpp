CEconItemDefinition *CEconItemSchema::GetItemDefinitionMutable( int iItemIndex, bool bNoDefault )
{
#if defined(CLIENT_DLL) || defined(GAME_DLL)
#if !defined(CSTRIKE_DLL)
	AssertMsg( m_pDefaultItemDefinition, "No default item definition set up for item schema." );
#endif // CSTRIKE_DLL
#endif // defined(CLIENT_DLL) || defined(GAME_DLL)

	int iIndex = m_mapItems.Find( iItemIndex );
	if ( m_mapItems.IsValidIndex( iIndex ) )
		return m_mapItems[iIndex]; 

	if ( bNoDefault )
		return NULL;

	if ( m_pDefaultItemDefinition )
		return m_pDefaultItemDefinition;

#if !defined(CSTRIKE_DLL)
	// We shouldn't ever get down here, but all the same returning a valid pointer is very slightly
	// a better plan than returning an invalid pointer to code that won't check to see if it's valid.
	static CEconItemDefinition *s_pEmptyDefinition = CreateEconItemDefinition();
	return s_pEmptyDefinition;
#else
	return NULL;
#endif // CSTRIKE_DLL
}