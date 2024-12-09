void MP3FileInfo::m_parseGenre(void)
{
	if(bHasV2Tag) // Use V2 if present
	{
		szGenre = m_getNewString(ID3FID_CONTENTTYPE);
		return;
	}

	char buf[12];
	if(!m_getString(ID3FID_CONTENTTYPE, buf))
	{
		szGenre = 0;
		return;
	}

	CString temp = "";
	
	try	{ temp = buf; }
	catch(int e) {	}
	
	if(temp.Compare("[Not Found]") != 0)
	{
		int gid;
		sscanf(buf, "(%i)", &gid); // filter Genre ID

		if(gid >= ID3_NR_OF_V1_GENRES) // genre ID too large
		{
			szGenre = new char[strlen(buf)+1];
			sprintf(szGenre, buf);
			return;
		}

		szGenre = new char[strlen(ID3_V1GENRE2DESCRIPTION(gid))+1];
		sprintf(szGenre, ID3_V1GENRE2DESCRIPTION(gid));
	}
	else
		szGenre = 0;
}