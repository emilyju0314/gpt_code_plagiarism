void SaveStrategicEventsToSavedGame(HWFILE const f)
{
	// Determine the number of events
	UINT32 n_game_events = 0;
	for (STRATEGICEVENT* i = gpEventList; i; i = i->next)
	{
		++n_game_events;
	}
	f->write(&n_game_events, sizeof(UINT32));

	for (STRATEGICEVENT* i = gpEventList; i; i = i->next)
	{
		BYTE  data[28];
		DataWriter d{data};
		INJ_SKIP(d, 4)
		INJ_U32( d, i->uiTimeStamp)
		INJ_U32( d, i->uiParam)
		INJ_U32( d, i->uiTimeOffset)
		INJ_U8(  d, i->ubEventType)
		INJ_U8(  d, i->ubCallbackID)
		INJ_U8(  d, i->ubFlags)
		INJ_SKIP(d, 9)
		Assert(d.getConsumed() == lengthof(data));

		f->write(data, sizeof(data));
	}
}