void CHexEditDoc::KillPreviewThread()
{
	ASSERT(pthread6_ != NULL);
	if (pthread6_ == NULL) return;

	HANDLE hh = pthread6_->m_hThread;    // Save handle since it will be lost when thread is killed and object is destroyed
	TRACE1("+++ Killing preview thread for %p\n", this);

	bool waiting, dying;
	docdata_.Lock();
	preview_command_ = DIE;
	docdata_.Unlock();
	SetThreadPriority(pthread6_->m_hThread, THREAD_PRIORITY_NORMAL); // Make it a quick and painless death
	for (int ii = 0; ii < 100; ++ii)
	{
		// Wait just a little bit in case the thread was just about to go into wait state
		docdata_.Lock();
		waiting = preview_state_ == WAITING;
		dying   = preview_state_ == DYING;
		docdata_.Unlock();
		if (waiting || dying)
			break;
		Sleep(1);
	}
	ASSERT(waiting || dying);

	timer tt(true);
	if (waiting)
		start_preview_event_.SetEvent();

	pthread6_ = NULL;
	DWORD wait_status = ::WaitForSingleObject(hh, INFINITE);
	ASSERT(wait_status == WAIT_OBJECT_0 || wait_status == WAIT_FAILED);
	tt.stop();
	TRACE1("+++ Thread took %g secs to kill\n", double(tt.elapsed()));

	// Free resources that are only needed during scan
	if (pfile6_ != NULL)
	{
		pfile6_->Close();
		delete pfile6_;
		pfile6_ = NULL;
	}
	for (int ii = 0; ii < doc_loc::max_data_files; ++ii)
	{
		if (data_file6_[ii] != NULL)
		{
			data_file6_[ii]->Close();
			delete data_file6_[ii];
			data_file6_[ii] = NULL;
		}
	}
}