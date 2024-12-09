inline std::function<double ()> Gaussian_white_noise(unsigned long seed)
	{
		std::shared_ptr<std::mt19937> 
			random(new std::mt19937(seed));
		std::shared_ptr<std::normal_distribution<double>> 
			normal(new std::normal_distribution<double>);

		return [random, normal] () -> double 
			{ return (*normal)(*random); };
	}