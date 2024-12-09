void CSystem::SetClipboardText(const wchar_t *text, int textLen)
{
	char *charStr = (char *)malloc( textLen * 4 );

	Q_UnicodeToUTF8( text, charStr, textLen*4 );

#if defined( USE_SDL )
	SetClipboardText( charStr, Q_strlen( charStr ) );
#elif defined( OSX )
	PasteboardSynchronize( m_PasteBoardRef );
	PasteboardClear( m_PasteBoardRef );

	CFDataRef theData = CFDataCreate( kCFAllocatorDefault, (const UInt8*)charStr, Q_strlen(charStr) );
	PasteboardPutItemFlavor( m_PasteBoardRef, (PasteboardItemID)1, CFSTR("public.utf8-plain-text"), theData, 0 );
	CFRelease( theData );
#endif

	free( charStr );
}