int _SocketThreadListMulti::close (ACE_HANDLE reply_id)
{
	ACE_ASSERT (_initialized != 0);

	int result = YARP_FAIL;

	_listProtect.Wait();
	YARPList<_SocketThreadMultiBase *>::iterator it_avail(_list);

	for (; !it_avail.done(); it_avail++)
	{
		if (!((*it_avail)->isAvailable ()))
		{
			if ((*it_avail)->getID () == reply_id)
			{
				(*it_avail)->End ();
				(*it_avail)->setAvailable (1);
				result = YARP_OK;
			}
		}
	}
	_listProtect.Post();

	return result;
}