void CHexEditView::InvalidateRange(CPointAp start, CPointAp end, bool f /*=false*/)
{
	BOOL saved_edit_char = display_.edit_char;          // Saved value of display_.edit_char
	FILE_ADDRESS start_addr, end_addr;          // Range of addresses to invalidate

	// Work out what we are invalidating (hex or char area)
	if (display_.vert_display)
		; // do nothing since edit_char does not affect pos2addr for vert_display
	else if (!display_.hex_area ||
		(display_.char_area && pos_hex(start.x) == rowsize_ && pos_hex(end.x) == rowsize_))
		display_.edit_char = TRUE;                      // Change display_.edit_char so pos2addr() works
	else
		display_.edit_char = FALSE;

	// Work out range to invalidate (WARNING: this relies on display_.edit_char)
	start_addr = pos2addr(start);
	end_addr = pos2addr(end);

	display_.edit_char = saved_edit_char;               // Restore display_.edit_char

	if (theApp.show_other_)
		++end_addr;
	else if (start_addr == end_addr)
		return;

	if (f)
	{
		// When dragging with the mouse the selected area in the hex view is only
		// invalidated in the part of the selection that actually changes - this
		// avoids the flickering which still occurs with kb (Shift+arrow) selection.
		// However, as the selectiop for the aerial view is drawn with a boundary
		// (marching ants) this leaves bits of the old boundary behind when increasing
		// the selection size by dragging the mouse.  The f flag signals that the
		// whole of the selection (start_addr to end_addr) should be invalidated
		// in the aerial view.
		if (pav_ != NULL)
			pav_->InvalidateRange(start_addr, end_addr);
	}
	else
	{
		// Note: We need to invalidate an extra char backwards because in the hex
		// display area the white space to the right of the last byte selected is
		// not shown in reverse video.  When the selection is extended towards the
		// end of file (causing InvalidateRange to be called) not only the newly
		// selected bytes need to be invalidated but also the previous one so that
		// the white area after the character is then drawn in reverse video.
		invalidate_hex_addr_range(start_addr-1, end_addr);

		// Also invalidate in aerial view so it can "undraw" the selection if it is smaller
		if (pav_ != NULL)
			pav_->InvalidateRange(start_addr, end_addr);
	}
}