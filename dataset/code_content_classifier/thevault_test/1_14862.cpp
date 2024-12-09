void MSYS_DefineRegion(MOUSE_REGION* const r, UINT16 const tlx, UINT16 const tly, UINT16 const brx, UINT16 const bry, INT8 priority, UINT16 const crsr, MOUSE_CALLBACK const movecallback, MOUSE_CALLBACK const buttoncallback)
{
#ifdef MOUSESYSTEM_DEBUGGING
	AssertMsg(!(r->uiFlags & MSYS_REGION_EXISTS), "Attempting to define a region that already exists.");
#endif

	if (priority <= MSYS_PRIORITY_LOWEST) priority = MSYS_PRIORITY_LOWEST;

	r->PriorityLevel      = priority;
	r->uiFlags            = MSYS_REGION_ENABLED | MSYS_REGION_EXISTS;
	r->RegionTopLeftX     = tlx;
	r->RegionTopLeftY     = tly;
	r->RegionBottomRightX = brx;
	r->RegionBottomRightY = bry;
	r->MouseXPos          = 0;
	r->MouseYPos          = 0;
	r->RelativeXPos       = 0;
	r->RelativeYPos       = 0;
	r->ButtonState        = 0;
	r->Cursor             = crsr;
	r->MovementCallback   = movecallback;
	r->ButtonCallback     = buttoncallback;
	r->FastHelpTimer      = 0;
	r->FastHelpText       = ST::null;
	r->next               = 0;
	r->prev               = 0;

	MSYS_AddRegionToList(r);
	gfRefreshUpdate = TRUE;
}