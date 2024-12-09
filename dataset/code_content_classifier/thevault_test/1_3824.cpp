void V_FixupPathName( char *pOut, int nOutLen, const char *pPath )
{
	V_strncpy( pOut, pPath, nOutLen );
	V_FixSlashes( pOut );
	V_RemoveDotSlashes( pOut );
	V_FixDoubleSlashes( pOut );
	V_strlower( pOut );
}