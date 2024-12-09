void CHexEditDoc::KillCompThread()
{
	ASSERT(pthread4_ != NULL);
	if (pthread4_ == NULL) return;

	HANDLE hh = pthread4_->m_hThread;    // Save handle since it will be lost when thread is killed and object is destroyed
	TRACE1("+++ Killing compare thread for %p\n", this);

	// Signal thread to kill itself
	docdata_.Lock();
	comp_command_ = DIE;
	docdata_.Unlock();

	SetThreadPriority(pthread4_->m_hThread, THREAD_PRIORITY_NORMAL); // Make it a quick and painless death
	bool waiting, dying;
	for (int ii = 0; ii < 100; ++ii)
	{
		// Wait just a little bit in case the thread was just about to go into wait state
		docdata_.Lock();
		waiting = comp_state_ == WAITING;
		dying   = comp_state_ == DYING;
		docdata_.Unlock();
		if (waiting || dying)
			break;
		Sleep(1);
	}
	ASSERT(waiting || dying);

	// Send start message in case it is on hold
	if (waiting)
		start_comp_event_.SetEvent();

	TRACE1("+++ Setting compare thread to NULL for %p\n", this);
	pthread4_ = NULL;
	DWORD wait_status = ::WaitForSingleObject(hh, INFINITE);
	ASSERT(wait_status == WAIT_OBJECT_0 || wait_status == WAIT_FAILED);

	// Free resources that are only needed during bg compares
	CloseCompFile();
	if (bCompSelf_)
	{
		if (!tempFileA_.IsEmpty())
		{
			VERIFY(::remove(tempFileA_) == 0);
			tempFileA_.Empty();
		}
		if (!tempFileB_.IsEmpty())
		{
			VERIFY(::remove(tempFileB_) == 0);
			tempFileB_.Empty();
		}
	}
	ASSERT(tempFileA_.IsEmpty() && tempFileB_.IsEmpty());
}