static  SLONG   InitializeSyncPositionHeartBeat( void )
{
 idSyncPositionHeartBeat = timeSetEvent(syncpositionheartbeat_data.dwMsPerBeat,
	                            NULL,
								SyncPositionHeartBeatProc,
								NULL,
								TIME_PERIODIC);
 return TTN_OK;
}