const char *V_GetFileExtensionSafe( const char *path )
{
	const char *pExt = V_GetFileExtension( path );
	if ( pExt == NULL )
		return "";
	else
		return pExt;
}