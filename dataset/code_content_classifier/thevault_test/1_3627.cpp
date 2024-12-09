bool IsLowViolence_CommandLine()
{
#if defined( _LOWVIOLENCE )
	// a low violence build can not be-undone
	return true;
#endif

	return ( CommandLine()->FindParm( "-lv" ) != 0 );
}