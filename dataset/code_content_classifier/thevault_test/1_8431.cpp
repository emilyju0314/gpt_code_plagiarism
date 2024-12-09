void CWretch::VehicleLeapAttack( void )
{
	CBaseEntity *pEnemy = GetEnemy();
	if ( pEnemy == NULL )
		return;

	Vector vecEnemyPos;
	UTIL_PredictedPosition( pEnemy, 1.0f, &vecEnemyPos );

	// Move
	SetGroundEntity( NULL );
	BeginAttackJump();
	LeapAttackSound();

	// Take him off ground so engine doesn't instantly reset FL_ONGROUND.
	UTIL_SetOrigin( this, GetLocalOrigin() + Vector( 0 , 0 , 1 ));

	// FIXME: This should be the exact position we'll enter at, but this approximates it generally
	//vecEnemyPos[2] += 16;

	Vector vecMins = GetHullMins();
	Vector vecMaxs = GetHullMaxs();
	Vector vecJumpDir = VecCheckToss( this, GetAbsOrigin(), vecEnemyPos, 0.1f, 1.0f, false, &vecMins, &vecMaxs );

	SetAbsVelocity( vecJumpDir );
	m_flNextAttack = gpGlobals->curtime + 2.0f;
	SetTouch( &CWretch::VehicleLeapAttackTouch );
}