const char *CAI_BaseNPC::GetActivityName(int actID) 
{
	if ( actID == -1 )
		return "ACT_INVALID";

	// m_pActivitySR only contains public activities, ActivityList_NameForIndex() has them all
	const char *name = ActivityList_NameForIndex(actID);	

	if( !name )
	{
		AssertOnce( !"CAI_BaseNPC::GetActivityName() returning NULL!" );
	}

	return name;
}