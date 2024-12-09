bool CEconItemSchema::BInitBinaryBuffer( CUtlBuffer &buffer, CUtlVector<CUtlString> *pVecErrors /* = NULL */ )
{
	Reset();
	m_pKVRawDefinition = new KeyValues( "CEconItemSchema" );
	m_pKVRawDefinition->UsesEscapeSequences( true );
	if ( m_pKVRawDefinition->ReadAsBinary( buffer ) )
	{
		return BInitSchema( m_pKVRawDefinition, pVecErrors );
	}
	if ( pVecErrors )
	{
		pVecErrors->AddToTail( "Error parsing keyvalues" );
	}
	return false;
}