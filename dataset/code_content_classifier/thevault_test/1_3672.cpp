bool CEconItemSchema::BInitAttributes( KeyValues *pKVAttributes, CUtlVector<CUtlString> *pVecErrors )
{
	// Initialize the attribute definitions
	FOR_EACH_TRUE_SUBKEY( pKVAttributes, pKVAttribute )
	{
		int nAttrIndex = Q_atoi( pKVAttribute->GetName() );
		
		// Make sure the index is positive
		SCHEMA_INIT_CHECK(
			( nAttrIndex >= 0 ) && ( nAttrIndex < 30*1000 ),
			CFmtStr( "Attribute definition index %d must be greater than or equal to zero", nAttrIndex ) );

		if ( !( ( nAttrIndex >= 0 ) && ( nAttrIndex < 30*1000 ) ) )
			continue;

		// Build the direct mapping container
		while ( nAttrIndex >= m_mapAttributesContainer.Count() )
			m_mapAttributesContainer.AddToTail( NULL );
		Assert( nAttrIndex < m_mapAttributesContainer.Count() );

		// Make sure the attribute index is not repeated
		SCHEMA_INIT_CHECK( 
			!m_mapAttributesContainer[nAttrIndex],
			CFmtStr( "Duplicate attribute definition index (%d)", nAttrIndex ) );
		if ( m_mapAttributesContainer[nAttrIndex] )
			continue;

		m_mapAttributesContainer[nAttrIndex] = new CEconItemAttributeDefinition;
		SCHEMA_INIT_SUBSTEP( m_mapAttributesContainer[nAttrIndex]->BInitFromKV( pKVAttribute, *this, pVecErrors ) );
	}

	// Check the integrity of the attribute definitions

	// Check for duplicate attribute definition names
	CUtlRBTree<const char *> rbAttributeNames( CaselessStringLessThan );
	rbAttributeNames.EnsureCapacity( m_mapAttributesContainer.Count() );
	FOR_EACH_VEC( m_mapAttributesContainer, i )
	{
		if ( !m_mapAttributesContainer[i] )
			continue;

		int iIndex = rbAttributeNames.Find( m_mapAttributesContainer[i]->GetDefinitionName() );
		SCHEMA_INIT_CHECK( 
			!rbAttributeNames.IsValidIndex( iIndex ),
			CFmtStr( "Attribute definition %d: Duplicate name \"%s\"", i, m_mapAttributesContainer[i]->GetDefinitionName() ) );
		if( !rbAttributeNames.IsValidIndex( iIndex ) )
			rbAttributeNames.Insert( m_mapAttributesContainer[i]->GetDefinitionName() );
	}

	return SCHEMA_INIT_SUCCESS();
}