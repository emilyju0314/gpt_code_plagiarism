bool V_PathsMatch( const char *pPath1, const char *pPath2)
{
	char pPath1Fixed[MAX_PATH];
	V_strcpy_safe( pPath1Fixed, pPath1 );
	char pPath2Fixed[MAX_PATH];
	V_strcpy_safe( pPath2Fixed, pPath2 );
	V_FixSlashes( pPath1Fixed, '/' );
	V_FixSlashes( pPath2Fixed, '/' );

	return ( V_stricmp( pPath1Fixed, pPath2Fixed ) == 0 );
}