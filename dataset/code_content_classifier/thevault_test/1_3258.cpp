bool CHexEditDoc::CompProcessStop()
{
	bool retval = false;

	CSingleLock sl(&docdata_, TRUE);
	switch(comp_command_)
	{
	case STOP:                      // stop scan and wait
		TRACE1("+++ BGCompare: stop for %p\n", this);
		retval = true;
		break;
	case DIE:                       // terminate this thread
		TRACE1("+++ BGCompare: killed thread for %p\n", this);
		comp_state_ = DYING;
		sl.Unlock();                // we need this here as AfxEndThread() never returns so d'tor is not called
		_aligned_free(comp_bufa_); comp_bufa_ = NULL;
		_aligned_free(comp_bufb_); comp_bufb_ = NULL;
		AfxEndThread(1);            // kills thread (no return)
		break;                      // Avoid warning
	case NONE:                      // nothing needed here - just continue scanning
		break;
	default:                        // should not happen
		ASSERT(0);
	}

	// Prevent reprocessing of the same command
	comp_command_ = NONE;
	return retval;
}