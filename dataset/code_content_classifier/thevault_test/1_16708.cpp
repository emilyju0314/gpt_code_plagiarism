int CImageTool::GetBound(CImage &Image, DSCC_RECT &rRange)
{
	DSCC_BYTE	mask[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	if(Image.GetType() != DIB_1BIT )
	{
		rRange.left = 0;
		rRange.right = Image.GetWidth()-1;
		rRange.top = 0;
		rRange.bottom = Image.GetHeight()-1;
		return 0;
	}
	int i, j, k, w, wb, h;
	DSCC_BYTE *p = Image.LockRawImg(); 
	w=Image.GetWidth ();
	h=Image.GetHeight ();
	wb=Image.GetLineSizeInBytes ();
	i=0;
	while(i<h)
	{
		for(j=0; j<wb; j++)
			if(*(p+(h-1-i)*wb+j) != 0)	break;
		if(j==wb)	i++;
		else		break;
	}
	rRange.top = i;
	i=h-1;
	while(i>0)
	{
		for(j=0; j<wb; j++)
			if(*(p+(h-1-i)*wb+j) != 0)	break;
		if(j==wb)	i--;
		else		break;
	}
	rRange.bottom = i;

	rRange.left = (wb+1)*8;
	j=0;
	while(j<wb)
	{
		for(i=0; i<h; i++)
		{
			if(*(p+i*wb+j) !=0)	
			{
				for( k=0; k<8; k++ )
				{
					if( *(p+i*wb+j) & mask[k] )
					{
						rRange.left = min( rRange.left, (long)(8*j+k));
						break;
					}
				}
			}
		}
		if(rRange.left != (wb+1)*8)	
			break;
		else
			j++;
	}

	j=wb-1;
	rRange.right = 0;
	while(j>0)
	{
		for(i=0; i<h; i++)
		{
			if(*(p+i*wb+j) != 0)
			{
				for( k=7; k>=0; k-- )
				{
					if( *(p+i*wb+j) & mask[k] )
					{
						rRange.right = max( rRange.right, long(8*j+k));
						break;
					}
				}
			}
		}
		if( rRange.right != 0 )
			break;
		else 
			j--;
	}
	Image.UnlockRawImg ();
	return 0;
}