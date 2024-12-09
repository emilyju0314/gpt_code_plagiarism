static void AddTextToMineBox(PopUpBox* const box, INT8 const mine)
{
	UINT8            const  town   = GetTownAssociatedWithMine(mine);
	MINE_STATUS_TYPE const& status = gMineStatus[mine];
	ST::string buf;

	// Name of town followed by "mine"
	buf = ST::format("{} {}", GCM->getTownName(town), pwMineStrings[0]);
	AddMonoString(box, buf);

	AddMonoString(box, ST::null); // Blank line

	AddSectorToBox(box);

	// Mine status
	buf = ST::format("{}:", pwMineStrings[9]);
	AddMonoString(box, buf);
	ST::string status_txt =
		status.fEmpty      ? pwMineStrings[5] : // Abandonded
		status.fShutDown   ? pwMineStrings[6] : // Shut down
		status.fRunningOut ? pwMineStrings[7] : // Running out
		pwMineStrings[8];                       // Producing
	AddSecondColumnMonoString(box, status_txt);

	if (!status.fEmpty)
	{
		// Current production
		buf = ST::format("{}:", pwMineStrings[3]);
		AddMonoString(box, buf);
		UINT32 const predicted_income = PredictDailyIncomeFromAMine(mine);
		AddSecondColumnMonoString(box, SPrintMoney(predicted_income));

		// Potential production
		buf = ST::format("{}:", pwMineStrings[4]);
		AddMonoString(box, buf);
		UINT32 const max_removal = GetMaxDailyRemovalFromMine(mine);
		AddSecondColumnMonoString(box, SPrintMoney(max_removal));

		if (GetMaxPeriodicRemovalFromMine(mine) > 0)
		{ // Production rate (current production as a percentage of potential production)
			buf = ST::format("{}:", pwMineStrings[10]);
			AddMonoString(box, buf);
			buf = ST::format("{}%", predicted_income * 100 / max_removal);
			AddSecondColumnMonoString(box, buf);
		}

		// Town control percentage
		buf = ST::format("{}:", pwMineStrings[12]);
		AddMonoString(box, buf);
		buf = ST::format("{}%", GetTownSectorsUnderControl(town) * 100 / GetTownSectorSize(town));
		AddSecondColumnMonoString(box, buf);

		TOWN_LOYALTY const& loyalty = gTownLoyalty[town];
		if (loyalty.fStarted && gfTownUsesLoyalty[town])
		{ // Town loyalty percentage
			buf = ST::format("{}:", pwMineStrings[13]);
			AddMonoString(box, buf);
			buf = ST::format("{}%", loyalty.ubRating);
			AddSecondColumnMonoString(box, buf);
		}

		// Ore type (silver/gold)
		buf = ST::format("{}:", pwMineStrings[11]);
		AddMonoString(box, buf);
		AddSecondColumnMonoString(box, status.ubMineType == SILVER_MINE ? pwMineStrings[1] : pwMineStrings[2]);
	}

#ifdef _DEBUG
	// Dollar amount remaining in mine
	AddMonoString(box, "Remaining (DEBUG):");
	AddSecondColumnMonoString(box, SPrintMoney(GetTotalLeftInMine(mine)));
#endif
}