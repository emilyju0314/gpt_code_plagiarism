static WaitList* openWaitList(Uptr address)
{
	Platform::Mutex::Lock mapLock(addressToWaitListMapMutex);
	auto waitListPtr = addressToWaitListMap.get(address);
	if(waitListPtr)
	{
		++(*waitListPtr)->numReferences;
		return *waitListPtr;
	}
	else
	{
		WaitList* waitList = new WaitList();
		addressToWaitListMap.set(address, waitList);
		return waitList;
	}
}