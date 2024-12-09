void CTexture::GetDownloadFaceCount( int &nFirstFace, int &nFaceCount )
{
	nFaceCount = 1;
	nFirstFace = 0;
	if ( IsCubeMap() )
	{
		nFaceCount = CUBEMAP_FACE_COUNT;
	}
}