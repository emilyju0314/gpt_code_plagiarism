void ThermalEventCamera::printSignsRaw(bool flip)
{	// rows and column of printed image
	int c=32,r=26;
	// if the flip flag is set
	// the rows and cols are switched
	if(flip){
		c = 26;
		r = 32;
	}
	for(int x=0;x<c;++x)
	{
		for(int y=0;y<r;++y)
		{
			std::cout << this->out[32*(25-y)+x];
		}
		std::cout << std::endl;
	}
	printf("\x1b[33A");
}