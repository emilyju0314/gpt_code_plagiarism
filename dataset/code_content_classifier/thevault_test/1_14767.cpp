static void BtnFirstContactButtonCallback(GUI_BUTTON *btn, INT32 reason)
{
	if (reason & MSYS_CALLBACK_REASON_LBUTTON_UP)
	{
		UINT8	const ubRetValue = btn->GetUserData();

		//gfStopMercFromTalking = TRUE;
		StopMercTalking();

		gfAimMemberCanMercSayOpeningQuote = FALSE;

		if (ubRetValue == 0)
		{
			if (CanMercBeHired())
			{
				gubVideoConferencingMode = AIM_VIDEO_HIRE_MERC_MODE;
			}
		}
		else
		{
			gubVideoConferencingMode = AIM_VIDEO_POPDOWN_MODE;
		}
	}
}