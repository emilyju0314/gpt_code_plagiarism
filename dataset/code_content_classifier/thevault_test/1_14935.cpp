FOR_EACH_SOLDIER(s)
		{
			if (!(s->uiStatusFlags & SOLDIER_BOXER)) continue;
			if (GetRoom(s->sGridNo) != BOXING_RING)  continue;

			if (s->uiStatusFlags & SOLDIER_PC)
			{
				if (ubPass == 0) continue; // pass 0, only handle AI
				// put guy under AI control temporarily
				s->uiStatusFlags |= SOLDIER_PCUNDERAICONTROL;
			}
			else
			{
				if (ubPass == 1) continue; // pass 1, only handle PCs
				// reset AI boxer to neutral
				SetSoldierNeutral(s);
				RecalculateOppCntsDueToBecomingNeutral(s);
			}
			CancelAIAction(s);
			s->bAlertStatus = STATUS_GREEN;
			s->bUnderFire   = 0;

			// if necessary, revive boxer so he can leave ring
			if (s->bLife > 0 && (s->bLife < OKLIFE || s->bBreath < OKBREATH))
			{
				s->bLife = __max(OKLIFE * 2, s->bLife);
				if (s->bBreath < 100)
				{
					// deduct -ve BPs to grant some BPs back (properly)
					DeductPoints(s, 0, -100 * (100 - s->bBreath));
				}
				BeginSoldierGetup(s);
			}
		}