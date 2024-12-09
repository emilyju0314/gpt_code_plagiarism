static  SLONG   InitializeSyncSeaPositionHeartBeat( void )
{
 idSyncSeaPositionHeartBeat = timeSetEvent(syncseapositionheartbeat_data.dwMsPerBeat,
	                            NULL,
								SyncSeaPositionHeartBeatProc,
								NULL,
								TIME_PERIODIC);
 return TTN_OK;
}