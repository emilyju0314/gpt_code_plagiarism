void Host_Error (const char *error, ...)
{
	va_list		argptr;
	char		string[1024];
	static	bool inerror = false;

	if (inerror)
	{
		Sys_Error ("Host_Error: recursively entered");
	}
	inerror = true;

#ifndef DEDICATED
	//	CL_WriteMessageHistory();	TODO must be done by network layer
#endif

	va_start (argptr,error);
	Q_vsnprintf(string,sizeof(string),error,argptr);
	va_end (argptr);

	if ( sv.IsDedicated() )
	{
		// dedicated servers just exit
		Sys_Error( "Host_Error: %s\n", string );
		return;
	}

#ifndef DEDICATED
	// Reenable screen updates
	SCR_EndLoadingPlaque ();		
#endif
	ConMsg( "\nHost_Error: %s\n\n", string );

	Host_Disconnect(true);

#ifndef DEDICATED
	GetBaseLocalClient().demonum = -1;
#endif

	inerror = false;

	if ( g_bAbortServerSet )
	{
		longjmp (host_abortserver, 1);
	}
}