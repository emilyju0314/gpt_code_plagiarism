void BlackPixelsInByte()
{
	for(int i=0;i<256;i++)
	{
		lut[i]=0;
		for(int j=0;j<8;j++)
		{
			if((i>>j)&0x01)
				lut[i]++;
		}
	}
}