bool MP3FileInfo::Init(const char* cszFilename)
{
	Free();
	m_bOK = true;

	// copy filename
	szFilename = new char[strlen(cszFilename)+1];
	sprintf(szFilename, cszFilename);

	m_id3tag = new ID3_Tag;
	m_id3tag->Link(szFilename);

	if(m_id3tag == NULL) { return m_bOK; }

	/* Fileinfo */
	bHasLyrics = m_id3tag->HasLyrics();
	bHasV1Tag  = m_id3tag->HasV1Tag();
	bHasV2Tag  = m_id3tag->HasV2Tag();
	nFileSize  = (int)m_id3tag->GetFileSize();

	/* Headerinfo */
	m_parseHeader();
	if(!m_bOK) { Free(); return m_bOK; }

	/* V1 up */
	szAlbum   = m_getNewString(ID3FID_ALBUM);
	szArtist  = m_getNewString(ID3FID_LEADARTIST);
	szComment = m_getNewString(ID3FID_COMMENT);
	szTitle   = m_getNewString(ID3FID_TITLE);
	szTrack   = m_getNewString(ID3FID_TRACKNUM);
	szYear    = m_getNewString(ID3FID_YEAR);

	/* V2 */
	szComposer        = m_getNewString(ID3FID_COMPOSER);
	szCopyright       = m_getNewString(ID3FID_COPYRIGHT);
	szEncodedBy       = m_getNewString(ID3FID_ENCODEDBY);
	szOriginalArtist  = m_getNewString(ID3FID_ORIGARTIST);
	szURL             = m_getNewString(ID3FID_WWWUSER);

	m_parseGenre();
	if(szYear)  sscanf(szYear,  "%i", &nYear);
	if(szTrack) sscanf(szTrack, "%i", &nTrack);

	return m_bOK;
}