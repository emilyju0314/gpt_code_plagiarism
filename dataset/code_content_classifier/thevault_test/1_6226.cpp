int SoundIdentificationThread::SavePairList(YARPString name) {

	YARPListIterator<SoundImagePair> thePairListIterator(_pairList);
	char tempbuff[100];

	ACE_OS::fprintf(stdout,"SoundIdentificationThread: Saving pair list %s", name.c_str());

	thePairListIterator.go_head();

	for ( unsigned int i = 0; i < _pairList.size(); i++) {

		YARPString sequenceName(name);
		SoundImagePair &temppair = *thePairListIterator;
		sequenceName.append(itoa(i, tempbuff, 10));

		temppair.Save( sequenceName );
		thePairListIterator++;
	}

	return YARP_OK;
}