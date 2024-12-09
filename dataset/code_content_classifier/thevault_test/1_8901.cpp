void StartWalk(int pnum, int xvel, int yvel, int xoff, int yoff, int xadd, int yadd, int mapx, int mapy, direction EndDir, int sdir, int variant)
{
	if ((DWORD)pnum >= MAX_PLRS) {
		app_fatal("StartWalk: illegal player %d", pnum);
	}

	if (plr[pnum]._pInvincible && plr[pnum]._pHitPoints == 0 && pnum == myplr) {
		SyncPlrKill(pnum, -1);
		return;
	}

	SetPlayerOld(pnum);

	if (!PlrDirOK(pnum, EndDir)) {
		return;
	}

	//The player's tile position after finishing this movement action
	int px = xadd + plr[pnum]._px;
	int py = yadd + plr[pnum]._py;
	plr[pnum]._pfutx = px;
	plr[pnum]._pfuty = py;

	//If this is the local player then update the camera offset position
	if (pnum == myplr) {
		ScrollInfo._sdx = plr[pnum]._px - ViewX;
		ScrollInfo._sdy = plr[pnum]._py - ViewY;
	}

	switch (variant) {
	case PM_WALK:
		dPlayer[px][py] = -(pnum + 1);
		plr[pnum]._pmode = PM_WALK;
		plr[pnum]._pxvel = xvel;
		plr[pnum]._pyvel = yvel;
		plr[pnum]._pxoff = 0;
		plr[pnum]._pyoff = 0;
		plr[pnum]._pVar1 = xadd;
		plr[pnum]._pVar2 = yadd;
		plr[pnum]._pVar3 = EndDir;

		plr[pnum]._pVar6 = 0;
		plr[pnum]._pVar7 = 0;
		break;
	case PM_WALK2:
		dPlayer[plr[pnum]._px][plr[pnum]._py] = -(pnum + 1);
		plr[pnum]._pVar1 = plr[pnum]._px;
		plr[pnum]._pVar2 = plr[pnum]._py;
		plr[pnum]._px = px; // Move player to the next tile to maintain correct render order
		plr[pnum]._py = py;
		dPlayer[plr[pnum]._px][plr[pnum]._py] = pnum + 1;
		plr[pnum]._pxoff = xoff; // Offset player sprite to align with their previous tile position
		plr[pnum]._pyoff = yoff;

		ChangeLightXY(plr[pnum]._plid, plr[pnum]._px, plr[pnum]._py);
		PM_ChangeLightOff(pnum);

		plr[pnum]._pmode = PM_WALK2;
		plr[pnum]._pxvel = xvel;
		plr[pnum]._pyvel = yvel;
		plr[pnum]._pVar6 = xoff * 256;
		plr[pnum]._pVar7 = yoff * 256;
		plr[pnum]._pVar3 = EndDir;
		break;
	case PM_WALK3:
		int x = mapx + plr[pnum]._px;
		int y = mapy + plr[pnum]._py;

		dPlayer[plr[pnum]._px][plr[pnum]._py] = -(pnum + 1);
		dPlayer[px][py] = -(pnum + 1);
		plr[pnum]._pVar4 = x;
		plr[pnum]._pVar5 = y;
		dFlags[x][y] |= BFLAG_PLAYERLR;
		plr[pnum]._pxoff = xoff; // Offset player sprite to align with their previous tile position
		plr[pnum]._pyoff = yoff;

		if (leveltype != DTYPE_TOWN) {
			ChangeLightXY(plr[pnum]._plid, x, y);
			PM_ChangeLightOff(pnum);
		}

		plr[pnum]._pmode = PM_WALK3;
		plr[pnum]._pxvel = xvel;
		plr[pnum]._pyvel = yvel;
		plr[pnum]._pVar1 = px;
		plr[pnum]._pVar2 = py;
		plr[pnum]._pVar6 = xoff * 256;
		plr[pnum]._pVar7 = yoff * 256;
		plr[pnum]._pVar3 = EndDir;
		break;
	}

	//Load walk animation in case it's not loaded yet
	if (!(plr[pnum]._pGFXLoad & PFILE_WALK)) {
		LoadPlrGFX(pnum, PFILE_WALK);
	}

	//Start walk animation
	NewPlrAnim(pnum, plr[pnum]._pWAnim[EndDir], plr[pnum]._pWFrames, 0, plr[pnum]._pWWidth);

	plr[pnum]._pdir = EndDir;
	plr[pnum]._pVar8 = 0;

	if (pnum != myplr) {
		return;
	}

	if (zoomflag) {
		if (abs(ScrollInfo._sdx) >= 3 || abs(ScrollInfo._sdy) >= 3) {
			ScrollInfo._sdir = SDIR_NONE;
		} else {
			ScrollInfo._sdir = sdir;
		}
	} else if (abs(ScrollInfo._sdx) >= 2 || abs(ScrollInfo._sdy) >= 2) {
		ScrollInfo._sdir = SDIR_NONE;
	} else {
		ScrollInfo._sdir = sdir;
	}
}