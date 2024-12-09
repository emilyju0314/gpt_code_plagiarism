CEconItemDefinition *CEconItemSchema::GetItemDefinitionByName( const char *pszDefName )
{
    SNPROF(__PRETTY_FUNCTION__);

	if ( m_bSchemaParsingItems )
	{
		AssertMsg( 0, "GetItemDefinitionByName while parsing item definitions. This is not a valid operation." );
		return NULL;
	}

	// This shouldn't happen, but let's not crash if it ever does.
	Assert( pszDefName != NULL );
	if ( pszDefName == NULL )
		return NULL;

	FOR_EACH_MAP_FAST( m_mapItems, i )
	{
		if ( !strcmp( pszDefName, m_mapItems[i]->GetDefinitionName()) )
			return m_mapItems[i]; 
	}
	return NULL;
}