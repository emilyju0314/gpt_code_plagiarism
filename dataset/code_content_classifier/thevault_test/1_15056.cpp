void DailyUpdateOfInsuredMercs()
{
	FOR_EACH_IN_TEAM(s, OUR_TEAM)
	{
		//if the merc has life insurance
		if (s->usLifeInsurance)
		{
			//if the merc wasn't just hired
			if ((INT16)GetWorldDay() != s->iStartOfInsuranceContract)
			{
				//if the contract has run out of time
				if (GetTimeRemainingOnSoldiersInsuranceContract(s) <= 0)
				{
					//if the soldier isn't dead
					if (!IsMercDead(GetProfile(s->ubProfile)))
					{
						s->usLifeInsurance = 0;
						s->iTotalLengthOfInsuranceContract = 0;
						s->iStartOfInsuranceContract = 0;
					}
				}
			}
		}
	}
}