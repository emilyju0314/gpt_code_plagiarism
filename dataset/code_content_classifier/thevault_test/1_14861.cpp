static void MSYS_UpdateMouseRegion(void)
{
	MOUSE_REGION* cur;
	for (cur = MSYS_RegList; cur != NULL; cur = cur->next)
	{
		if (cur->uiFlags & (MSYS_REGION_ENABLED | MSYS_ALLOW_DISABLED_FASTHELP) &&
			cur->RegionTopLeftX <= MSYS_CurrentMX && MSYS_CurrentMX <= cur->RegionBottomRightX &&
			cur->RegionTopLeftY <= MSYS_CurrentMY && MSYS_CurrentMY <= cur->RegionBottomRightY)
		{
			/* We got the right region. We don't need to check for priorities because
			 * the whole list is sorted the right way! */
			break;
		}
	}
	MSYS_CurrRegion = cur;

	MOUSE_REGION* prev = MSYS_PrevRegion;
	if (prev)
	{
		prev->uiFlags &= ~MSYS_MOUSE_IN_AREA;

		if (prev != cur)
		{
			/* Remove the help text for the previous region if one is currently being
			 * displayed. */
			if (!prev->FastHelpText.empty())
			{
#ifdef _JA2_RENDER_DIRTY
				if (prev->uiFlags & MSYS_GOT_BACKGROUND)
				{
					FreeBackgroundRectPending(prev->FastHelpRect);
				}
#endif
				prev->uiFlags &= ~MSYS_GOT_BACKGROUND;
				prev->uiFlags &= ~MSYS_FASTHELP_RESET;
			}

			/* Force a callbacks to happen on previous region to indicate that the
			 * mouse has left the old region */
			if (prev->MovementCallback != NULL && prev->uiFlags & MSYS_REGION_ENABLED)
			{
				prev->MovementCallback(prev, MSYS_CALLBACK_REASON_LOST_MOUSE);
			}
		}
	}

	// If a region was found in the list, update its data
	if (cur != NULL)
	{
		if (cur != prev)
		{
			cur->FastHelpTimer = gsFastHelpDelay;

			//Kris -- October 27, 1997
			//Implemented gain mouse region
			if (cur->MovementCallback != NULL)
			{
				if (!cur->FastHelpText.empty() && !(cur->uiFlags & MSYS_FASTHELP_RESET))
				{
#ifdef _JA2_RENDER_DIRTY
					if (cur->uiFlags & MSYS_GOT_BACKGROUND)
					{
						FreeBackgroundRectPending(cur->FastHelpRect);
					}
#endif
					cur->uiFlags &= ~MSYS_GOT_BACKGROUND;
					cur->uiFlags |= MSYS_FASTHELP_RESET;
				}
				if (cur->uiFlags & MSYS_REGION_ENABLED)
				{
					cur->MovementCallback(cur, MSYS_CALLBACK_REASON_GAIN_MOUSE);
				}
			}

			// if the cursor is set and is not set to no cursor
			if (cur->uiFlags & MSYS_REGION_ENABLED && cur->Cursor != MSYS_NO_CURSOR)
			{
				MSYS_SetCurrentCursor(cur->Cursor);
			}
			else
			{
				/* Addition Oct 10/1997 Carter, patch for mouse cursor
				 * start at region and find another region encompassing */
				for (const MOUSE_REGION* i = cur->next; i != NULL; i = i->next)
				{
					if (i->uiFlags & MSYS_REGION_ENABLED &&
							i->RegionTopLeftX <= MSYS_CurrentMX && MSYS_CurrentMX <= i->RegionBottomRightX &&
							i->RegionTopLeftY <= MSYS_CurrentMY && MSYS_CurrentMY <= i->RegionBottomRightY &&
							i->Cursor != MSYS_NO_CURSOR)
					{
						MSYS_SetCurrentCursor(i->Cursor);
						break;
					}
				}
			}
		}

		// OK, if we do not have a button down, any button is game!
		if (!g_clicked_region || g_clicked_region == cur)
		{
			cur->uiFlags |= MSYS_MOUSE_IN_AREA;

			cur->MouseXPos    = MSYS_CurrentMX;
			cur->MouseYPos    = MSYS_CurrentMY;
			cur->RelativeXPos = MSYS_CurrentMX - cur->RegionTopLeftX;
			cur->RelativeYPos = MSYS_CurrentMY - cur->RegionTopLeftY;

			cur->ButtonState = MSYS_CurrentButtons;

			if (cur->uiFlags & MSYS_REGION_ENABLED &&
					cur->MovementCallback != NULL &&
					MSYS_Action & MSYS_DO_MOVE)
			{
				cur->MovementCallback(cur, MSYS_CALLBACK_REASON_MOVE);
			}

			MSYS_Action &= ~MSYS_DO_MOVE;

			if (cur->ButtonCallback != NULL && MSYS_Action & MSYS_DO_BUTTONS)
			{
				if (cur->uiFlags & MSYS_REGION_ENABLED)
				{
					UINT32 ButtonReason = MSYS_CALLBACK_REASON_NONE;
					if (MSYS_Action & MSYS_DO_LBUTTON_DWN)
					{
						ButtonReason |= MSYS_CALLBACK_REASON_LBUTTON_DWN;
						g_clicked_region = cur;
					}

					if (MSYS_Action & MSYS_DO_LBUTTON_UP)
					{
						ButtonReason |= MSYS_CALLBACK_REASON_LBUTTON_UP;
						g_clicked_region = 0;
					}

					if (MSYS_Action & MSYS_DO_RBUTTON_DWN)
					{
						ButtonReason |= MSYS_CALLBACK_REASON_RBUTTON_DWN;
						g_clicked_region = cur;
					}

					if (MSYS_Action & MSYS_DO_RBUTTON_UP)
					{
						ButtonReason |= MSYS_CALLBACK_REASON_RBUTTON_UP;
						g_clicked_region = 0;
					}

					if (MSYS_Action & MSYS_DO_MBUTTON_DWN)
					{
						ButtonReason |= MSYS_CALLBACK_REASON_MBUTTON_DWN;
						g_clicked_region = cur;
					}

					if (MSYS_Action & MSYS_DO_MBUTTON_UP)
					{
						ButtonReason |= MSYS_CALLBACK_REASON_MBUTTON_UP;
						g_clicked_region = 0;
					}

					// ATE: Added repeat resons....
					if (MSYS_Action & MSYS_DO_LBUTTON_REPEAT)
					{
						ButtonReason |= MSYS_CALLBACK_REASON_LBUTTON_REPEAT;
					}

					if (MSYS_Action & MSYS_DO_RBUTTON_REPEAT)
					{
						ButtonReason |= MSYS_CALLBACK_REASON_RBUTTON_REPEAT;
					}

					if (MSYS_Action & MSYS_DO_MBUTTON_REPEAT)
					{
						ButtonReason |= MSYS_CALLBACK_REASON_MBUTTON_REPEAT;
					}

					if (MSYS_Action & MSYS_DO_WHEEL_UP)   ButtonReason |= MSYS_CALLBACK_REASON_WHEEL_UP;
					if (MSYS_Action & MSYS_DO_WHEEL_DOWN) ButtonReason |= MSYS_CALLBACK_REASON_WHEEL_DOWN;

					if (ButtonReason != MSYS_CALLBACK_REASON_NONE)
					{
						if (cur->uiFlags & MSYS_FASTHELP)
						{
							// Button was clicked so remove any FastHelp text
							cur->uiFlags &= ~MSYS_FASTHELP;
#ifdef _JA2_RENDER_DIRTY
							if (cur->uiFlags & MSYS_GOT_BACKGROUND)
							{
								FreeBackgroundRectPending(cur->FastHelpRect);
							}
#endif
							cur->uiFlags &= ~MSYS_GOT_BACKGROUND;
							cur->uiFlags &= ~MSYS_FASTHELP_RESET;

							cur->FastHelpTimer = gsFastHelpDelay;
						}

						//Kris: Nov 31, 1999 -- Added support for double click events.
						//This is where double clicks are checked and passed down.
						if (ButtonReason == MSYS_CALLBACK_REASON_LBUTTON_DWN)
						{
							UINT32 uiCurrTime = GetClock();
							if (gpRegionLastLButtonDown == cur &&
									gpRegionLastLButtonUp   == cur &&
									uiCurrTime <= guiRegionLastLButtonDownTime + MSYS_DOUBLECLICK_DELAY)
							{
								/* Sequential left click on same button within the maximum time
								 * allowed for a double click.  Double click check succeeded,
								 * set flag and reset double click globals. */
								ButtonReason |= MSYS_CALLBACK_REASON_LBUTTON_DOUBLECLICK;
								gpRegionLastLButtonDown = NULL;
								gpRegionLastLButtonUp   = NULL;
								guiRegionLastLButtonDownTime = 0;
							}
							else
							{
								/* First click, record time and region pointer (to check if 2nd
								 * click detected later) */
								gpRegionLastLButtonDown = cur;
								guiRegionLastLButtonDownTime = GetClock();
							}
						}
						else if (ButtonReason == MSYS_CALLBACK_REASON_LBUTTON_UP)
						{
							UINT32 uiCurrTime = GetClock();
							if (gpRegionLastLButtonDown == cur &&
									uiCurrTime <= guiRegionLastLButtonDownTime + MSYS_DOUBLECLICK_DELAY)
							{
								/* Double click is Left down, then left up, then left down.  We
								 * have just detected the left up here (step 2). */
								gpRegionLastLButtonUp = cur;
							}
							else
							{
								/* User released mouse outside of current button, so kill any
								 * chance of a double click happening. */
								gpRegionLastLButtonDown = NULL;
								gpRegionLastLButtonUp   = NULL;
								guiRegionLastLButtonDownTime = 0;
							}
						}

						cur->ButtonCallback(cur, ButtonReason);
					}
				}
			}

			MSYS_Action &= ~MSYS_DO_BUTTONS;
		}
		else if (cur->uiFlags & MSYS_REGION_ENABLED)
		{
			// OK here, if we have release a button, UNSET LOCK wherever you are....
			// Just don't give this button the message....
			if (MSYS_Action & MSYS_DO_RBUTTON_UP) g_clicked_region = 0;
			if (MSYS_Action & MSYS_DO_LBUTTON_UP) g_clicked_region = 0;
			if (MSYS_Action & MSYS_DO_MBUTTON_UP) g_clicked_region = 0;

			// OK, you still want move messages however....
			cur->uiFlags |= MSYS_MOUSE_IN_AREA;
			cur->MouseXPos = MSYS_CurrentMX;
			cur->MouseYPos = MSYS_CurrentMY;
			cur->RelativeXPos = MSYS_CurrentMX - cur->RegionTopLeftX;
			cur->RelativeYPos = MSYS_CurrentMY - cur->RegionTopLeftY;

			if (cur->MovementCallback != NULL && MSYS_Action & MSYS_DO_MOVE)
			{
				cur->MovementCallback(cur, MSYS_CALLBACK_REASON_MOVE);
			}

			MSYS_Action &= ~MSYS_DO_MOVE;
		}
	}
	/* the current region can get deleted during this function, so fetch the
	 * latest value here */
	MSYS_PrevRegion = MSYS_CurrRegion;
}