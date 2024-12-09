void CSDKBot::InfoGathering()
{
	if (!GetEnemy())
	{
		m_flBotToEnemyDist = 9999;
		m_flHeightDifToEnemy = 0;
		m_bEnemyOnSights = false;

		m_flDistTraveled += fabs(GetLocalVelocity().Length()); // this is used for stuck checking,
		return;
	}

	m_flBotToEnemyDist = (GetLocalOrigin() - GetEnemy()->GetLocalOrigin()).Length();

	trace_t tr;
	UTIL_TraceHull( EyePosition(), GetEnemy()->EyePosition() - Vector(0,0,20), -BotTestHull, BotTestHull, MASK_SHOT, this, COLLISION_GROUP_NONE, &tr );

	if( tr.m_pEnt == GetEnemy() ) // vision line between both
		m_bEnemyOnSights = true;
	else
		m_bEnemyOnSights = false;

	m_bInRangeToAttack = (m_flBotToEnemyDist < m_flMinRangeAttack) && FInViewCone( GetEnemy() );

	m_flDistTraveled += fabs(GetLocalVelocity().Length()); // this is used for stuck checking,

	m_flHeightDifToEnemy = GetLocalOrigin().z - GetEnemy()->GetLocalOrigin().z;
}