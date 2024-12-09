bool CEconCraftingRecipeDefinition::ItemListMatchesInputs( const CUtlVector< CEconItem* > &vecCraftingItems, bool bAllowPartialMatch /*= false*/ ) const
{
	bool bResult = true;

	CUtlVector< uint8 > arrDupesUsed;
	arrDupesUsed.SetCount( m_InputItemsCriteria.Count() );

	uint8 *pDupesUsed = arrDupesUsed.Base();
	memset( pDupesUsed, 0, m_InputItemsCriteria.Count() );

	int nSet = -1;

	if ( ( GetFilter() == CRAFT_FILTER_COLLECT || GetFilter() == CRAFT_FILTER_TRADEUP ) && 
		 vecCraftingItems.Count() > 0 )
	{
		nSet = vecCraftingItems[ 0 ]->GetItemSetIndex();

		if ( nSet < 0 )
		{
			// This item must be in a set!
			return false;
		}
	}

	FOR_EACH_VEC( vecCraftingItems, nItem )
	{
		CEconItem *pEconItem = vecCraftingItems[ nItem ];

#if 0	// Relaxing set restriction on crafting
		if ( nSet >= 0 && pEconItem->GetItemSetIndex() != nSet )
		{
			bResult = false;
			break;
		}
#endif

		// Any items at the top rarity of their set are illegal in crafting
		if ( GetFilter() == CRAFT_FILTER_TRADEUP )
		{
			const IEconItemSetDefinition *pSetDef = GetItemSchema()->GetItemSet( vecCraftingItems[ nItem ]->GetItemSetIndex() );
			if ( !pSetDef ) 
			{
				return false;
			}

			bool bHasItemsAtNextRarityTier = false;
			for ( int i = 0; i < pSetDef->GetItemCount(); ++i )
			{
				if ( pSetDef->GetItemRarity( i ) == pEconItem->GetRarity() + 1 )
				{
					bHasItemsAtNextRarityTier = true;
					break;
				}
			}

			if ( !bHasItemsAtNextRarityTier )
				return false;
		}

		bool bFoundCriteriaMatch = false;

		FOR_EACH_VEC( m_InputItemsCriteria, nCriteria )
		{
			const CItemSelectionCriteria *pCriteria = &( m_InputItemsCriteria[ nCriteria ] );
			if ( !pCriteria )
				continue;

			// Skip if we've used this criteria to the limit
			if ( pDupesUsed[ nCriteria ] >= m_InputItemDupeCounts[ nCriteria ] )
				continue;

			bFoundCriteriaMatch = pCriteria->BEvaluate( pEconItem, *GetItemSchema() );
			if ( bFoundCriteriaMatch )
			{
				pDupesUsed[ nCriteria ]++;
				break;
			}
		}

		if ( !bFoundCriteriaMatch )
		{
			// Did the item not fit any criteria!
			bResult = false;
			break;
		}
	}

	if ( !bAllowPartialMatch )
	{
		// Make sure we've matched ALL the criteria
		FOR_EACH_VEC( m_InputItemsCriteria, nCriteria )
		{
			if ( pDupesUsed[ nCriteria ] < m_InputItemDupeCounts[ nCriteria ] )
			{
				// Not all criteria dupes were matched
				bResult = false;
				break;
			}
		}
	}

	return bResult;
}