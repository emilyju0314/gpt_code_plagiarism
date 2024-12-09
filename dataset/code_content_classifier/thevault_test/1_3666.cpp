void CEconItemSchema::MaybeInitFromBuffer( IDelayedSchemaData *pDelayedSchemaData )
{
	// Use whatever our most current data block is.
	if ( m_pDelayedSchemaData )
	{
		delete m_pDelayedSchemaData;
	}

	m_pDelayedSchemaData = pDelayedSchemaData;

#ifdef CLIENT_DLL
	// If we aren't in a game we can parse immediately now.
	if ( !engine->IsInGame() )
	{
		BInitFromDelayedBuffer();
	}
#endif // CLIENT_DLL
}