static void MatProxyCallback( IConVar *pConVar, const char *old, float flOldValue )
{
	ConVarRef var( pConVar );
	int oldVal = (int)flOldValue;
	if ( var.GetInt() == 0 && oldVal != 0 )
	{
		g_MaterialSystem.ReloadMaterials();
	}
}