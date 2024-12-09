void CHexEditDoc::PreviewChange(CHexEditView *pview /*= NULL*/)
{
	if (preview_count_ == 0) return;
	ASSERT(pthread6_ != NULL);
	if (pthread6_ == NULL) return;

	// Wait for thread to stop if necessary
	bool waiting;
	docdata_.Lock();
	preview_command_ = STOP;
	docdata_.Unlock();
	SetThreadPriority(pthread6_->m_hThread, THREAD_PRIORITY_NORMAL);
	for (int ii = 0; ii < 100; ++ii)
	{
		// Wait just a little bit in case the thread was just about to go into wait state
		docdata_.Lock();
		waiting = preview_state_ == WAITING;
		docdata_.Unlock();
		if (waiting)
			break;
		TRACE("+++ PreviewChange - thread not waiting (yet)\n");
		Sleep(1);
	}
	SetThreadPriority(pthread6_->m_hThread, THREAD_PRIORITY_LOWEST);
	ASSERT(waiting);

	// Restart the scan
	docdata_.Lock();
	preview_command_ = NONE;  // make sure we don't stop the scan before it starts
	preview_fin_ = false;
	docdata_.Unlock();

	TRACE("+++ Pulsing preview event (restart)\n");
	start_preview_event_.SetEvent();
}