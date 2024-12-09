void ThermalEventCamera::printSigns(bool flip)
{	// rows and column of printed image
	int c=32,r=26;
	// if the flip flag is set
	// the rows and cols are switched
	if(flip){
		c = 26;
		r = 32;
	}
	for(int x=0;x<c;++x){
		for(int y=0;y<r;++y){
			// get value of signs matrix
			signed short val = this->out[32*(25-y) + x];
			// print color based on value
			if (val==1){
				std::cout << this->ansi_pos_color;
			}
			else if(val == -1){
				std::cout << this->ansi_neg_color;
			}
			else if(val == 0){
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
	printf("\x1b[33A");
}