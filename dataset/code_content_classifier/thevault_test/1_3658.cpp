void CEconItemDefinition::BInitStylesBlockFromKV( KeyValues *pKVStyles, CEconItemSchema &pschema, AssetInfo *pVisData, CUtlVector<CUtlString> *pVecErrors )
{
	FOR_EACH_SUBKEY( pKVStyles, pKVStyle )
	{
		CEconStyleInfo *pStyleInfo = pschema.CreateEconStyleInfo();
		Assert( pStyleInfo );

		pStyleInfo->BInitFromKV( pKVStyle, pschema, pVecErrors );

		pVisData->m_Styles.AddToTail( pStyleInfo );
	}
}