void C_SDKRootPanel::RenderLetterboxing( void )
{
	C_SDKPlayer* pPlayer = C_SDKPlayer::GetLocalOrSpectatedPlayer();
	C_WeaponSDKBase* pWeapon = pPlayer->GetActiveSDKWeapon();

	ConVarRef spec_freeze_time("spec_freeze_time");
	if (pPlayer && !pPlayer->IsAlive() && pPlayer->GetDeathTime() && gpGlobals->curtime < pPlayer->GetDeathTime() + spec_freeze_time.GetFloat())
		RenderDeathFrame();
	else
		m_flKilledByStartTime = 0;

	float flLetterbox = 0.0;
	if (pPlayer)
	{
		if (pPlayer->m_Shared.GetAimIn() > 0 && pWeapon && (pWeapon->FullAimIn() || pWeapon->HasAimInFireRateBonus() || pWeapon->HasAimInRecoilBonus()))
		{
			flLetterbox = pPlayer->m_Shared.GetAimIn()*2;
			if (flLetterbox > 1)
				flLetterbox = 1;
		}

		if (pPlayer->GetSlowMoMultiplier() < 1)
			flLetterbox = max(flLetterbox, RemapValClamped(pPlayer->GetSlowMoMultiplier(), 1, 0.8f, 0, 1));
	}

	if (!UseVR() && flLetterbox > 0)
	{
		int iWidth = ScreenWidth();
		int iHeight = ScreenHeight();

		int i169Height = iWidth*9/16;
		if (i169Height >= iHeight - iHeight/10)
			i169Height = iHeight - iHeight/10;
		int iBarHeight = ((iHeight - i169Height)/2)*flLetterbox;

		surface()->DrawSetColor(Color(0, 0, 0, 255*flLetterbox));
		surface()->DrawFilledRect( 0, 0, ScreenWidth(), iBarHeight );
		surface()->DrawFilledRect( 0, ScreenHeight()-iBarHeight, ScreenWidth(), ScreenHeight() );
	}
}