bool CEconCraftingRecipeDefinition::BDeserializeFromMsg( const CSOItemRecipe & msg )
{
	m_nDefIndex = msg.def_index();
	m_strName = msg.name().c_str();
	m_strN_A = msg.n_a().c_str();
	m_strDescInputs = msg.desc_inputs().c_str();
	m_strDescOutputs = msg.desc_outputs().c_str();
	m_strDI_A = msg.di_a().c_str();
	m_strDI_B = msg.di_b().c_str();
	m_strDI_C = msg.di_c().c_str();
	m_strDO_A = msg.do_a().c_str();
	m_strDO_B = msg.do_b().c_str();
	m_strDO_C = msg.do_c().c_str();

	m_bRequiresAllSameClass = msg.requires_all_same_class();
	m_bRequiresAllSameSlot = msg.requires_all_same_slot();
	m_iCacheClassUsageForOutputFromItem = msg.class_usage_for_output();
	m_iCacheSlotUsageForOutputFromItem = msg.slot_usage_for_output();
	m_iCacheSetForOutputFromItem = msg.set_for_output();

	// Read how many input items there are
	uint32 unCount = msg.input_items_criteria_size();
	m_InputItemsCriteria.SetSize( unCount );
	for ( uint32 i = 0; i < unCount; i++ )
	{
		if ( !m_InputItemsCriteria[i].BDeserializeFromMsg( msg.input_items_criteria( i ) ) )
			return false;
	}

	// Read how many input item dupe counts there are
	unCount = msg.input_item_dupe_counts_size();
	m_InputItemDupeCounts.SetSize( unCount );
	for ( uint32 i = 0; i < unCount; i++ )
	{
		m_InputItemDupeCounts[i] = msg.input_item_dupe_counts( i );
	}

	// Read how many output items there are
	unCount = msg.output_items_criteria_size();
	m_OutputItemsCriteria.SetSize( unCount );
	for ( uint32 i = 0; i < unCount; i++ )
	{
		if ( !m_OutputItemsCriteria[i].BDeserializeFromMsg( msg.output_items_criteria( i ) ) )
			return false;
	}

	GenerateLocStrings();

	return true;
}