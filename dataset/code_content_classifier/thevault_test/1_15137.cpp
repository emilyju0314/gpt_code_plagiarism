FOR_EACH_MERC(i)
	{
		const SOLDIERTYPE* const pTemp = *i;

		// if this merc is inactive, at base, on assignment, or dead
		if (!pTemp->bLife) continue; // next merc

		// if this merc is neutral/on same side, he's not an opponent
		if ( CONSIDERED_NEUTRAL( pSoldier, pTemp ) || (pSoldier->bSide == pTemp->bSide))
			continue;          // next merc

		pbPersOL = pSoldier->bOppList + pTemp->ubID;
		pbPublOL = gbPublicOpplist[pSoldier->bTeam] + pTemp->ubID;
		psLastLoc = gsLastKnownOppLoc[pSoldier->ubID] + pTemp->ubID;
		pbLastLevel = gbLastKnownOppLevel[pSoldier->ubID] + pTemp->ubID;

		// if this guy's been personally heard within last 3 turns
		if (*pbPersOL < NOT_HEARD_OR_SEEN)
		{
			// calculate how far this noise was, and its relative "importance"
			iDistAway = SpacesAway(pSoldier->sGridNo,*psLastLoc);
			iNoiseValue = (*pbPersOL) * iDistAway;               // always a negative number!

			if (iNoiseValue > iBestValue)
			{
				iBestValue = iNoiseValue;
				sBestGridNo = *psLastLoc;
				bBestLevel = *pbLastLevel;
			}
		}

		// if this guy's been publicly heard within last 3 turns
		if (*pbPublOL < NOT_HEARD_OR_SEEN)
		{
			// calculate how far this noise was, and its relative "importance"
			iDistAway = SpacesAway(pSoldier->sGridNo,gsPublicLastKnownOppLoc[pSoldier->bTeam][pTemp->ubID]);
			iNoiseValue = (*pbPublOL) * iDistAway;               // always a negative number!

			if (iNoiseValue > iBestValue)
			{
				iBestValue = iNoiseValue;
				sBestGridNo = gsPublicLastKnownOppLoc[pSoldier->bTeam][pTemp->ubID];
				bBestLevel = gbPublicLastKnownOppLevel[pSoldier->bTeam][pTemp->ubID];
			}
		}

	}