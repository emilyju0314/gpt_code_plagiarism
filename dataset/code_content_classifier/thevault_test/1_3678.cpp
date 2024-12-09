bool CEconItemSchema::BInitTimedRewards( KeyValues *pKVTimedRewards, CUtlVector<CUtlString> *pVecErrors )
{
	m_vecTimedRewards.Purge();

	// initialize the rewards sections
	if ( NULL != pKVTimedRewards )
	{
		FOR_EACH_TRUE_SUBKEY( pKVTimedRewards, pKVTimedReward )
		{
			int index = m_vecTimedRewards.AddToTail();
			SCHEMA_INIT_SUBSTEP( m_vecTimedRewards[index].BInitFromKV( pKVTimedReward, *this, pVecErrors ) );
		}
	}

	return SCHEMA_INIT_SUCCESS();
}