CPointAp CHexEditView::addr2pos(FILE_ADDRESS address, int row /*=0*/) const
{
	ASSERT(row == 0 || (display_.vert_display && row < 3));
	address += offset_;
	if (display_.vert_display)
		return CPointAp(char_pos(int(address%rowsize_)), (address/rowsize_) * line_height_ + row * text_height_);
	else if (display_.edit_char)
		return CPointAp(char_pos(int(address%rowsize_)), address/rowsize_ * line_height_);
	else if ((num_entered_ % 2) == 0)
		return CPointAp(hex_pos(int(address%rowsize_)), address/rowsize_ * line_height_);
	else
		return CPointAp(hex_pos(int(address%rowsize_)) + 2*text_width_,
					  address/rowsize_ * line_height_);
}