bool CEconItemSchema::GetKillEaterScoreTypeUseLevelData( uint32 unScoreType ) const
{
	const kill_eater_score_type_t *pScoreType = FindKillEaterScoreType( unScoreType );
	return pScoreType ? pScoreType->m_bUseLevelBlock : false;
}