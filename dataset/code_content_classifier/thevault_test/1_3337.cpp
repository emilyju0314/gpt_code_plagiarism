void CAerialView::ShowPos(FILE_ADDRESS addr)
{
	int width = GetDocument()->GetBpe() * cols_;                // row width in bytes
	int zone = 0;                                               // no of rows from top/bottom before scrolling
	if (phev_ != NULL) zone = phev_->GetVertBufferZone();
	if (zone > rows_/2) zone = rows_/2;                         // Can't be more than half window height

	if (addr < scrollpos_ + width*zone)
	{
		SetScroll(int(addr/width) - zone);
	}
	else if (addr >= scrollpos_ + width*(rows_ - zone))
	{
		SetScroll(int(addr/width) - rows_ + zone + 1);
	}
}