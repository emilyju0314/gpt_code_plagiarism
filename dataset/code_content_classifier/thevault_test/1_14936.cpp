void EndBoxingMatch( SOLDIERTYPE * pLoser )
{
	if (pLoser->bTeam == OUR_TEAM )
	{
		SetBoxingState( LOST_ROUND );
	}
	else
	{
		SetBoxingState( WON_ROUND );
		gfLastBoxingMatchWonByPlayer = TRUE;
		gubBoxingMatchesWon++;
	}
	TriggerNPCRecord( DARREN, 22 );
}