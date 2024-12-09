int CImageTool::CopyBlock ( DSCC_BYTE *ps, int xs, int ys, int wInBytesS, DSCC_BYTE *pd, int xd, int yd, int wInBytesD, int w, int h, int Type, int bUpSideDown)
{
	DSCC_BYTE *tps, *tpd;
	if(Type == DIB_1BIT)
	{
		DSCC_BYTE mask[8] = {1,2,4,8,16,32,64,128} ;
		for ( int i=0 ; i<h ; i++ )
		{
			tps=ps+(ys+i)*wInBytesS+(xs>>3) ;
			if( bUpSideDown )
				tpd=pd+(yd+i)*wInBytesD+(xd>>3) ;
			else
				tpd=pd+(h-1-yd-i)*wInBytesD+(xd>>3);
			int rs = 7-(xs%8) ;
			int rd = 7-(xd%8) ;
			for ( int j=0 ; j<w ; j++ )
			{
				if ( mask[rs] & (*tps) )
					*tpd = (*tpd) | mask[rd] ;
				if ( --rs < 0 ) { rs = 7 ; tps++ ; }
				if ( --rd < 0 ) { rd = 7 ; tpd++ ; }
			}
		}
		return 0;
	}
	else if(Type == DIB_8BIT)
	{
		for ( int i=0; i<h; i++)
		{
			tps = ps+(ys+i)*wInBytesS+xs;
			if( bUpSideDown )
				tpd = pd+(h-1-yd-i)*wInBytesD+xd;
			else
				tpd = pd+(yd+i)*wInBytesD+xd;
			for ( int j=0; j<w; j++)
			{
				*tpd = *tps;	
				tpd++;		tps++;
			}
		}
		return 0;
	}
	else if(Type == DIB_24BIT)
	{
		for ( int i=0; i<h; i++)
		{
			tps = ps+(ys+i)*wInBytesS+3*xs;
			if( bUpSideDown )
				tpd = pd+(h-1-yd-i)*wInBytesD+3*xd;
			else
				tpd = pd+(yd+i)*wInBytesD+3*xd;
			for ( int j=0; j<3*w; j++)
			{
				*tpd = *tps;
				tpd++;
				tps++;
			}
		}
	}
    return -1 ;
}