int _SocketThreadListMulti::closeByName (const YARPString& name)
{
	ACE_ASSERT (_initialized != 0);

	int result = YARP_FAIL;

	_listProtect.Wait();
	YARPList<_SocketThreadMultiBase *>::iterator it_avail(_list);

	for (; !it_avail.done(); it_avail++)
	{
		if (!((*it_avail)->isAvailable ()))
		{
			if (ACE_OS::strcmp((*it_avail)->getRemoteName().c_str(), name.c_str()) == 0)
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