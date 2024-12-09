double Convert::coefficientOfVariationSample(const std::vector<double>& x) {
	double sd = Convert::standardDeviationSample(x);
	double mean = Convert::mean(x);
	return sd / mean;
}