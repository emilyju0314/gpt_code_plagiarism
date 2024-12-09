static void MSYS_DeleteRegionFromList(MOUSE_REGION* const r)
{
	MOUSE_REGION* const prev = r->prev;
	MOUSE_REGION* const next = r->next;
	if (prev) prev->next = next;
	if (next) next->prev = prev;

	if (MSYS_RegList == r) MSYS_RegList = next;

	r->prev = 0;
	r->next = 0;
}