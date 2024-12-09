FOR_EACH(SectorDescriptionInfo const, i, sector_description)
	{
		if (x != i->x || y != i->y) continue;

		// If we're not scifi, skip some
		if (i == &sector_description[3] && !gGameOptions.fSciFi) continue;

		SetSectorFlag(x, y, z, SF_HAVE_USED_GUIDE_QUOTE);

		ts.fCountingDownForGuideDescription = TRUE;
		ts.bGuideDescriptionCountDown       = 4 + Random(5); // 4 to 8 tactical turns
		ts.ubGuideDescriptionToUse          = i->quote;
		ts.bGuideDescriptionSectorX         = x;
		ts.bGuideDescriptionSectorY         = y;

		// Handle guide description (will be needed if a SAM one)
		HandleRPCDescription();
		break;
	}