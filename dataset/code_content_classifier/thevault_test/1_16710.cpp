void CImageTool::ZoomY ( DSCC_BYTE *ImgS,  DSCC_BYTE *ImgD, int h, int nh, int wInBytes )
{
        int SourceY, LastSrcY, i, j, k ;
        DSCC_BYTE *ThisLine, *tThisLine, *LastLine, *tImgS ;

        LastSrcY = -1 ;
        for ( i=0 ; i<nh ; i++ )
        {
                ThisLine = ImgD + i*wInBytes ;
                SourceY = (i+1)*(h-1)/nh ;
                if ( SourceY == LastSrcY )
                {
                        LastLine = ImgD + (i-1)*wInBytes ;
                        tThisLine = ThisLine ;
                        for ( j=0 ; j<wInBytes ; j++ )
                                *tThisLine++ = *LastLine++ ;
                }
                else
                {
                        tImgS = ImgS+wInBytes*(LastSrcY+1) ;
                        tThisLine = ThisLine ;
                        for ( j=0 ; j<wInBytes ; j++ )
                                *tThisLine++ = *tImgS++ ;
                        for ( k=LastSrcY+2 ; k<=SourceY ; k++ )
                        {
                                tImgS = ImgS+wInBytes*k ;
                                tThisLine = ThisLine ;
                                for ( j=0 ; j<wInBytes ; j++ )
                                        *tThisLine++ |= *tImgS++ ;
                        }
                }
                LastSrcY = SourceY ;
        }
}