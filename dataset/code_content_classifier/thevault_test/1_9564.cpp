double Convert::coefficientOfVariationPopulation(const std::vector<double>& x) {
	double sd = Convert::standardDeviation(x);
	double mean = Convert::mean(x);
	return sd / mean;
}