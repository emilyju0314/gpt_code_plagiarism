int _SocketThreadListMulti::read(char *buf, int len, ACE_HANDLE *reply_pid, bool safe)
{
	ACE_HANDLE save_pid = ACE_INVALID_HANDLE;

	int finished = 0;
	int result = YARP_FAIL;

	while (!finished)
	{
		YARP_DBG(THIS_DBG) ((LM_DEBUG, "### Waiting for new data\n"));
		_new_data.Wait();

		// checks for proper initialization. maybe should move the wait for new data
		// at the very beginning in this case?
		ACE_ASSERT (_initialized != 0);

		YARP_DBG(THIS_DBG) ((LM_DEBUG, "### Got new data\n"));

		if (safe) _listProtect.Wait();

		YARPList<_SocketThreadMultiBase *>::iterator it_avail(_list);
		for (; !it_avail.done(); it_avail++)
		{
			// WARNING: isAvailable is read here without mut exclusion!
			if (!((*it_avail)->isAvailable()))
			{
				int work = 0, in_len = 0;
				(*it_avail)->waitOnMutex ();		// _mutex.Wait();

				if ((*it_avail)->isWaiting())
				{
					YARP_DBG(THIS_DBG) ((LM_DEBUG, "### Identified source of new data\n"));

					work = 1;
					(*it_avail)->setWaiting(0);							// = 0;
					(*it_avail)->setExternalBuffer (buf);				///extern_buffer = buf;
					in_len = (*it_avail)->getExternalBufferLength ();	///extern_length;
					(*it_avail)->setExternalBufferLength (len);			///extern_length = len;

					(*it_avail)->setNeedsReply (1);

					(*it_avail)->postToWakeup ();	// wakeup.Post();

					YARP_DBG(THIS_DBG) ((LM_DEBUG, "### Waking up source of new data\n"));
				}
				
				(*it_avail)->postToMutex ();	// mutex.Post();

				if (work)
				{
					YARP_DBG(THIS_DBG) ((LM_DEBUG, "### Waiting for buffer write\n"));
					_new_data_written.Wait();

					save_pid = (*it_avail)->getID();
					YARP_DBG(THIS_DBG) ((LM_DEBUG, "@@@ got data %d/%d\n", in_len, len));
					result = in_len;
					finished = 1;
					break;
				}
			}
		}

		if (safe) _listProtect.Post();
	}

	if (reply_pid != NULL)
	{
		*reply_pid = save_pid;
	}

	return result;
}