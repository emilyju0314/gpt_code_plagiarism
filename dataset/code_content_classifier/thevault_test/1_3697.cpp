const CEconItemAttributeDefinition *CEconItemSchema::GetAttributeDefinition( int iAttribIndex ) const
{
	if ( m_mapAttributesContainer.IsValidIndex( iAttribIndex ) )
		return m_mapAttributesContainer[iAttribIndex];
	return NULL;
}