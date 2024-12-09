void CSDKBot::RunPlayerMove( CUserCmd &cmd, float frametime )
{
	// Store off the globals.. they're gonna get whacked
	float flOldFrametime = gpGlobals->frametime;
	float flOldCurtime = gpGlobals->curtime;

	float flTimeBase = gpGlobals->curtime + gpGlobals->frametime - frametime;
	SetTimeBase( flTimeBase );

	MoveHelperServer()->SetHost( this );

	MDLCACHE_CRITICAL_SECTION();

	PlayerRunCommand( &cmd, MoveHelperServer() );

	// save off the last good usercmd
	SetLastUserCommand( cmd );

	// Clear out any fixangle that has been set
	pl.fixangle = FIXANGLE_NONE;

	// Restore the globals..
	gpGlobals->frametime = flOldFrametime;
	gpGlobals->curtime = flOldCurtime;

#ifdef STUCK_DEBUG
	if (m_collecting)
	{
		while (m_button_history.size() && m_button_history.front().m_time < gpGlobals->curtime - 4)
			m_button_history.pop_front();

		m_button_history.push_back(ButtonHistory());
		m_button_history.back().m_buttons = cmd.buttons;
		m_button_history.back().m_position = GetAbsOrigin();
		m_button_history.back().m_time = gpGlobals->curtime;
		m_button_history.back().m_sliding = m_Shared.IsSliding();
		m_button_history.back().m_flipping = m_Shared.IsWallFlipping();
		m_button_history.back().m_rolling = m_Shared.IsRolling();
		m_button_history.back().m_diving = m_Shared.IsDiving();

		trace_t traceresult;

		Ray_t ray;
		ray.Init( GetAbsOrigin(), GetAbsOrigin(), GetPlayerMins(), GetPlayerMaxs() );
		UTIL_TraceRay( ray, PlayerSolidMask(), this, COLLISION_GROUP_PLAYER_MOVEMENT, &traceresult );

		m_button_history.back().m_stuck = !!traceresult.m_pEnt;
	}
#endif
}