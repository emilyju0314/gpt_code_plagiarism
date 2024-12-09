void RenderWorld(void)
{
	gfRenderFullThisFrame = FALSE;

	// If we are testing renderer, set background to pink!
	if (gTacticalStatus.uiFlags & DEBUGCLIFFS)
	{
		ColorFillVideoSurfaceArea(FRAME_BUFFER, 0, gsVIEWPORT_WINDOW_START_Y, SCREEN_WIDTH, gsVIEWPORT_WINDOW_END_Y, Get16BPPColor(FROMRGB(0, 255, 0)));
		SetRenderFlags(RENDER_FLAG_FULL);
	}

	if (gTacticalStatus.uiFlags & SHOW_Z_BUFFER)
	{
		SetRenderFlags(RENDER_FLAG_FULL);
	}

	// For now here, update animated tiles
	if (COUNTERDONE(ANIMATETILES))
	{
		RESETCOUNTER(ANIMATETILES);
		for (UINT32 i = 0; i != gusNumAnimatedTiles; ++i)
		{
			TILE_ANIMATION_DATA& a = *gTileDatabase[gusAnimatedTiles[i]].pAnimData;
			if (++a.bCurrentFrame >= a.ubNumFrames) a.bCurrentFrame = 0;
		}
	}

	// HERE, UPDATE GLOW INDEX
	if (COUNTERDONE(GLOW_ENEMYS))
	{
		RESETCOUNTER(GLOW_ENEMYS);
		gsCurrentGlowFrame     = (gsCurrentGlowFrame     + 1) % lengthof(gsGlowFrames);
		gsCurrentItemGlowFrame = (gsCurrentItemGlowFrame + 1) % NUM_ITEM_CYCLE_COLORS;
	}

	if (gRenderFlags & RENDER_FLAG_FULL)
	{
		gfRenderFullThisFrame = TRUE;
		gfTopMessageDirty     = TRUE;

		// Dirty the interface...
		fInterfacePanelDirty = DIRTYLEVEL2;

		// Apply scrolling sets some world variables
		ApplyScrolling(gsRenderCenterX, gsRenderCenterY, TRUE, FALSE);
		ResetLayerOptimizing();

		if (gRenderFlags & RENDER_FLAG_NOZ)
		{
			RenderStaticWorldRect(gsVIEWPORT_START_X, gsVIEWPORT_START_Y, gsVIEWPORT_END_X, gsVIEWPORT_END_Y, FALSE);
		}
		else
		{
			RenderStaticWorld();
		}

		if (!(gRenderFlags & RENDER_FLAG_SAVEOFF)) UpdateSaveBuffer();
	}
	else if (gRenderFlags & RENDER_FLAG_MARKED)
	{
		ResetLayerOptimizing();
		RenderMarkedWorld();
		if (!(gRenderFlags & RENDER_FLAG_SAVEOFF)) UpdateSaveBuffer();
	}

	if (!g_scroll_inertia               ||
			gRenderFlags & RENDER_FLAG_NOZ  ||
			gRenderFlags & RENDER_FLAG_FULL ||
			gRenderFlags & RENDER_FLAG_MARKED)
	{
		RenderDynamicWorld();
	}

	if (g_scroll_inertia) EmptyBackgroundRects();

	if (gRenderFlags & RENDER_FLAG_ROOMIDS)
	{
		RenderRoomInfo(gsStartPointX_M, gsStartPointY_M, gsStartPointX_S, gsStartPointY_S, gsEndXS, gsEndYS);
	}

#ifdef _DEBUG
	if (gRenderFlags & RENDER_FLAG_FOVDEBUG)
	{
		RenderFOVDebugInfo(gsStartPointX_M, gsStartPointY_M, gsStartPointX_S, gsStartPointY_S, gsEndXS, gsEndYS);
	}
	else if (gfDisplayCoverValues)
	{
		RenderCoverDebugInfo(gsStartPointX_M, gsStartPointY_M, gsStartPointX_S, gsStartPointY_S, gsEndXS, gsEndYS);
	}
	else if (gfDisplayGridNoVisibleValues)
	{
		RenderGridNoVisibleDebugInfo(gsStartPointX_M, gsStartPointY_M, gsStartPointX_S, gsStartPointY_S, gsEndXS, gsEndYS);
	}
#endif


	if (gRenderFlags & RENDER_FLAG_MARKED) ClearMarkedTiles();

	if (gRenderFlags & RENDER_FLAG_CHECKZ && !(gTacticalStatus.uiFlags & NOHIDE_REDUNDENCY))
	{
		ExamineZBufferRect(gsVIEWPORT_START_X, gsVIEWPORT_WINDOW_START_Y, gsVIEWPORT_END_X, gsVIEWPORT_WINDOW_END_Y);
	}

	gRenderFlags &= ~(RENDER_FLAG_FULL | RENDER_FLAG_MARKED | RENDER_FLAG_ROOMIDS | RENDER_FLAG_CHECKZ);

	if (gTacticalStatus.uiFlags & SHOW_Z_BUFFER)
	{
		// COPY Z BUFFER TO FRAME BUFFER
		SGPVSurface::Lock l(FRAME_BUFFER);
		UINT16* const pDestBuf = l.Buffer<UINT16>();

		for (UINT32 i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i)
		{
			pDestBuf[i] = gpZBuffer[i];
		}
	}
}