static  void    DestroySyncPositionHeartBeat( void )
{
    timeKillEvent(idSyncPositionHeartBeat);
	SaveMsgToLog("SYSTEM","DESTROY_SYNCPOSITIONHEARTBEAT_OK");
}