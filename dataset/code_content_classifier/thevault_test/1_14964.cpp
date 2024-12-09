void HandleEnricoEmail(void)
{
	UINT8 ubCurrentProgress = CurrentPlayerProgressPercentage();
	UINT8 ubHighestProgress = HighestPlayerProgressPercentage();

	// if creatures have attacked a mine (doesn't care if they're still there or not at the moment)
	if (HasAnyMineBeenAttackedByMonsters() && !(gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_SENT_CREATURES))
	{
		AddEmail(ENRICO_CREATURES, ENRICO_CREATURES_LENGTH, MAIL_ENRICO, GetWorldTotalMin());
		gStrategicStatus.usEnricoEmailFlags |= ENRICO_EMAIL_SENT_CREATURES;
		return;	// avoid any other E-mail at the same time
	}


	if ((ubCurrentProgress >= SOME_PROGRESS_THRESHOLD) && !(gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_SENT_SOME_PROGRESS))
	{
		AddEmail(ENRICO_PROG_20, ENRICO_PROG_20_LENGTH, MAIL_ENRICO, GetWorldTotalMin());
		gStrategicStatus.usEnricoEmailFlags |= ENRICO_EMAIL_SENT_SOME_PROGRESS;
		return;	// avoid any setback E-mail at the same time
	}

	if ((ubCurrentProgress >= ABOUT_HALFWAY_THRESHOLD) && !(gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_SENT_ABOUT_HALFWAY))
	{
		AddEmail(ENRICO_PROG_55, ENRICO_PROG_55_LENGTH, MAIL_ENRICO, GetWorldTotalMin());
		gStrategicStatus.usEnricoEmailFlags |= ENRICO_EMAIL_SENT_ABOUT_HALFWAY;
		return;	// avoid any setback E-mail at the same time
	}

	if ((ubCurrentProgress >= NEARLY_DONE_THRESHOLD) && !(gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_SENT_NEARLY_DONE))
	{
		AddEmail(ENRICO_PROG_80, ENRICO_PROG_80_LENGTH, MAIL_ENRICO, GetWorldTotalMin());
		gStrategicStatus.usEnricoEmailFlags |= ENRICO_EMAIL_SENT_NEARLY_DONE;
		return;	// avoid any setback E-mail at the same time
	}

	// test for a major setback OR a second minor setback
	if ((((ubHighestProgress - ubCurrentProgress) >= MAJOR_SETBACK_THRESHOLD) ||
		(((ubHighestProgress - ubCurrentProgress) >= MINOR_SETBACK_THRESHOLD) && (gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_FLAG_SETBACK_OVER))) &&
		!(gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_SENT_MAJOR_SETBACK))
	{
		AddEmail(ENRICO_SETBACK, ENRICO_SETBACK_LENGTH, MAIL_ENRICO, GetWorldTotalMin());
		gStrategicStatus.usEnricoEmailFlags |= ENRICO_EMAIL_SENT_MAJOR_SETBACK;
	}
	else
	// test for a first minor setback
	if (((ubHighestProgress - ubCurrentProgress) >= MINOR_SETBACK_THRESHOLD) &&
		!(gStrategicStatus.usEnricoEmailFlags & (ENRICO_EMAIL_SENT_MINOR_SETBACK | ENRICO_EMAIL_SENT_MAJOR_SETBACK)))
	{
		AddEmail(ENRICO_SETBACK_2, ENRICO_SETBACK_2_LENGTH, MAIL_ENRICO, GetWorldTotalMin());
		gStrategicStatus.usEnricoEmailFlags |= ENRICO_EMAIL_SENT_MINOR_SETBACK;
	}
	else
	// if player is back at his maximum progress after having suffered a minor setback
	if ((ubHighestProgress == ubCurrentProgress) && (gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_SENT_MINOR_SETBACK))
	{
		// remember that the original setback has been overcome, so another one can generate another E-mail
		gStrategicStatus.usEnricoEmailFlags |= ENRICO_EMAIL_FLAG_SETBACK_OVER;
	}
	else if ( GetWorldDay() > (UINT32) (gStrategicStatus.usLastDayOfPlayerActivity) )
	{
		INT8			bComplaint = 0;
		UINT8			ubTolerance;

		gStrategicStatus.ubNumberOfDaysOfInactivity++;
		ubTolerance = LackOfProgressTolerance();

		if ( gStrategicStatus.ubNumberOfDaysOfInactivity >= ubTolerance )
		{
			if ( gStrategicStatus.ubNumberOfDaysOfInactivity == ubTolerance )
			{
				// send email
				if ( !(gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_SENT_LACK_PROGRESS1 ) )
				{
					bComplaint = 1;
				}
				else if ( !(gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_SENT_LACK_PROGRESS2 ) )
				{
					bComplaint = 2;
				}
				else if ( !(gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_SENT_LACK_PROGRESS3 ) )
				{
					bComplaint = 3;
				}
			}
			else if ( gStrategicStatus.ubNumberOfDaysOfInactivity == (UINT32) ubTolerance * 2 )
			{
				// six days? send 2nd or 3rd message possibly
				if ( !(gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_SENT_LACK_PROGRESS2 ) )
				{
					bComplaint = 2;
				}
				else if ( !(gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_SENT_LACK_PROGRESS3 ) )
				{
					bComplaint = 3;
				}

			}
			else if ( gStrategicStatus.ubNumberOfDaysOfInactivity == ubTolerance * 3 )
			{
				// nine days??? send 3rd message possibly
				if ( !(gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_SENT_LACK_PROGRESS3 ) )
				{
					bComplaint = 3;
				}
			}

			if ( bComplaint != 0 )
			{
				switch( bComplaint )
				{
					case 3:
						AddEmail(LACK_PLAYER_PROGRESS_3, LACK_PLAYER_PROGRESS_3_LENGTH, MAIL_ENRICO, GetWorldTotalMin());
						gStrategicStatus.usEnricoEmailFlags |= ENRICO_EMAIL_SENT_LACK_PROGRESS3;
						break;
					case 2:
						AddEmail(LACK_PLAYER_PROGRESS_2, LACK_PLAYER_PROGRESS_2_LENGTH, MAIL_ENRICO, GetWorldTotalMin());
						gStrategicStatus.usEnricoEmailFlags |= ENRICO_EMAIL_SENT_LACK_PROGRESS2;
						break;
					default:
						AddEmail(LACK_PLAYER_PROGRESS_1, LACK_PLAYER_PROGRESS_1_LENGTH, MAIL_ENRICO, GetWorldTotalMin());
						gStrategicStatus.usEnricoEmailFlags |= ENRICO_EMAIL_SENT_LACK_PROGRESS1;
						break;

				}

				AddHistoryToPlayersLog( HISTORY_ENRICO_COMPLAINED, 0, GetWorldTotalMin(), -1, -1 );
			}

			// penalize loyalty!
			if ( gStrategicStatus.usEnricoEmailFlags & ENRICO_EMAIL_SENT_LACK_PROGRESS2 )
			{
				DecrementTownLoyaltyEverywhere( LOYALTY_PENALTY_INACTIVE * (gStrategicStatus.ubNumberOfDaysOfInactivity - LackOfProgressTolerance() + 1) );
			}
			else
			{
				// on first complaint, give a day's grace...
				DecrementTownLoyaltyEverywhere( LOYALTY_PENALTY_INACTIVE * (gStrategicStatus.ubNumberOfDaysOfInactivity - LackOfProgressTolerance() ) );
			}
		}
	}

	// reset # of new sectors visited 'today'
	// grant some leeway for the next day, could have started moving
	// at night...
	gStrategicStatus.ubNumNewSectorsVisitedToday = __min( gStrategicStatus.ubNumNewSectorsVisitedToday, NEW_SECTORS_EQUAL_TO_ACTIVITY ) / 3;
}