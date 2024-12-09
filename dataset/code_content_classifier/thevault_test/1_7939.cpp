void ZoomHistory::preserve_aspect_ratio()
{
	double window_ratio;
	double world_ratio;

	window_ratio = (win.bottom - win.top) / (win.right - win.left);
	world_ratio = (world.bottom - world.top) / (world.right - world.left);

	if( world_ratio > window_ratio ) {
		win.right = win.left +
				(win.bottom - win.top) / world_ratio;
	} else {
		win.bottom = win.top +
				(win.right - win.left) * world_ratio;
	}

}