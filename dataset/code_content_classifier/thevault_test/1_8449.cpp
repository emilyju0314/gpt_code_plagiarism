void CSTrooper :: HandleAnimEvent( MonsterEvent_t *pEvent )
{
	Vector	vecShootDir;
	Vector	vecShootOrigin;

	switch( pEvent->event )
	{
		case STROOPER_AE_DROP_GUN:
			{
			Vector	vecGunPos;
			Vector	vecGunAngles;

			GetAttachment( 0, vecGunPos, vecGunAngles );

			// switch to body group with no gun.
			//SetBodygroup( GUN_NONE, GUN_NONE );
			pev->body = 1;

			// now spawn a gun.
		
				 //DropItem( "weapon_9mmAR", vecGunPos, vecGunAngles );
				//CBaseEntity *pChild = CBaseEntity::Create( "monster_shockroach", pev->origin, pev->angles, edict() );
			}
			break;

		case STROOPER_AE_RELOAD:
			m_cAmmoLoaded = m_cClipSize;
			ClearConditions(bits_COND_NO_AMMO_LOADED);
			break;

		case STROOPER_AE_GREN_TOSS:
		{
			UTIL_MakeVectors( pev->angles );
			// CGrenade::ShootTimed( pev, pev->origin + gpGlobals->v_forward * 34 + Vector (0, 0, 32), m_vecTossVelocity, 3.5 );
			CSpore::Spore( pev, GetGunPosition(), m_vecTossVelocity, 3.5 );

			m_fThrowGrenade = FALSE;
			m_flNextGrenadeCheck = gpGlobals->time + 6;// wait six seconds before even looking again to see if a grenade can be thrown.
			// !!!LATER - when in a group, only try to throw grenade if ordered.
		}
		break;

		case STROOPER_AE_GREN_DROP:
		{
			UTIL_MakeVectors( pev->angles );
			CSpore::Spore( pev, pev->origin + gpGlobals->v_forward * 17 - gpGlobals->v_right * 27 + gpGlobals->v_up * 6, g_vecZero, 3 );
		}
		break;

		case STROOPER_AE_BURST1:
		{
				Shoot();

				// the first round of the three round burst plays the sound and puts a sound in the world sound list.
					EMIT_SOUND( ENT(pev), CHAN_WEAPON, "shocktrooper/shock_trooper_attack.wav", 1, ATTN_NORM );
		
			CSoundEnt::InsertSound ( bits_SOUND_COMBAT, pev->origin, 384, 0.3 );
		}
		break;

		case STROOPER_AE_BURST2:
		case STROOPER_AE_BURST3:
			Shoot();
			break;

		case STROOPER_AE_KICK:
		{
			CBaseEntity *pHurt = Kick();

			if ( pHurt )
			{
				// SOUND HERE!
				UTIL_MakeVectors( pev->angles );
				pHurt->pev->punchangle.x = 15;
				pHurt->pev->velocity = pHurt->pev->velocity + gpGlobals->v_forward * 100 + gpGlobals->v_up * 50;
				pHurt->TakeDamage( pev, pev, gSkillData.shocktrooperDmgKick, DMG_CLUB );
			}
		}
		break;

		case STROOPER_AE_CAUGHT_ENEMY:
		{
			if ( FOkToSpeak() )
			{
				SENTENCEG_PlayRndSz(ENT(pev), "ST_ALERT", STROOPER_SENTENCE_VOLUME, TROOPER_ATTN, 0, m_voicePitch);
				 JustSpoke();
			}

		}

		default:
			CSquadMonster::HandleAnimEvent( pEvent );
			break;
	}
}