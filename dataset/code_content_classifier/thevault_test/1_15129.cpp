void MainGameScreenShutdown(void)
{
	ShutdownZBuffer(gpZBuffer);
	RemoveVideoOverlay(g_fps_overlay);
	RemoveVideoOverlay(g_counter_period_overlay);
	ShutdownBackgroundRects();
}