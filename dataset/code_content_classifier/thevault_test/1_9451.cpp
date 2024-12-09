static void closeWaitList(Uptr address, WaitList* waitList)
{
	if(--waitList->numReferences == 0)
	{
		Platform::Mutex::Lock mapLock(addressToWaitListMapMutex);
		if(!waitList->numReferences)
		{
			WAVM_ASSERT(!waitList->wakeEvents.size());
			delete waitList;
			addressToWaitListMap.remove(address);
		}
	}
}