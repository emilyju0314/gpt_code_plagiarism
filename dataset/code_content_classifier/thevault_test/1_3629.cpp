bool Host_AllowQueuedMaterialSystem( bool bAllow )
{
#if !defined( DEDICATED )
	g_bAllowThreadedSound = bAllow;
	// NOTE: Moved this to materialsystem for integrating with other mqm changes
	return g_pMaterialSystem->AllowThreading( bAllow, g_nMaterialSystemThread );
#endif
	//lwss fix- THIS DID NOT RETURN A VALUE ON DEDICATED BUILDS, MESSING UP THE STACK AND CAUSING ME MUCH GRIEF!
	return false;
}