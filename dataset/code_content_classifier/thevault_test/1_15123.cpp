void RenderStaticWorldRect(INT16 sLeft, INT16 sTop, INT16 sRight, INT16 sBottom, BOOLEAN fDynamicsToo)
{
	RenderLayerID sLevelIDs[10];

	// Calculate render starting parameters
	CalcRenderParameters(sLeft, sTop, sRight, sBottom);

	// Reset layer optimizations
	ResetLayerOptimizing();

	// STATICS
	sLevelIDs[0] = RENDER_STATIC_LAND;
	RenderTiles(TILES_NONE, gsLStartPointX_M, gsLStartPointY_M, gsLStartPointX_S, gsLStartPointY_S, gsLEndXS, gsLEndYS, 1, sLevelIDs);

	sLevelIDs[0] = RENDER_STATIC_OBJECTS;
	RenderTiles(TILES_NONE, gsLStartPointX_M, gsLStartPointY_M, gsLStartPointX_S, gsLStartPointY_S, gsLEndXS, gsLEndYS, 1, sLevelIDs);

	if (gRenderFlags & RENDER_FLAG_SHADOWS)
	{
		sLevelIDs[0] = RENDER_STATIC_SHADOWS;
		RenderTiles(TILES_NONE, gsLStartPointX_M, gsLStartPointY_M, gsLStartPointX_S, gsLStartPointY_S, gsLEndXS, gsLEndYS, 1, sLevelIDs);
	}

	sLevelIDs[0] = RENDER_STATIC_STRUCTS;
	sLevelIDs[1] = RENDER_STATIC_ROOF;
	sLevelIDs[2] = RENDER_STATIC_ONROOF;
	sLevelIDs[3] = RENDER_STATIC_TOPMOST;
	RenderTiles(TILES_NONE, gsLStartPointX_M, gsLStartPointY_M, gsLStartPointX_S, gsLStartPointY_S, gsLEndXS, gsLEndYS, 4, sLevelIDs);

	//ATE: Do obsucred layer!
	sLevelIDs[0] = RENDER_STATIC_STRUCTS;
	sLevelIDs[1] = RENDER_STATIC_ONROOF;
	RenderTiles(TILES_OBSCURED, gsLStartPointX_M, gsLStartPointY_M, gsLStartPointX_S, gsLStartPointY_S, gsLEndXS, gsLEndYS, 2, sLevelIDs);

	if (fDynamicsToo)
	{
		// DYNAMICS
		sLevelIDs[0] = RENDER_DYNAMIC_LAND;
		sLevelIDs[1] = RENDER_DYNAMIC_OBJECTS;
		sLevelIDs[2] = RENDER_DYNAMIC_SHADOWS;
		sLevelIDs[3] = RENDER_DYNAMIC_STRUCT_MERCS;
		sLevelIDs[4] = RENDER_DYNAMIC_MERCS;
		sLevelIDs[5] = RENDER_DYNAMIC_STRUCTS;
		sLevelIDs[6] = RENDER_DYNAMIC_ROOF;
		sLevelIDs[7] = RENDER_DYNAMIC_HIGHMERCS;
		sLevelIDs[8] = RENDER_DYNAMIC_ONROOF;
		RenderTiles(TILES_NONE, gsLStartPointX_M, gsLStartPointY_M, gsLStartPointX_S, gsLStartPointY_S, gsLEndXS, gsLEndYS, 9, sLevelIDs);

		SumAdditiveLayerOptimization();
	}

	ResetRenderParameters();

	if (!gfDoVideoScroll) AddBaseDirtyRect(sLeft, sTop, sRight, sBottom);
}