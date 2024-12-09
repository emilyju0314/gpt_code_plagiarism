bool CHexEditDoc::PreviewProcessStop()
{
	bool retval = false;

	CSingleLock sl(&docdata_, TRUE);
	switch(preview_command_)
	{
	case STOP:                      // stop scan and wait
		TRACE1("+++ BGPreview: stop for %p\n", this);
		retval = true;
		break;
	case DIE:                       // terminate this thread
		TRACE1("+++ BGPreview: killed thread for %p\n", this);
		preview_state_ = DYING;
		sl.Unlock();                // we need this here as AfxEndThread() never returns so d'tor is not called
		AfxEndThread(1);            // kills thread (no return)
		break;                      // Avoid warning
	case NONE:                      // nothing needed here - just continue scanning
		break;
	default:                        // should not happen
		ASSERT(0);
	}

	// Prevent reprocessing of the same command
	preview_command_ = NONE;
	return retval;
}