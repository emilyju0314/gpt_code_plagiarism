void MP3FileInfo::Free(void)
{
	if(m_bOK) // only free if OK
	{
		m_bOK = false;

		if(m_id3tag!=0)
		{
			// in rare cases (e.g. if file is corrupt)
			// "delete m_id3tag" fails ...
			try { delete m_id3tag; } catch(...) {}
			m_id3tag = 0;
		}

		/* fileinfo */
		delete[] szFilename; szFilename = 0; nFileSize = -1;
		bHasLyrics = false; bHasV1Tag = false; bHasV2Tag = false;

		/* headerinfo */
		m_mp3header = 0;
		nVbrBitRate = 0; nBitRate = 0; nCbrBitRate = 0;
		nSampleRate = 0; nLength  = 0;
		delete[] szBitRate;     szBitRate = 0;
		delete[] szMpegLayer;   szMpegLayer = 0;
		delete[] szMpegVersion; szMpegVersion = 0;
		delete[] szChannelMode; szChannelMode = 0;

		/* ID3V1 Tag elements */
		nTrack = 0; nYear = 0;
		delete[] szArtist;  szArtist  = 0;
		delete[] szTitle;   szTitle   = 0;
		delete[] szAlbum;   szAlbum   = 0;
		delete[] szComment; szComment = 0;
		delete[] szTrack;   szTrack   = 0;
		delete[] szYear;    szYear    = 0;
		delete[] szGenre;   szGenre   = 0;

		/* V2 up */
		delete[] szComposer;        szComposer= 0;
		delete[] szCopyright;       szCopyright= 0;
		delete[] szEncodedBy;       szEncodedBy= 0;
		delete[] szOriginalArtist;  szOriginalArtist= 0;
		delete[] szURL;             szURL= 0;
	}
}