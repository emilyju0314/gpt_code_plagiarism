const CEconItemDefinition *CEconItemSchema::GetItemDefinitionByMapIndex( int iMapIndex ) const
{
	if ( m_mapItems.IsValidIndex( iMapIndex ) )
		return m_mapItems[iMapIndex];

	return NULL;
}