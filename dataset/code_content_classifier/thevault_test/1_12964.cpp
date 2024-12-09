void ThermalEventCamera::interpOutliers(uint16_t (&cf)[832])
{
	std::mutex mx;
	std::unique_lock<std::mutex> lck(mx);
	// interpolate outliers
	// uses matrix setup by *_ExtractParameters call in constructor
	MLX90640_InterpolateOutliers(this->frame,this->eeMLX90640);
	// free mutex so the thread can keep running
	lck.unlock();
	// copy matrix to pointer
	std::copy(std::begin(this->eeMLX90640),std::end(this->eeMLX90640),std::begin(cf));
}