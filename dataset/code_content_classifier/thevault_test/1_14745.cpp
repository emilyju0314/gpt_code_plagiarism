void SetRelativeStartAndEndPercentage(UINT8 id, UINT32 uiRelStartPerc, UINT32 uiRelEndPerc, const ST::string& str)
{
	Assert(id < MAX_PROGRESSBARS);
	PROGRESSBAR* const bar = pBar[id];
	if (!bar) return;

	bar->rStart = uiRelStartPerc * 0.01;
	bar->rEnd   = uiRelEndPerc   * 0.01;

	//Render the entire panel now, as it doesn't need update during the normal rendering
	if (bar->flags & PROGRESS_PANEL)
	{ // Draw panel
		UINT16 const l = bar->usPanelLeft;
		UINT16 const t = bar->usPanelTop;
		UINT16 const r = bar->usPanelRight;
		UINT16 const b = bar->usPanelBottom;
		ColorFillVideoSurfaceArea(FRAME_BUFFER, l,     t,     r,     b,     bar->usLtColor);
		ColorFillVideoSurfaceArea(FRAME_BUFFER, l + 1, t + 1, r,     b,     bar->usDkColor);
		ColorFillVideoSurfaceArea(FRAME_BUFFER, l + 1, t + 1, r - 1, b - 1, bar->usColor);
		InvalidateRegion(l, t, r, b);
		if (!bar->title.empty())
		{ // Draw title
			SGPFont  const font = bar->usTitleFont;
			INT32 const x    = (r + l - StringPixLength(bar->title, font)) / 2; // Center
			SetFontAttributes(font, bar->ubTitleFontForeColor, bar->ubTitleFontShadowColor);
			MPrint(x, t + 3, bar->title);
		}
	}

	if (bar->flags & PROGRESS_DISPLAY_TEXT && !str.empty())
	{ // Draw message
		INT32 const x    = bar->pos.x;
		INT32 const y    = bar->pos.y + bar->pos.h;
		SGPFont  const font = bar->usMsgFont;
		if (bar->flags & PROGRESS_USE_SAVEBUFFER)
		{
			UINT16 const h = GetFontHeight(font);
			RestoreExternBackgroundRect(x, y, bar->pos.w, h + 3);
		}

		SetFontAttributes(font, bar->ubMsgFontForeColor, bar->ubMsgFontShadowColor);
		MPrint(x, y + 3, str);
	}
}