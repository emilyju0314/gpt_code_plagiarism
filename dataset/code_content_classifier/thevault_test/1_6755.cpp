void EditView::string(float fx, float fy, float dim, const char* s, int anchor)
{
	if (editing_stage_ == NONE)
		View::string(fx, fy, dim, s, anchor);
}