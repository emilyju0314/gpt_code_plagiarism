bool IsLowViolence_Secure()
{
	// CS:GO does not have any low violence regions. Ignore what Steam reports.
#if defined( CSTRIKE15 )
	return false;
#endif

#ifndef _GAMECONSOLE
	if ( IsPC() && Steam3Client().SteamApps() )
	{
		// let Steam determine current violence settings 		
		return Steam3Client().SteamApps()->BIsLowViolence();
	}
#endif

	if ( IsGameConsole() )
	{
#if defined( _LOWVIOLENCE )
		// a low violence build can not be-undone
		return true;
#endif
		// Users can opt into low violence mode on the command-line.
		if ( IsLowViolence_CommandLine() )
		{
			return true;
		}
	}
		
	return false;
}