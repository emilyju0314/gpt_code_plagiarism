bool PM_DoWalk(int pnum, int variant)
{
	if ((DWORD)pnum >= MAX_PLRS) {
		app_fatal("PM_DoWalk: illegal player %d", pnum);
	}

	//Play walking sound effect on certain animation frames
	if (sgOptions.Audio.bWalkingSound) {
		if (plr[pnum]._pAnimFrame == 3
		    || (plr[pnum]._pWFrames == 8 && plr[pnum]._pAnimFrame == 7)
		    || (plr[pnum]._pWFrames != 8 && plr[pnum]._pAnimFrame == 4)) {
			PlaySfxLoc(PS_WALK1, plr[pnum]._px, plr[pnum]._py);
		}
	}

	//"Jog" in town which works by doubling movement speed and skipping every other animation frame
	if (currlevel == 0 && gbRunInTown) {
		if (plr[pnum]._pAnimFrame % 2 == 0) {
			plr[pnum]._pAnimFrame++;
			plr[pnum]._pVar8++;
		}
		if (plr[pnum]._pAnimFrame >= plr[pnum]._pWFrames) {
			plr[pnum]._pAnimFrame = 0;
		}
	}

	//Acquire length of walk animation length (this is 8 for every class, so the AnimLenFromClass array is redundant right now)
	int anim_len = 8;
	if (currlevel != 0) {
		anim_len = AnimLenFromClass[plr[pnum]._pClass];
	}

	//Check if we reached new tile
	if (plr[pnum]._pVar8 >= anim_len) {

		//Update the player's tile position
		switch (variant) {
		case PM_WALK:
			dPlayer[plr[pnum]._px][plr[pnum]._py] = 0;
			if (leveltype != DTYPE_TOWN && pnum == myplr)
				DoUnVision(plr[pnum]._px, plr[pnum]._py, plr[pnum]._pLightRad); // fix for incorrect vision updating
			plr[pnum]._px += plr[pnum]._pVar1;
			plr[pnum]._py += plr[pnum]._pVar2;
			dPlayer[plr[pnum]._px][plr[pnum]._py] = pnum + 1;
			break;
		case PM_WALK2:
			dPlayer[plr[pnum]._pVar1][plr[pnum]._pVar2] = 0;
			break;
		case PM_WALK3:
			dPlayer[plr[pnum]._px][plr[pnum]._py] = 0;
			if (leveltype != DTYPE_TOWN && pnum == myplr)
				DoUnVision(plr[pnum]._px, plr[pnum]._py, plr[pnum]._pLightRad); // fix for incorrect vision updating
			dFlags[plr[pnum]._pVar4][plr[pnum]._pVar5] &= ~BFLAG_PLAYERLR;
			plr[pnum]._px = plr[pnum]._pVar1;
			plr[pnum]._py = plr[pnum]._pVar2;
			dPlayer[plr[pnum]._px][plr[pnum]._py] = pnum + 1;
			break;
		}

		//Update the coordinates for lighting and vision entries for the player
		if (leveltype != DTYPE_TOWN) {
			ChangeLightXY(plr[pnum]._plid, plr[pnum]._px, plr[pnum]._py);
			ChangeVisionXY(plr[pnum]._pvid, plr[pnum]._px, plr[pnum]._py);
		}

		//Update the "camera" tile position
		if (pnum == myplr && ScrollInfo._sdir) {
			ViewX = plr[pnum]._px - ScrollInfo._sdx;
			ViewY = plr[pnum]._py - ScrollInfo._sdy;
		}

		if (plr[pnum].walkpath[0] != WALK_NONE) {
			StartWalkStand(pnum);
		} else {
			StartStand(pnum, (direction)plr[pnum]._pVar3);
		}

		ClearPlrPVars(pnum);

		//Reset the "sub-tile" position of the player's light entry to 0
		if (leveltype != DTYPE_TOWN) {
			ChangeLightOff(plr[pnum]._plid, 0, 0);
		}

		AutoGoldPickup(pnum);
		return true;
	} else { //We didn't reach new tile so update player's "sub-tile" position
		PM_ChangeOffset(pnum);
		return false;
	}
}