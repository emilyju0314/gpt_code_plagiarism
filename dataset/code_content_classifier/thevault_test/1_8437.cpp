int CSTrooper::IRelationship ( CBaseEntity *pTarget )
{
	if ( FClassnameIs( pTarget->pev, "monster_alien_grunt" ) || ( FClassnameIs( pTarget->pev,  "monster_gargantua" ) ) || ( FClassnameIs( pTarget->pev,  "monster_gargantua_friend" ) ) || ( FClassnameIs( pTarget->pev,  "monster_babygarg" ) ) || ( FClassnameIs( pTarget->pev,  "monster_babygarg_friend" ) ) )
	{
		return R_NM;
	}

	return CSquadMonster::IRelationship( pTarget );
}