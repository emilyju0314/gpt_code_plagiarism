int CHexEditView::pos2row(CPointAp pos)
{
	ASSERT(display_.vert_display);
	ASSERT((pos.y%line_height_)/text_height_ < 3);
	return int((pos.y%line_height_)/text_height_);
}