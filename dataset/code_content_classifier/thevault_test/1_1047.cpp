static  void    DestroySyncSeaPositionHeartBeat( void )
{
    timeKillEvent(idSyncSeaPositionHeartBeat);
	SaveMsgToLog("SYSTEM","DESTROY_SYNCSEAPOSITIONHEARTBEAT_OK");
}