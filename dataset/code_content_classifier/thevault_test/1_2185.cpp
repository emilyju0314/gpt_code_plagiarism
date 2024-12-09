void MP3FileInfo::ShowAllFrames(void)
{
	assert(m_bOK);

	// all FrameIDs
	ID3_FrameID fids[] = { ID3FID_NOFRAME,          ID3FID_AUDIOCRYPTO,     ID3FID_PICTURE,             ID3FID_AUDIOSEEKPOINT,  ID3FID_COMMENT,
		ID3FID_COMMERCIAL,       ID3FID_CRYPTOREG,       ID3FID_EQUALIZATION2,       ID3FID_EQUALIZATION,    ID3FID_EVENTTIMING,
		ID3FID_GENERALOBJECT,    ID3FID_GROUPINGREG,     ID3FID_INVOLVEDPEOPLE,      ID3FID_LINKEDINFO,      ID3FID_CDID,
		ID3FID_MPEGLOOKUP,       ID3FID_OWNERSHIP,       ID3FID_PRIVATE,             ID3FID_PLAYCOUNTER,     ID3FID_POPULARIMETER,
		ID3FID_POSITIONSYNC,     ID3FID_BUFFERSIZE,      ID3FID_VOLUMEADJ2,          ID3FID_VOLUMEADJ,       ID3FID_REVERB,
		ID3FID_SEEKFRAME,        ID3FID_SIGNATURE,       ID3FID_SYNCEDLYRICS,        ID3FID_SYNCEDTEMPO,     ID3FID_ALBUM,
		ID3FID_BPM,              ID3FID_COMPOSER,        ID3FID_CONTENTTYPE,         ID3FID_COPYRIGHT,       ID3FID_DATE,
		ID3FID_ENCODINGTIME,     ID3FID_PLAYLISTDELAY,   ID3FID_ORIGRELEASETIME,     ID3FID_RECORDINGTIME,   ID3FID_RELEASETIME,
		ID3FID_TAGGINGTIME,      ID3FID_INVOLVEDPEOPLE2, ID3FID_ENCODEDBY,           ID3FID_LYRICIST,        ID3FID_FILETYPE,
		ID3FID_TIME,             ID3FID_CONTENTGROUP,    ID3FID_TITLE,               ID3FID_SUBTITLE,        ID3FID_INITIALKEY,
		ID3FID_LANGUAGE,         ID3FID_SONGLEN,         ID3FID_MUSICIANCREDITLIST,  ID3FID_MEDIATYPE,       ID3FID_MOOD,
		ID3FID_ORIGALBUM,        ID3FID_ORIGFILENAME,    ID3FID_ORIGLYRICIST,        ID3FID_ORIGARTIST,      ID3FID_ORIGYEAR,
		ID3FID_FILEOWNER,        ID3FID_LEADARTIST,      ID3FID_BAND,                ID3FID_CONDUCTOR,       ID3FID_MIXARTIST,
		ID3FID_PARTINSET,        ID3FID_PRODUCEDNOTICE,  ID3FID_PUBLISHER,           ID3FID_TRACKNUM,        ID3FID_RECORDINGDATES,
		ID3FID_NETRADIOSTATION,  ID3FID_NETRADIOOWNER,   ID3FID_SIZE,                ID3FID_ALBUMSORTORDER,  ID3FID_PERFORMERSORTORDER,
		ID3FID_TITLESORTORDER,   ID3FID_ISRC,            ID3FID_ENCODERSETTINGS,     ID3FID_SETSUBTITLE,     ID3FID_USERTEXT,
		ID3FID_YEAR,             ID3FID_UNIQUEFILEID,    ID3FID_TERMSOFUSE,          ID3FID_UNSYNCEDLYRICS,  ID3FID_WWWCOMMERCIALINFO,
		ID3FID_WWWCOPYRIGHT,     ID3FID_WWWAUDIOFILE,    ID3FID_WWWARTIST,           ID3FID_WWWAUDIOSOURCE,  ID3FID_WWWRADIOPAGE,
		ID3FID_WWWPAYMENT,       ID3FID_WWWPUBLISHER,    ID3FID_WWWUSER,             ID3FID_METACRYPTO,      ID3FID_METACOMPRESSION,
		ID3FID_LASTFRAMEID
	};

	// a frame usually contains one field of the following fields:
	ID3_FieldID fiids[] = { ID3FN_NOFIELD, ID3FN_TEXTENC, ID3FN_TEXT, ID3FN_URL, ID3FN_DATA, ID3FN_DESCRIPTION, ID3FN_OWNER, ID3FN_EMAIL, ID3FN_RATING, ID3FN_FILENAME, ID3FN_LANGUAGE, ID3FN_PICTURETYPE, ID3FN_IMAGEFORMAT, ID3FN_MIMETYPE, ID3FN_COUNTER, ID3FN_ID, ID3FN_VOLUMEADJ, ID3FN_NUMBITS, ID3FN_VOLCHGRIGHT, ID3FN_VOLCHGLEFT, ID3FN_PEAKVOLRIGHT, ID3FN_PEAKVOLLEFT, ID3FN_TIMESTAMPFORMAT, ID3FN_CONTENTTYPE, ID3FN_LASTFIELDID};
	char*       idesc[] = { "No field.", "Text encoding (unicode or ASCII).", "Text field.", "A URL.", "Data field.", "Description field.", "Owner field.", "Email field.", "Rating field.", "Filename field.", "Language field.", "Picture type field.", "Image format field.", "Mimetype field.", "Counter field.", "Identifier/Symbol field.", "Volume adjustment field.", "Number of bits field.", "Volume chage on the right channel.", "Volume chage on the left channel.", "Peak volume on the right channel.", "Peak volume on the left channel.", "SYLT Timestamp Format.", "SYLT content type.", "Last field placeholder."};


	int i=0;
	char* buf = 0;
	ID3_Frame* frame = 0;
	ID3_Field* field = 0;
	while(i<96)
	{
		if(i==2 || i==10) // picture and encapsulated object often fail
		{
			printf("%2i. Skipping\n", i);
			i++; continue;
		}

		try { frame = m_id3tag->Find(fids[i]); }
		catch(...)
		{
			printf("ERROR: SKIPPING FILE (i=%i)\n", i);
			Free();
			return;
		}

		if(frame==0) { i++; continue; } // Frame not found
		printf("%2i. %-35s : ", i, frame->GetDescription());

		buf = m_getNewString(fids[i]);
		if(buf)
		{
			printf("\"%s\"\n", buf);
			delete[] buf;
			frame = 0;
			i++; continue;
		}

		printf("No Text found, but:\n", buf);

		for(int k=1; k<24; k++)
		{
			try
			{
				if(frame->Contains(fiids[k]))
				{ printf("%-43s- %s\n", "", idesc[k]); }
			}
			catch(...)
			{
				printf("%-42sERROR: SKIPPING FILE (i=%i; k=%i)\n", "", i, k);
				Free();
				return;
			}
		}
		printf("\n");
		frame = 0;
		i++; continue;
	}
	printf("\n");
}