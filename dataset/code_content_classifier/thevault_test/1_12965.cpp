void ThermalEventCamera::getTemperature(float (&cf)[768])
{
	std::mutex mx;
	std::unique_lock<std::mutex> lck(mx);
	// interpolate outliers
	// uses matrix setup by *_ExtractParameters call in constructor
	MLX90640_InterpolateOutliers(this->frame,this->eeMLX90640);
	// get environmental temperature
	this->eTa = MLX90640_GetTa(this->frame, &this->mlx90640); // Sensor ambient temprature
	//calculate temprature of all pixels, based on current set emissivity
	//updates given array directly
	MLX90640_CalculateTo(this->frame, &this->mlx90640, this->emissivity, this->eTa, cf);
	// free mutex so the thread can keep running
	lck.unlock();
}