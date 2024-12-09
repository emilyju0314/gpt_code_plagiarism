const CEconCraftingRecipeDefinition *CEconItemSchema::GetRecipeDefinition( int iRecipeIndex ) const
{ 
	int iIndex = m_mapRecipes.Find( iRecipeIndex );
	if ( m_mapRecipes.IsValidIndex( iIndex ) )
		return m_mapRecipes[iIndex]; 
	return NULL;
}