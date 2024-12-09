static void AttackWithVelocity(CFlaregun * flaregun, float projectileVelocity)
{
	CBasePlayer *pOwner = ToBasePlayer(flaregun->GetOwner());

	if (pOwner == NULL)
		return;

	if (flaregun->m_iClip1 <= 0)
	{
		flaregun->SendWeaponAnim(ACT_VM_DRYFIRE);
		pOwner->m_flNextAttack = gpGlobals->curtime + flaregun->SequenceDuration();
		return;
	}

	flaregun->m_iClip1 = flaregun->m_iClip1 - 1;

	flaregun->SendWeaponAnim(ACT_VM_PRIMARYATTACK);
	pOwner->m_flNextAttack = gpGlobals->curtime + 1;

	CFlare *pFlare = CFlareGunProjectile::Create(pOwner->Weapon_ShootPosition(), pOwner->EyeAngles(), pOwner, FLARE_DURATION);

	if (pFlare == NULL)
		return;

	Vector forward;
	pOwner->EyeVectors(&forward);
	forward *= projectileVelocity;
	forward += pOwner->GetAbsVelocity(); // Add the player's velocity to the forward vector so that the flare follows the player's motion
	forward.Normalized();

	pFlare->SetAbsVelocity(forward);
	pFlare->SetGravity(1.0f);
	pFlare->SetFriction(0.85f);
	pFlare->SetMoveType(MOVETYPE_FLYGRAVITY, MOVECOLLIDE_FLY_BOUNCE);

	flaregun->WeaponSound(SINGLE);
}