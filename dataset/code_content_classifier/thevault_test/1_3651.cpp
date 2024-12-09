bool CEconCraftingRecipeDefinition::BInitFromKV( KeyValues *pKVRecipe, CEconItemSchema &pschema, CUtlVector<CUtlString> *pVecErrors /* = NULL */ )
{
	m_nDefIndex = Q_atoi( pKVRecipe->GetName() );
	
	// Check for required fields
	SCHEMA_INIT_CHECK( 
		NULL != pKVRecipe->FindKey( "input_items" ), 
		CFmtStr( "Recipe definition %d: Missing required field \"input_items\"", m_nDefIndex ) );

	SCHEMA_INIT_CHECK( 
		NULL != pKVRecipe->FindKey( "output_items" ), 
		CFmtStr( "Recipe definition %d: Missing required field \"output_items\"", m_nDefIndex ) );

	m_bDisabled = pKVRecipe->GetBool( "disabled" );
	m_strName = pKVRecipe->GetString( "name" );	
	m_strN_A = pKVRecipe->GetString( "n_A" );	 
	m_strDescInputs = pKVRecipe->GetString( "desc_inputs" );	
	m_strDescOutputs = pKVRecipe->GetString( "desc_outputs" );	 
	m_strDI_A = pKVRecipe->GetString( "di_A" );	 
	m_strDI_B = pKVRecipe->GetString( "di_B" );	 
	m_strDI_C = pKVRecipe->GetString( "di_C" );	 
	m_strDO_A = pKVRecipe->GetString( "do_A" );	 
	m_strDO_B = pKVRecipe->GetString( "do_B" );	 
	m_strDO_C = pKVRecipe->GetString( "do_C" );	 

	m_bRequiresAllSameClass = pKVRecipe->GetBool( "all_same_class" );
	m_bRequiresAllSameSlot = pKVRecipe->GetBool( "all_same_slot" );
	m_iCacheClassUsageForOutputFromItem = pKVRecipe->GetInt( "add_class_usage_to_output", -1 );
	m_iCacheSlotUsageForOutputFromItem = pKVRecipe->GetInt( "add_slot_usage_to_output", -1 );
	m_iCacheSetForOutputFromItem = pKVRecipe->GetInt( "add_set_to_output", -1 );
	m_bAlwaysKnown = pKVRecipe->GetBool( "always_known", true );
	m_bPremiumAccountOnly = pKVRecipe->GetBool( "premium_only", false );
	m_iCategory = (recipecategories_t)StringFieldToInt( pKVRecipe->GetString("category"), g_szRecipeCategoryStrings, ARRAYSIZE(g_szRecipeCategoryStrings) );
	m_iFilter = pKVRecipe->GetInt( "filter", -1 );

	// Read in all the input items
	KeyValues *pKVInputItems = pKVRecipe->FindKey( "input_items" );
	if ( NULL != pKVInputItems )
	{
		FOR_EACH_TRUE_SUBKEY( pKVInputItems, pKVInputItem )
		{
			int index = m_InputItemsCriteria.AddToTail();
			SCHEMA_INIT_SUBSTEP( m_InputItemsCriteria[index].BInitFromKV( pKVInputItem, pschema ) );

			// Recipes ignore the enabled flag when generating items
			m_InputItemsCriteria[index].SetIgnoreEnabledFlag( true );

			index = m_InputItemDupeCounts.AddToTail();
			m_InputItemDupeCounts[index] = atoi( pKVInputItem->GetName() );
		}
	}

	// Read in all the output items
	KeyValues *pKVOutputItems = pKVRecipe->FindKey( "output_items" );
	if ( NULL != pKVOutputItems )
	{
		FOR_EACH_TRUE_SUBKEY( pKVOutputItems, pKVOutputItem )
		{
			int index = m_OutputItemsCriteria.AddToTail();
			SCHEMA_INIT_SUBSTEP( m_OutputItemsCriteria[index].BInitFromKV( pKVOutputItem, pschema ) );

			// Recipes ignore the enabled flag when generating items
			m_OutputItemsCriteria[index].SetIgnoreEnabledFlag( true );
		}
	}

	GenerateLocStrings();

	return SCHEMA_INIT_SUCCESS();
}