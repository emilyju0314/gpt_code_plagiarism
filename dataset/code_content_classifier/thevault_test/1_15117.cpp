void MercDailyUpdate()
{
	// if its the first day, leave
	if (GetWorldDay() == 1) return;

	SLOGD("%s - Doing MercDailyUpdate", WORLDTIMESTR.c_str());

	/* if the death rate is very low (this is independent of mercs' personal
	 * deathrate tolerances) */
	if (CalcDeathRate() < 5)
	{
		// everyone gets a morale bonus, which also gets player a reputation bonus.
		HandleMoraleEvent(NULL, MORALE_LOW_DEATHRATE, -1, -1, -1);
	}

	/* add an event so the merc will say the departing warning (2 hours prior to
	 * leaving).  Do so for all time slots they will depart from */
	AddSameDayStrategicEvent(EVENT_MERC_ABOUT_TO_LEAVE, MERC_ARRIVE_TIME_SLOT_1 - 2 * 60, 0);
	AddSameDayStrategicEvent(EVENT_MERC_ABOUT_TO_LEAVE, MERC_ARRIVE_TIME_SLOT_2 - 2 * 60, 0);
	AddSameDayStrategicEvent(EVENT_MERC_ABOUT_TO_LEAVE, MERC_ARRIVE_TIME_SLOT_3 - 2 * 60, 0);

	AddSameDayStrategicEvent(EVENT_BEGIN_CONTRACT_RENEWAL_SEQUENCE, MERC_ARRIVE_TIME_SLOT_1, 0);
	AddSameDayStrategicEvent(EVENT_BEGIN_CONTRACT_RENEWAL_SEQUENCE, MERC_ARRIVE_TIME_SLOT_2, 0);
	AddSameDayStrategicEvent(EVENT_BEGIN_CONTRACT_RENEWAL_SEQUENCE, MERC_ARRIVE_TIME_SLOT_3, 0);

	FOR_EACH_IN_TEAM(s, OUR_TEAM)
	{
		if (s->bAssignment == ASSIGNMENT_POW)
		{
			s->iEndofContractTime += 1440;
		}
		else if (s->bAssignment != IN_TRANSIT)
		{
			//CJC: Reset dialogue flags for quotes that can be said once/day
			s->usQuoteSaidFlags &= ~SOLDIER_QUOTE_SAID_ANNOYING_MERC;
			// ATE: Reset likes gun flag
			s->usQuoteSaidFlags &= ~SOLDIER_QUOTE_SAID_LIKESGUN;
			// ATE; Reset found something nice flag...
			s->usQuoteSaidFlags &= ~SOLDIER_QUOTE_SAID_FOUND_SOMETHING_NICE;

			// ATE: Decrement tolerance value...
			if (--s->bCorpseQuoteTolerance < 0) s->bCorpseQuoteTolerance = 0;

			MERCPROFILESTRUCT& p = GetProfile(s->ubProfile);
			MercProfile const profile(s->ubProfile);

			// CJC: For some personalities, reset personality quote said flag
			switch (p.bPersonalityTrait)
			{
				case HEAT_INTOLERANT:
				case CLAUSTROPHOBIC:
				case NONSWIMMER:
				case FEAR_OF_INSECTS:
					// repeatable once per day
					s->usQuoteSaidFlags &= ~SOLDIER_QUOTE_SAID_PERSONALITY;
					break;

				default: break;
			}

			//ATE: Try to see if our equipment sucks!
			if (SoldierHasWorseEquipmentThanUsedTo(s))
			{
				// Randomly anytime between 6:00, and 10:00
				AddSameDayStrategicEvent(EVENT_MERC_COMPLAIN_EQUIPMENT, 360 + Random(1080), s->ubProfile);
			}

			// increment days served by this grunt
			++p.usTotalDaysServed;

			// player has hired him, so he'll eligible to get killed off on another job
			p.ubMiscFlags3 |= PROFILE_MISC_FLAG3_PLAYER_HAD_CHANCE_TO_HIRE;

			//if the character is an RPC
			if (profile.isRPC())
			{
				//increment the number of days the mercs has been on the team
				++s->iTotalContractLength;

				// The player owes the salary
				INT16 const sSalary    = p.sSalary;
				INT32 iMoneyOwedToMerc = sSalary;

				//if the player owes the npc money, the balance field will be negative
				if (p.iBalance < 0) iMoneyOwedToMerc += -p.iBalance;

				//if the player owes money
				if (iMoneyOwedToMerc != 0)
				{
					//if the player can afford to pay them
					if (LaptopSaveInfo.iCurrentBalance >= iMoneyOwedToMerc)
					{
						//add the transaction to the player
						AddTransactionToPlayersBook(PAYMENT_TO_NPC, s->ubProfile, GetWorldTotalMin(), -iMoneyOwedToMerc);

						// reset the amount, if the player owed money to the npc
						if (p.iBalance < 0) p.iBalance = 0;
					}
					else
					{
						// Display a screen msg indicating that the npc was NOT paid
						ST::string zMoney = SPrintMoney(sSalary);
						ScreenMsg(FONT_MCOLOR_WHITE, MSG_INTERFACE, st_format_printf(pMessageStrings[MSG_CANT_AFFORD_TO_PAY_NPC_DAILY_SALARY_MSG], p.zNickname, zMoney));

						/* if the merc hasnt been paid for NUM_DAYS_TILL_UNPAID_RPC_QUITS
						 * days, the merc will quit */
						if (p.iBalance - sSalary <= -(sSalary * NUM_DAYS_TILL_UNPAID_RPC_QUITS))
						{
							// Set it up so the merc quits
							MercsContractIsFinished(s);
						}
						else
						{
							//set how much money the player owes the merc
							p.iBalance -= sSalary;

							// Add even for displaying a dialogue telling the player this....
							AddSameDayStrategicEvent(EVENT_RPC_WHINE_ABOUT_PAY, MERC_ARRIVE_TIME_SLOT_1, s->ubID);
						}
					}
				}
			}

			DailyMoraleUpdate(s);
			CheckIfMercGetsAnotherContract(*s);
		}

		// if active, here, & alive (POW is ok, don't care)
		if (s->bAssignment != ASSIGNMENT_DEAD &&
				s->bAssignment != IN_TRANSIT)
		{
			// increment the "man days" played counter for each such merc in the player's employment
			++gStrategicStatus.uiManDaysPlayed;
		}
	}

	/* Determine for all MERC mercs, whether they should levae, because the
	 * player refused to pay */
	if (LaptopSaveInfo.gubPlayersMercAccountStatus == MERC_ACCOUNT_INVALID)
	{
		FOR_EACH_IN_TEAM(s, OUR_TEAM)
		{
			if (s->bAssignment         == ASSIGNMENT_POW)  continue;
			if (s->bAssignment         == IN_TRANSIT)      continue;
			if (s->ubWhatKindOfMercAmI != MERC_TYPE__MERC) continue;
			if (s->bLife               <  CONSCIOUSNESS)   continue;
			MercsContractIsFinished(s);
		}
	}

	for (INT32 cnt = 0; cnt < NUM_PROFILES; ++cnt)
	{
		MERCPROFILESTRUCT& p = GetProfile(cnt);

		// dead guys don't do nuthin' !
		if (p.bMercStatus == MERC_IS_DEAD) continue;

		//Every day reset this variable
		p.uiPrecedentQuoteSaid = 0;

		// skip anyone currently on the player's team
		if (IsMercOnTeam(cnt)) continue;

		if (IsProfileIdAnAimOrMERCMerc((UINT8) cnt) && p.bMercStatus != MERC_RETURNING_HOME)
		{
			// check if any of his stats improve through working or training
			HandleUnhiredMercImprovement(p);

			// if he's working on another job
			if (p.bMercStatus == MERC_WORKING_ELSEWHERE)
			{
				// check if he's killed
				HandleUnhiredMercDeaths(cnt);
			}
		}

		// if merc is currently unavailable
		if (p.uiDayBecomesAvailable > 0)
		{
			if (--p.uiDayBecomesAvailable == 0 &&    // Check to see if the merc has become available
					p.bMercStatus != MERC_FIRED_AS_A_POW) // if the merc CAN become ready
			{
				p.bMercStatus = MERC_OK;

				// if the player has left a message for this merc
				if (p.ubMiscFlags3 & PROFILE_MISC_FLAG3_PLAYER_LEFT_MSG_FOR_MERC_AT_AIM)
				{
					//remove the Flag, so if the merc goes on another assignment, the player can leave an email.
					p.ubMiscFlags3 &= ~PROFILE_MISC_FLAG3_PLAYER_LEFT_MSG_FOR_MERC_AT_AIM;

					// TO DO: send E-mail to player telling him the merc has returned from an assignment
					AddEmail(AIM_REPLY_BARRY + cnt * AIM_REPLY_LENGTH_BARRY, AIM_REPLY_LENGTH_BARRY, 6 + cnt, GetWorldTotalMin());
				}
			}
		}
		else	// was already available today
		{
			if (IsProfileIdAnAimOrMERCMerc((UINT8) cnt))
			{
				// check to see if he goes on another assignment
				UINT32 uiChance;
				if (cnt < MAX_NUMBER_MERCS)
				{ // A.I.M. merc
					uiChance = 2 * p.bExpLevel;

					// player has now had a chance to hire him, so he'll eligible to get killed off on another job
					p.ubMiscFlags3 |= PROFILE_MISC_FLAG3_PLAYER_HAD_CHANCE_TO_HIRE;
				}
				else
				{ // M.E.R.C. merc - very rarely get other work
					uiChance = 1 * p.bExpLevel;

					// player doesn't have a chance to hire any M.E.R.C's until after Speck's E-mail is sent
					if (GetWorldDay() > DAYS_TIL_M_E_R_C_AVAIL)
					{
						// player has now had a chance to hire him, so he'll eligible to get killed off on another job
						p.ubMiscFlags3 |= PROFILE_MISC_FLAG3_PLAYER_HAD_CHANCE_TO_HIRE;
					}
				}

				if (Random(100) < uiChance)
				{
					p.bMercStatus = MERC_WORKING_ELSEWHERE;
					p.uiDayBecomesAvailable = 1 + Random(6 + (p.bExpLevel / 2)); // 1-(6 to 11) days
				}
			}
		}

		// Decrement morale hangover (merc appears hirable, he just gives lame refusals during this time, though)
		if (p.ubDaysOfMoraleHangover > 0) --p.ubDaysOfMoraleHangover;
	}

	HandleSlayDailyEvent();
	ReBuildCharactersList();
}