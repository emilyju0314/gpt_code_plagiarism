int CImageTool::CopyImage ( CImage &ImgS, int xs, int ys, CImage &ImgD, int xd, int yd, int w, int h)
{
    int wInBytesS = ImgS.GetLineSizeInBytes() ;
    int hs = ImgS.GetHeight() ;
    DSCC_BYTE *ps = ImgS.LockRawImg() ;
	int bUpSideDown = ImgS.GetOrientation();

    int wInBytesD = ImgD.GetLineSizeInBytes() ;
    int hd = ImgD.GetHeight() ;
    DSCC_BYTE *pd = ImgD.LockRawImg() ;
	if( bUpSideDown )
		CopyBlock ( ps, xs, hs-ys-h, wInBytesS, pd, xd, hd-yd-h, wInBytesD, w, h, ImgS.GetType(), bUpSideDown) ;
	else
		CopyBlock ( ps, xs, ys, wInBytesS, pd, xd, hd-yd-h, wInBytesD, w, h, ImgS.GetType(), bUpSideDown) ;
    ImgD.UnlockRawImg() ;
    ImgS.UnlockRawImg() ;
    return 0 ;
}