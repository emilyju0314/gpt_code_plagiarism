int CSystem::GetClipboardText(int offset, wchar_t *buf, int bufLen)
{
	char *outputUTF8 = (char *)malloc( bufLen*4 );
	int ret = GetClipboardText( offset, outputUTF8, bufLen );
	if ( ret )
		V_UTF8ToUnicode( outputUTF8, buf, bufLen );
	free( outputUTF8 );
	return ret;
}