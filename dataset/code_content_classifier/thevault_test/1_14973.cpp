static void UpDateStateOfStartButton(void)
{
	if (gubPersonnelInfoState == PRSNL_INV)
	{
		giPersonnelATMStartButton[PERSONNEL_INV_BTN       ]->uiFlags |=  BUTTON_CLICKED_ON;
		giPersonnelATMStartButton[PERSONNEL_STAT_BTN      ]->uiFlags &= ~BUTTON_CLICKED_ON;
		giPersonnelATMStartButton[PERSONNEL_EMPLOYMENT_BTN]->uiFlags &= ~BUTTON_CLICKED_ON;
	}
	else if (gubPersonnelInfoState == PRSNL_STATS)
	{
		giPersonnelATMStartButton[PERSONNEL_INV_BTN       ]->uiFlags &= ~BUTTON_CLICKED_ON;
		giPersonnelATMStartButton[PERSONNEL_STAT_BTN      ]->uiFlags |=  BUTTON_CLICKED_ON;
		giPersonnelATMStartButton[PERSONNEL_EMPLOYMENT_BTN]->uiFlags &= ~BUTTON_CLICKED_ON;
	}
	else
	{
		giPersonnelATMStartButton[PERSONNEL_STAT_BTN      ]->uiFlags &= ~BUTTON_CLICKED_ON;
		giPersonnelATMStartButton[PERSONNEL_INV_BTN       ]->uiFlags &= ~BUTTON_CLICKED_ON;
		giPersonnelATMStartButton[PERSONNEL_EMPLOYMENT_BTN]->uiFlags |= BUTTON_CLICKED_ON;
	}

	// if in current mercs and the currently selected guy is valid, enable button, else disable it
	if (fCurrentTeamMode)
	{
		// is the current guy valid
		if (GetNumberOfMercsDeadOrAliveOnPlayersTeam() > 0)
		{
			EnableButton(giPersonnelATMStartButton[PERSONNEL_STAT_BTN]);
			EnableButton(giPersonnelATMStartButton[PERSONNEL_INV_BTN]);
			EnableButton(giPersonnelATMStartButton[PERSONNEL_EMPLOYMENT_BTN]);

			if (GetSoldierOfCurrentSlot().bAssignment == ASSIGNMENT_POW)
			{
				DisableButton(giPersonnelATMStartButton[PERSONNEL_INV_BTN]);

				if (gubPersonnelInfoState == PRSNL_INV)
				{
					gubPersonnelInfoState = PRSNL_STATS;
					fPausedReDrawScreenFlag = TRUE;
				}
			}
		}
		else
		{
			// not valid, disable
			DisableButton(giPersonnelATMStartButton[PERSONNEL_STAT_BTN]);
			DisableButton(giPersonnelATMStartButton[PERSONNEL_INV_BTN]);
			DisableButton(giPersonnelATMStartButton[PERSONNEL_EMPLOYMENT_BTN]);
		}
	}
	else
	{
		// disable button
		EnableButton(giPersonnelATMStartButton[PERSONNEL_STAT_BTN]);
		DisableButton(giPersonnelATMStartButton[PERSONNEL_INV_BTN]);
		DisableButton(giPersonnelATMStartButton[PERSONNEL_EMPLOYMENT_BTN]);
	}
}