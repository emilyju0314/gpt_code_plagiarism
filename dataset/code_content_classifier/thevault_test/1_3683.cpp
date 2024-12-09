bool CEconItemSchema::BInitRecipes( KeyValues *pKVRecipes, CUtlVector<CUtlString> *pVecErrors )
{
	m_mapRecipes.Purge();

	// initialize the rewards sections
	if ( NULL != pKVRecipes )
	{
		int nHighestRecipeIndex = 0;
		FOR_EACH_TRUE_SUBKEY( pKVRecipes, pKVRecipe )
		{
			int nRecipeIndex = Q_atoi( pKVRecipe->GetName() );

			// Remember highest recipe index so we can make more past that 
			if ( nHighestRecipeIndex < nRecipeIndex + 1 )
			{
				nHighestRecipeIndex = nRecipeIndex + 1;
			}

			int nMapIndex = m_mapRecipes.Find( nRecipeIndex );

			// Make sure the recipe index is correct because we use this index as a reference
			SCHEMA_INIT_CHECK( 
				!m_mapRecipes.IsValidIndex( nMapIndex ),
				CFmtStr( "Duplicate recipe definition (%d)", nRecipeIndex ) );

			// Check to make sure the index is positive
			SCHEMA_INIT_CHECK( 
				nRecipeIndex >= 0,
				CFmtStr( "Recipe definition index %d must be greater than or equal to zero", nRecipeIndex ) );

			CEconCraftingRecipeDefinition *recipeDef = CreateCraftingRecipeDefinition();
			SCHEMA_INIT_SUBSTEP( recipeDef->BInitFromKV( pKVRecipe, *this, pVecErrors ) );

			// On clients, toss out any recipes that aren't always known. (Really, the clients
			// shouldn't ever get these, but just in case.)
#if defined(CLIENT_DLL) || defined(GAME_DLL)
			if ( recipeDef->IsAlwaysKnown() )
#endif // !GC_DLL
			{
#ifdef _DEBUG
				// Sanity check in debug builds so that we know we aren't putting the same recipe in
				// multiple times.
				FOR_EACH_MAP_FAST( m_mapRecipes, i )
				{
					Assert( i != nRecipeIndex );
					Assert( m_mapRecipes[i] != recipeDef );
				}
#endif // _DEBUG

				// Store this recipe.
				m_mapRecipes.Insert( nRecipeIndex, recipeDef );
			}
		}

#ifdef CSTRIKE15
		int nSetCount = GetItemSetCount();
		for ( int i = 0; i < nSetCount; ++i )
		{
			const IEconItemSetDefinition *pSet = GetItemSet( i );
			if ( !pSet || pSet->GetCraftReward() <= 0 )
				continue;

			CEconCraftingRecipeDefinition *recipeDef = CreateCraftingRecipeDefinition();
			SCHEMA_INIT_SUBSTEP( recipeDef->BInitFromSet( pSet, *this, pVecErrors ) );
			recipeDef->SetDefinitionIndex( nHighestRecipeIndex );
			recipeDef->SetFilter( CRAFT_FILTER_COLLECT );

			// Disabled for now until we ship collection badges!
			recipeDef->SetDisabled( true );

			m_mapRecipes.Insert( nHighestRecipeIndex, recipeDef );

			nHighestRecipeIndex++;
		}
#endif //#ifdef CSTRIKE15
	}

	return SCHEMA_INIT_SUCCESS();
}