void CEconStyleInfo::BInitFromKV( KeyValues *pKVStyle, CEconItemSchema &pschema, CUtlVector<CUtlString> *pVecErrors )
{
	enum { kInvalidSkinKey = -1, };

	Assert( pKVStyle );

	m_iIndex = atoi( pKVStyle->GetName() );

	// A "skin" entry means "use this index for all of our teams, no matter how many we have".
	int iCommonSkin = pKVStyle->GetInt( "skin", kInvalidSkinKey );
	if ( iCommonSkin != kInvalidSkinKey )
	{
		m_iSkin = iCommonSkin;
	}

	// If we don't have a base entry, we look for a unique entry for each team. This will be
	// handled in a subclass if necessary.

	// Are we hiding additional bodygroups when this style is active?
	KeyValues *pKVHideBodygroups = pKVStyle->FindKey( "additional_hidden_bodygroups" );
	if ( pKVHideBodygroups )
	{
		FOR_EACH_SUBKEY( pKVHideBodygroups, pKVBodygroup )
		{
			m_vecAdditionalHideBodygroups.AddToTail( pKVBodygroup->GetName() );
		}
	}

	// Remaining common properties.
	m_pszName = pKVStyle->GetString( "name", "#TF_UnknownStyle" );
	m_pszBasePlayerModel = pKVStyle->GetString( "model_player", NULL );

	// An alternate icon to use.
	m_iIcon = pKVStyle->GetInt( "alternate_icon", 0 );

	// Unlock rules.
	KeyValues* pUnlockInfo = pKVStyle->FindKey( "unlock" );
	if ( pUnlockInfo )
	{
		m_UnlockInfo.iPrice = pUnlockInfo->GetInt( "price", 0 );
		m_UnlockInfo.pszItemName = pUnlockInfo->GetString( "item", NULL );
		m_UnlockInfo.iStylePreReq = pUnlockInfo->GetInt( "style", 0 );
		m_UnlockInfo.pszAttrib = pUnlockInfo->GetString( "attribute", NULL );
		m_UnlockInfo.iAttribValue = pUnlockInfo->GetInt( "attribute_value", 0 );
	}
}