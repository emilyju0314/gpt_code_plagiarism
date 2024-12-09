static void AssertFailIfIdenticalButtonAttributesFound(const GUI_BUTTON* b)
{
	FOR_EACH_BUTTON(i)
	{
		GUI_BUTTON const* const c = *i;
		if (c->uiFlags            &   BUTTON_DELETION_PENDING) continue;
		if (c->uiFlags            &   BUTTON_NO_DUPLICATE)     continue;
		if (b->Area.PriorityLevel != c->Area.PriorityLevel)    continue;
		if (b->X()                != c->X())                   continue;
		if (b->Y()                != c->Y())                   continue;
		if (b->BottomRightX()     != c->BottomRightX())        continue;
		if (b->BottomRightY()     != c->BottomRightY())        continue;
		if (b->ClickCallback      != c->ClickCallback)         continue;
		if (b->MoveCallback       != c->MoveCallback)          continue;
		/* if we get this far, it is reasonably safe to assume that the newly
		 * created button already exists.  Placing a break point on the following
		 * assert will allow the coder to easily isolate the case!
		 */
		SLOGA("Attempting to create a button that has already been created (existing buttonID %d).", c->IDNum);
	}
}