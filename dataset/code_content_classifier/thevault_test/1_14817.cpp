FOR_EACH_IN_TEAM(s, OUR_TEAM)
		{
			// If we are controllable
			if (OkControllableMerc(s) && s->bAssignment == CurrentSquad())
			{
				pValidSoldier = s;
				//This now gets handled by strategic movement.  It is possible that the
				//group won't move instantaneously.
				//s->sSectorX = sNewX;
				//s->sSectorY = sNewY;

				ubDirection = GetInsertionDataFromAdjacentMoveDirection( ubTacticalDirection, sAdditionalData );
				break;
			}
		}