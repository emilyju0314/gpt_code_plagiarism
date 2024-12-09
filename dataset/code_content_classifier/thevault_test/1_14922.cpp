FOR_EACH_IN_TEAM(s, OUR_TEAM)
	{
		if (OkControllableMerc(s) &&
			s->fCloseCall &&
			s->bNumHitsThisTurn == 0 &&
			!(s->usQuoteSaidExtFlags & SOLDIER_QUOTE_SAID_EXT_CLOSE_CALL) &&
			Random(3) == 0)
		{
			// say close call quote!
			TacticalCharacterDialogue(s, QUOTE_CLOSE_CALL);
			s->usQuoteSaidExtFlags |= SOLDIER_QUOTE_SAID_EXT_CLOSE_CALL;
		}
		s->fCloseCall = FALSE;
	}