void copyGrayscaleToRGB(byte *RGBdest, byte *source, int w, int h, int extraWidth)
{
	int x, y;
	byte *ptrs, *ptrd;
	for (y=0; y<h; y++)
	{
	  ptrs = source + y*w;
	  ptrd = RGBdest + y*(w+extraWidth)*3;
	  for (x=0; x<w; x++)
 	  {
		*ptrd = *ptrs;
		*(ptrd+1) = *ptrs;
		*(ptrd+2) = *ptrs;
		ptrd+=3;
		ptrs+=1;
	  }
	
	  for (x=0; x<extraWidth; x++)
	  {
		  *ptrd = 0;
		  *(ptrd+1) = 0;
		  *(ptrd+2) = 0;
		  ptrd+=3;
	  }

	}


}