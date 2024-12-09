void ThermalEventCamera::read()
{
	// get frame data
	MLX90640_GetFrameData(MLX_I2C_ADDR,this->frame);
	// check for changes against last frame
	for(int i=0;i<834;++i)
	{
		bool cmp = false;
		// if the compare function is set
		// use it to compare the target pixel from current and pase frame
		if(this->cmpSet)
		{
			cmp = this->compare(this->frame[i],this->last_frame[i]);
		}
		else
		{	// if the compare function has not been set
			// calculate log of frame intensity adding +1 to avoid zero-error
			cmp = 65535*log(this->frame[i]+1)!=65535*log(this->last_frame[i]+1);
		}
		// if the pixels are different according to the comparison fn
		// generate EventData and add to queue
		if(cmp)
		{
			this->events.push(EventData(i,this->frame[i]>this->last_frame[i]? 1 : -1));
		}
	}
	// update last_frame with curent frame
	std::copy(std::begin(this->frame),std::end(this->frame),std::begin(this->last_frame));
}