void CSDKBot::BotThink()
{
	// Make sure we stay being a bot
	AddFlag( FL_FAKECLIENT );

	if ( IsEFlagSet(EFL_BOT_FROZEN) )
		return;

	CUserCmd cmd;
	Q_memset( &cmd, 0, sizeof( cmd ) );

	if ( !IsAlive() )
	{
		HandleRespawn(cmd);
	}
	else if (bot_mimic.GetBool())
	{
		CBasePlayer *pPlayer = UTIL_PlayerByIndex( bot_mimic.GetInt()  );
		if ( pPlayer && pPlayer->GetLastUserCommand() )
		{
			cmd = *pPlayer->GetLastUserCommand();

			ConVarRef bot_mimic_yaw_offset("bot_mimic_yaw_offset");
			cmd.viewangles[YAW] += bot_mimic_yaw_offset.GetFloat();

			if (bot_mimic_flip_pitch.GetBool())
				cmd.viewangles[PITCH] = -cmd.viewangles[PITCH];

			if( bot_crouch.GetInt() )
				cmd.buttons |= IN_DUCK;
		}
	}
	else if (bot_freeze.GetBool())
	{
		if (bot_attack.GetBool())
		{
			if (GetActiveSDKWeapon()->Clip1() == 0)
				cmd.buttons |= IN_RELOAD;
			else if (RandomFloat(0.0,1.0) > 0.5 && gpGlobals->curtime >= GetNextAttack())
				cmd.buttons |= IN_ATTACK;
		}
	}
	else
	{
		trace_t tr_front;
		Vector Forward;
		AngleVectors(GetLocalAngles(), &Forward);
		UTIL_TraceHull( GetLocalOrigin()+Vector(0,0,5), GetLocalOrigin() + Vector(0,0,5) + (Forward * 50), GetPlayerMins(), GetPlayerMaxs(), MASK_PLAYERSOLID, this, COLLISION_GROUP_NONE, &tr_front );

		// enemy acquisition
		if( !GetEnemy() || RecheckEnemy() || !GetEnemy()->IsAlive() )
		{
			if( GetEnemy() && !GetEnemy()->IsAlive() )
				ResetNavigationParams();

			AcquireEnemy();

			m_flTimeToRecheckEnemy = gpGlobals->curtime + 1.0f;
		}

		// assume we have an enemy from now on

		InfoGathering();

		Attack(cmd);

		if( m_flTimeToRecheckStuck < gpGlobals->curtime )
			CheckStuck(cmd);

		if( m_flNextDealObstacles < gpGlobals->curtime )
			DealWithObstacles(tr_front.m_pEnt, cmd);

		Navigation(cmd);

		if (this->m_Shared.IsManteling())
		{
			cmd.buttons |= IN_JUMP;
			cmd.forwardmove = cmd.sidemove = 0;
		}

		CheckNavMeshAttrib(&tr_front, cmd);
	}

#if 0 // debug waypoint related position
	int green = 200;
	for ( int i = 1; i <= gpGlobals->maxClients; i++ )
	{
		CSDKPlayer* pPlayer = ToSDKPlayer( UTIL_PlayerByIndex( i ) );
		if (!pPlayer)
			continue;

		if (!pPlayer->IsObserver())
			continue;

		if (pPlayer->GetObserverTarget() != this)
			continue;

		green = 0;
		break;
	}

	Vector previous = GetAbsOrigin();
	for( int i=0; i<m_Waypoints.Count(); i++ )
	{
		Vector current = m_Waypoints[i].Center;

		NDebugOverlay::Line(previous, current, 100, green, 0, false, -1);
		NDebugOverlay::Cross3DOriented(current, QAngle(0,0,0), 5*(m_Waypoints.Count()-i)+1, 200, 0, 0, false, -1);
		previous = current;
	}
#endif

	RunPlayerMove( cmd, gpGlobals->frametime );
}