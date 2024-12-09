bool CWeaponFrag::Holster( CBaseCombatWeapon *pSwitchingTo )
{
	m_bRedraw = false;

	return BaseClass::Holster( pSwitchingTo );
}